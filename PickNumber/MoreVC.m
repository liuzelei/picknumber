//
//  MoreVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "MoreVC.h"
#import "PN_Params.h"
#import "PN.h"
#import "AboutVC.h"


@interface MoreVC ()
{
    NSString *url;
}
@end

@implementation MoreVC

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
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row==0) {
        PNSoapBinding *pn = [PN PNSoapBinding];
        PN_GetUpdateInfo *params = [PN_Params get_update_info_params];
        [pn GetUpdateInfoAsyncUsingParameters:params delegate:self];
    }
    else if(indexPath.row==1)
    {
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        AboutVC *avc=[storyboard instantiateViewControllerWithIdentifier:@"AboutVC"];
        [self.navigationController pushViewController:avc animated:YES];
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
        
        if([bodyPart isKindOfClass:[PN_GetUpdateInfoResponse class]]) {
            PN_GetUpdateInfoResponse *body = (PN_GetUpdateInfoResponse*)bodyPart;
            if ([body.GetUpdateInfoResult.Result integerValue] == 0) {
                self->url = body.GetUpdateInfoResult.URL;
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"您的当前版本过低,必须升级.请点击确认升级."] delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                [alert_view show];
            }
            else
            {
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"您当前已经是最新版本"] delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                [alert_view show];
            }
        }
    }
}


- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:self->url]];
}

@end
