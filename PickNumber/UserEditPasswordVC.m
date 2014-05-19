//
//  UserEditPasswordVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "UserEditPasswordVC.h"
#import "PN.h"
#import "PN_Params.h"
#import "UIAlertView+PN.h"
@interface UserEditPasswordVC ()

@end

@implementation UserEditPasswordVC

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
    self.title = @"修改密码";
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

- (IBAction)btn_update_password:(id)sender {
    if (([self.txt_old_password.text isEqualToString:@""] || [self.txt_new_password.text isEqualToString:@""])
        || ![self.txt_new_password.text isEqualToString:self.txt_confirm_new_password.text]) {
        UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"请填写完整信息,并确认填写密码一致"] delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert_view show];
    }
    else{
        PNSoapBinding *pn = [PN PNSoapBinding];
        PN_ChangePassword *params = [PN_Params get_pn_change_password_params:self.txt_old_password.text new_password:self.txt_new_password.text];
        [pn ChangePasswordAsyncUsingParameters:params delegate:self];
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
        
        if([bodyPart isKindOfClass:[PN_ChangePasswordResponse class]]) {
            PN_ChangePasswordResponse *body = (PN_ChangePasswordResponse*)bodyPart;
            if ([body.ChangePasswordResult.Result integerValue] == 0) {
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"密码修改成功"] delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                [alert_view show];
            }
            else
            {
                [UIAlertView show_msg:body.ChangePasswordResult.ErrorDescription];
            }
        }
    }
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [self.navigationController popViewControllerAnimated:YES];
}
@end
