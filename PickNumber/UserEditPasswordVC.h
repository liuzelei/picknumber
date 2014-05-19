//
//  UserEditPasswordVC.h
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PN.h"

@interface UserEditPasswordVC : UITableViewController<PNSoapBindingResponseDelegate,UIAlertViewDelegate>
@property (strong, nonatomic) IBOutlet UITextField *txt_old_password;
@property (strong, nonatomic) IBOutlet UITextField *txt_new_password;
@property (strong, nonatomic) IBOutlet UITextField *txt_confirm_new_password;

@end
