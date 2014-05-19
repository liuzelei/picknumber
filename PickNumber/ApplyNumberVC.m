//
//  ApplyNumberVC.m
//  PickNumber
//
//  Created by bruce on 14-5-12.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "ApplyNumberVC.h"
#import "NumberFilterVC.h"
#import "NumberQueryResultVC.h"
#import "User.h"
#import "PN.h"
#import "AppConstants.h"
#import "PN_Params.h"
#import "ItemData.h"
#import "XmlParser.h"
@interface ApplyNumberVC ()
{
    CLabel *lbl_current;
    NSMutableArray *datas;
    NSString *current_element;
}
@end

@implementation ApplyNumberVC

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
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    [self set_default];
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)set_default
{
    ItemData *data_header = [[ItemData alloc]init];
    data_header.ikey = @"189";
    data_header.ivalue = @"189";
    self.lbl_number_header.model = data_header;
    self.lbl_number_header.text = data_header.ikey;
    
    ItemData *data_level = [[ItemData alloc]init];
    data_level.ikey = @"所有";
    data_level.ivalue = @"-1";
    self.lbl_number_level.model = data_level;
    self.lbl_number_level.text = data_level.ikey;
    
    ItemData *data_feature = [[ItemData alloc]init];
    data_feature.ikey = @"所有";
    data_feature.ivalue = @"";
    self.lbl_number_feature.model = data_feature;
    self.lbl_number_feature.text = data_feature.ikey;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row==0 || indexPath.row==1 || indexPath.row==2) {
        PNSoapBinding *pn = [PN PNSoapBinding];
        switch (indexPath.row) {
            case 0:
            {
                PN_ItemQueryList *params = [PN_Params get_item_query_list_params:@"2"];
                [pn ItemQueryListAsyncUsingParameters:params delegate:self];
                lbl_current = self.lbl_number_header;
                break;
            }
            case 1:
            {
                PN_LevelQueryList *params = [PN_Params get_pn_level_query_list:((ItemData *)self.lbl_number_header.model).ivalue];
                [pn LevelQueryListAsyncUsingParameters:params delegate:self];
                lbl_current = self.lbl_number_level;
                break;
            }
            case 2:
            {
                PN_FeatureQueryList *params = [PN_Params get_pn_feature_query_list:((ItemData *)self.lbl_number_level.model).ivalue];
                [pn FeatureQueryListAsyncUsingParameters:params delegate:self];
                lbl_current = self.lbl_number_feature;
                break;
            }
            default:
                break;
        }
    }
}

-(void)setLabel:(ItemData *)item_data
{
    lbl_current.text = item_data.ikey;
    lbl_current.model = item_data;
}

- (IBAction)btn_query:(id)sender {
    [self.txt_include_num resignFirstResponder];
    PNSoapBinding *pn = [PN PNSoapBinding];
    PN_TelQueryList *pn_tel_query_list_params = [PN_Params get_pn_tel_query_list_params:((ItemData *)self.lbl_number_header.model).ivalue level:((ItemData *)self.lbl_number_level.model).ivalue feature:((ItemData *)self.lbl_number_feature.model).ivalue include_num:self.txt_include_num.text exclude_num:self.swh_number_uncontains_four.isOn is_area:self.swh_number_contains_code.isOn];
    [pn TelQueryListAsyncUsingParameters:pn_tel_query_list_params delegate:self];
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
        
        if([bodyPart isKindOfClass:[PN_TelQueryListResponse class]]) {
            PN_TelQueryListResponse *body = (PN_TelQueryListResponse*)bodyPart;
            if ([body.TelQueryListResult.Result integerValue] == 0) {
                datas = [XmlParser load_tels:body.TelQueryListResult.List];
                NumberQueryResultVC * nqrvc = [[NumberQueryResultVC alloc] initWithNibName:nil bundle:nil];
                nqrvc.tels = datas;
                [self.navigationController pushViewController:nqrvc animated:YES];
            }
            else
            {
                NSLog(@"%@",body.TelQueryListResult.ErrorDescription);
            }
        }
        else if([bodyPart isKindOfClass:[PN_ItemQueryListResponse class]])
        {
            PN_ItemQueryListResponse *body = (PN_ItemQueryListResponse*)bodyPart;
            
            if ([body.ItemQueryListResult.Result integerValue] == 0) {
                datas = [XmlParser load_item_datas:body.ItemQueryListResult.List];
                [self push_number_filterVC:datas];
            }
            else
            {
                NSLog(@"%@",body.ItemQueryListResult.ErrorDescription);
            }
        }
        else if([bodyPart isKindOfClass:[PN_LevelQueryListResponse class]])
        {
            PN_LevelQueryListResponse *body = (PN_LevelQueryListResponse*)bodyPart;
            
            if ([body.LevelQueryListResult.Result integerValue] == 0) {
                NSLog(@"%@",body.LevelQueryListResult.List);
                datas = [XmlParser load_item_datas:body.LevelQueryListResult.List];
                [self push_number_filterVC:datas];
            }
            else
            {
                NSLog(@"%@",body.LevelQueryListResult.ErrorDescription);
            }
        }
        else if([bodyPart isKindOfClass:[PN_FeatureQueryListResponse class]])
        {
            PN_FeatureQueryListResponse *body = (PN_FeatureQueryListResponse*)bodyPart;
            if ([body.FeatureQueryListResult.Result integerValue] == 0) {
                NSLog(@"%@",body.FeatureQueryListResult.List);
                datas = [XmlParser load_item_datas:body.FeatureQueryListResult.List];
                [self push_number_filterVC:datas];
            }
            else
            {
                NSLog(@"%@",body.FeatureQueryListResult.ErrorDescription);
            }
        }
        // ...
    }
}

-(void)push_number_filterVC:(NSMutableArray *)item_datas
{
    NumberFilterVC *nfv = [[NumberFilterVC alloc] initWithNibName:nil bundle:nil];
    nfv.datas = item_datas;
    [nfv setDissMissDelegate:self];
    [self.navigationController pushViewController:nfv animated:YES];
}
@end
