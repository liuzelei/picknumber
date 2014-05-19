//
//  LoginVC.h
//  PickNumber
//
//  Created by bruce on 14-5-12.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PN.h"

@interface LoginVC : UIViewController<PNSoapBindingResponseDelegate>


@property (strong, nonatomic) IBOutlet UISwitch *swh_remember_me;
@property (strong, nonatomic) IBOutlet UITextField *txt_phone;
@property (strong, nonatomic) IBOutlet UITextField *txt_pwd;
@end
