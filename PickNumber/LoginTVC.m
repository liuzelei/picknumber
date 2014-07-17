//
//  LoginTVC.m
//  PickNumber
//
//  Created by bruce on 14-5-19.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "LoginTVC.h"
#import "PN.h"
#import "User.h"
#import "PN_Params.h"
#import "UIAlertView+PN.h"
#import "XmlParser.h"
@interface LoginTVC ()
{
    NSString *url;
}
@end

@implementation LoginTVC

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
    
    [self.swh_remember_me setOn:[User current_user].is_remember];
    if ([User current_user].is_remember)
    {
        self.txt_phone.text = [User current_user].phone;
    }
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
//- (IBAction)btn_checkbox:(id)sender {
//    UIButton * checkbox = (UIButton *)sender;
//    if(checkbox.tag == 0){
//        [checkbox setSelected:YES];
//        checkbox.tag = 1;
//    }
//    else {
//        [checkbox setSelected:NO];
//        checkbox.tag = 0;
//    }
//}

- (IBAction)btn_login:(id)sender {
    PNSoapBinding *pn = [PN PNSoapBinding];
    PN_Login *pn_login_params = [PN_Params get_pn_login_params:self.txt_phone.text msg_code:self.txt_pwd.text password:@""];
    [pn LoginAsyncUsingParameters:pn_login_params delegate:self];
}
- (IBAction)btn_msg:(id)sender {
    PNSoapBinding *pn = [PN PNSoapBinding];
    PN_GetMsgCode *params = [PN_Params get_pn_get_msg_code:self.txt_phone.text];
    [pn GetMsgCodeAsyncUsingParameters:params delegate:self];
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
        
        if([bodyPart isKindOfClass:[PN_LoginResponse class]]) {
            PN_LoginResponse *body = (PN_LoginResponse*)bodyPart;
            
            if ([body.LoginResult.Result integerValue] == 0) {
                
                [self remember_me:self.txt_phone.text name:body.LoginResult.UserName token:body.LoginResult.UserToken is_remember:self.swh_remember_me.isOn];
                
                UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
                UITabBarController *obj=[storyboard instantiateViewControllerWithIdentifier:@"tab"];
                self.navigationController.navigationBarHidden=YES;
                [self.navigationController pushViewController:obj animated:YES];
            }
            else if([body.LoginResult.Result integerValue] == -10)
            {
                self->url = body.LoginResult.ErrorDescription;
                UIAlertView *alert_view = [[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:@"您的当前版本过低,必须升级.请点击确认升级."] delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                [alert_view show];
            }
            else
            {
                [UIAlertView show_msg:body.LoginResult.ErrorDescription];
            }
        }
        else if([bodyPart isKindOfClass:[PN_GetMsgCodeResponse class]])
        {
            PN_GetMsgCodeResponse *body = (PN_GetMsgCodeResponse*)bodyPart;
            
            if ([body.GetMsgCodeResult.Result integerValue] == 0) {
                [UIAlertView show_msg:@"信息发送成功,请接收短信"];
            }
            else
            {
                [UIAlertView show_msg:body.GetMsgCodeResult.ErrorDescription];
            }
        }
        // ...
    }
}

-(void)remember_me:(NSString *)phone name:(NSString *)name token:(NSString *)token is_remember:(BOOL)is_remember
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    NSDictionary *userDict =  [userDefaults objectForKey:@"user"];
    userDict = [[NSMutableDictionary alloc] initWithDictionary:userDict];
    [userDict setValue:phone forKey:@"phone"];
    [userDict setValue:name forKey:@"name"];
    [userDict setValue:token forKey:@"token"];
    [userDict setValue:[NSNumber numberWithBool:is_remember] forKey:@"is_remember"];
    [userDefaults setObject:userDict forKey:@"user"];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:self->url]];
}
@end
