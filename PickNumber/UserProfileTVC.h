//
//  UserProfileTVC.h
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CLabel.h"
#import "User.h"
@interface UserProfileTVC : UITableViewController
{
    User *user;
}
@property (strong, nonatomic) User *user;
@property (strong, nonatomic) IBOutlet CLabel *lbl_name;

@property (strong, nonatomic) IBOutlet CLabel *lbl_account;
@property (strong, nonatomic) IBOutlet CLabel *lbl_tel;
@property (strong, nonatomic) IBOutlet CLabel *lbl_department;
@property (strong, nonatomic) IBOutlet CLabel *lbl_area;
@property (strong, nonatomic) IBOutlet CLabel *lbl_no;

@end
