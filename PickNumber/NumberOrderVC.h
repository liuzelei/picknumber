//
//  NumberOrderVC.h
//  PickNumber
//
//  Created by bruce on 14-5-13.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CLabel.h"
#import "PN.h"
#import "NumberFilterVC.h"
#import "Tel.h"
@interface NumberOrderVC : UITableViewController <PNSoapBindingResponseDelegate,DissMissDelegate,UIAlertViewDelegate>
{
    Tel *tel;
}
@property (nonatomic,strong) Tel *tel;
@property (strong, nonatomic) IBOutlet CLabel *lbl_packet;
@property (strong, nonatomic) IBOutlet UITextField *txt_id_card;
@property (strong, nonatomic) IBOutlet UITextField *txt_company_name;

@property (strong, nonatomic) IBOutlet UITextField *txt_custom_name;

@end
