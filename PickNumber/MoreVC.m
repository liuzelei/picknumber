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
        PN_GetUserInfo *params = [PN_Params get_user_info_params];
        [pn GetUserInfoAsyncUsingParameters:params delegate:self];
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
        if([bodyPart isKindOfClass:[PN_GetUserInfoResponse class]]) {
            PN_GetUserInfoResponse *body = (PN_GetUserInfoResponse*)bodyPart;
            if ([body.GetUserInfoResult.Result integerValue] == 0) {
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"您的版本过低,请到AppStore升级"] delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
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



@end
