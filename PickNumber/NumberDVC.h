//
//  NumberDVC.h
//  PickNumber
//
//  Created by bruce on 14-5-13.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Tel.h"
@interface NumberDVC : UIViewController
{
    Tel *tel;
}
@property(nonatomic,retain) Tel *tel;
@property (strong, nonatomic) IBOutlet UILabel *lbl_tel;
@property (strong, nonatomic) IBOutlet UILabel *lbl_level;
@property (strong, nonatomic) IBOutlet UILabel *lbl_min_fee;
@property (strong, nonatomic) IBOutlet UILabel *lbl_input_area;
@property (strong, nonatomic) IBOutlet UILabel *lbl_status;
@property (strong, nonatomic) IBOutlet UILabel *lbl_feature;
@property (strong, nonatomic) IBOutlet UILabel *lbl_pre_deposit;
@property (strong, nonatomic) IBOutlet UILabel *lbl_star_num;
@property (strong, nonatomic) IBOutlet UILabel *lbl_group_num;
@property (strong, nonatomic) IBOutlet UILabel *lbl_month_num;
@property (strong, nonatomic) IBOutlet UILabel *lbl_note;


@end
