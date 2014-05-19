//
//  ApplyNumberVC.h
//  PickNumber
//
//  Created by bruce on 14-5-12.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NumberFilterVC.h"
#import "CLabel.h"
#import "PN.h"
@interface ApplyNumberVC : UITableViewController <DissMissDelegate,PNSoapBindingResponseDelegate>
@property (strong, nonatomic) IBOutlet CLabel *lbl_number_header;
@property (strong, nonatomic) IBOutlet CLabel *lbl_number_level;
@property (strong, nonatomic) IBOutlet CLabel *lbl_number_feature;
@property (strong, nonatomic) IBOutlet UISwitch *swh_number_uncontains_four;
@property (strong, nonatomic) IBOutlet UISwitch *swh_number_contains_code;
@property (strong, nonatomic) IBOutlet UITextField *txt_include_num;


@end
