//
//  NumberOrderVC.m
//  PickNumber
//
//  Created by bruce on 14-5-13.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "NumberOrderVC.h"
#import "ItemData.h"
#import "PN.h"
#import "XmlParser.h"
#import "PN_Params.h"
#import "NumberFilterVC.h"
#import "UIAlertView+PN.h"
@interface NumberOrderVC ()
{
    NSMutableArray *datas;
}
@end

@implementation NumberOrderVC

@synthesize tel;
- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"申请";
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}



- (IBAction)btn_apply:(id)sender {
        PNSoapBinding *pn = [PN PNSoapBinding];
        PN_ItemQueryList *params = [PN_Params get_item_query_list_params:@"1"];
        [pn ItemQueryListAsyncUsingParameters:params delegate:self];
//        PN_TELRequest *params = [PN_Params get_pn_tel_request_params:tel.tel id_card:self.txt_id_card.text company_name:self.txt_company_name.text custom_name:self.txt_custom_name.text pack_et:((ItemData *)self.lbl_packet.model).ivalue note:@""];
//        [pn TELRequestAsyncUsingParameters:params delegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    CGFloat height = self.tableView.rowHeight;
    
    return height;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row==0 ) {
        PNSoapBinding *pn = [PN PNSoapBinding];
        switch (indexPath.row) {
            case 0:
            {
                PN_ItemQueryList *params = [PN_Params get_item_query_list_params:@"1"];
                [pn ItemQueryListAsyncUsingParameters:params delegate:self];
                break;
            }
            default:
                break;
        }
    }
}

- (void) operation:(PNSoapBindingOperation *)operation completedWithResponse:(PNSoapBindingResponse *)response
{
    NSArray *responseBodyParts = response.bodyParts;
    
    for(id bodyPart in responseBodyParts) {
        if ([bodyPart isKindOfClass:[SOAPFault class]]) {
            // You can get the error like this:
            NSLog(@"%@,%@",[bodyPart faultcode],[bodyPart faultstring]);
            continue;
        }
        
  
        if([bodyPart isKindOfClass:[PN_ItemQueryListResponse class]])
        {
            PN_ItemQueryListResponse *body = (PN_ItemQueryListResponse*)bodyPart;
            
            if ([body.ItemQueryListResult.Result integerValue] == 0) {
                datas = [XmlParser load_item_datas:body.ItemQueryListResult.List];
                NSArray *array = [datas sortedArrayUsingComparator:[self get_comparator]];
                PNSoapBinding *pn = [PN PNSoapBinding];
                PN_TELRequest *params = [PN_Params get_pn_tel_request_params:tel.tel id_card:self.txt_id_card.text company_name:self.txt_company_name.text custom_name:self.txt_custom_name.text pack_et:((ItemData *)[array objectAtIndex:0]).ivalue note:@""];
                [pn TELRequestAsyncUsingParameters:params delegate:self];
            }
            else
            {
                NSLog(@"%@",body.ItemQueryListResult.ErrorDescription);
            }
        }
        else if([bodyPart isKindOfClass:[PN_TELRequestResponse class]])
        {
            PN_TELRequestResponse *body = (PN_TELRequestResponse*)bodyPart;
            
            if ([body.TELRequestResult.Result integerValue] == 0) {
                
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"号码申请成功，请在CRM建单后打电话给集中业务处理中心处理,申请单号为:%@",body.TELRequestResult.RNO] delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                [alert_view show];
            }
            else
            {
                [UIAlertView show_msg:body.TELRequestResult.ErrorDescription];
            }
        }
        // ...
    }
}

-(void)setLabel:(ItemData *)item_data
{
    self.lbl_packet.text = item_data.ikey;
    self.lbl_packet.model = item_data;
}

-(void)push_number_filterVC:(NSMutableArray *)item_datas
{
    NumberFilterVC *nfv = [[NumberFilterVC alloc] initWithNibName:nil bundle:nil];
    nfv.datas = item_datas;
    [nfv setDissMissDelegate:self];
    [self.navigationController pushViewController:nfv animated:YES];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    id object = nil;
    
    for (UIViewController *viewControl in self.navigationController.viewControllers)
    {
        if(viewControl.view.tag == 11)
        {
            object = viewControl;
            break;
        }
    }
    [self.navigationController popToViewController:object animated:YES];
}

-(NSComparator )get_comparator
{
    NSComparator cmptr = ^(ItemData *obj1,ItemData *obj2) {
        
        if ([obj1.ivalue integerValue] > [obj2.ivalue integerValue]) {
            
            return (NSComparisonResult)NSOrderedDescending;
        }
        if ([obj1.ivalue integerValue] < [obj2.ivalue integerValue]) {
            return (NSComparisonResult)NSOrderedAscending;
        }
        return (NSComparisonResult)NSOrderedSame;
        
    };
    
    return cmptr;
}
@end
