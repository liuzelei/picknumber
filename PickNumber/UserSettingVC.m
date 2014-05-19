//
//  UserSettingVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "UserSettingVC.h"
#import "PN.h"
#import "PN_Params.h"
#import "User.h"
#import "UserEditPasswordVC.h"
#import "UserProfileTVC.h"
#import "UIAlertView+PN.h"
@interface UserSettingVC ()
{
}
@end

@implementation UserSettingVC

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
        UserEditPasswordVC *uepvc=[storyboard instantiateViewControllerWithIdentifier:@"UserEditPasswordVC"];
        [self.navigationController pushViewController:uepvc animated:YES];
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
        
        if([bodyPart isKindOfClass:[PN_GetUserInfoResponse class]]) {
            PN_GetUserInfoResponse *body = (PN_GetUserInfoResponse*)bodyPart;
            if ([body.GetUserInfoResult.Result integerValue] == 0) {
                User *user = [[User alloc] init];
                user.name = body.GetUserInfoResult.Name;
                user.no = body.GetUserInfoResult.WorkNo;
                user.tel = body.GetUserInfoResult.TEL;
                user.phone = body.GetUserInfoResult.LoginName;
                user.department = body.GetUserInfoResult.CompanyName;
                user.area = body.GetUserInfoResult.AreaName;
                
                UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                UserProfileTVC *upvc=[storyboard instantiateViewControllerWithIdentifier:@"UserProfileTVC"];
                upvc.user = user;
                [self.navigationController pushViewController:upvc animated:YES];
            }
            else
            {
                [UIAlertView show_msg:body.GetUserInfoResult.ErrorDescription];
            }
        }
    }
}


@end
