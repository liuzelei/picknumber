//
//  UserProfileTVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "UserProfileTVC.h"

@interface UserProfileTVC ()

@end

@implementation UserProfileTVC

@synthesize user;

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
    self.title=@"个人信息";
    [self setup];
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)setup
{
    self.lbl_account.text = user.phone;
    self.lbl_tel.text = user.tel;
    self.lbl_no.text = user.no;
    self.lbl_area.text = user.area;
    self.lbl_name.text = user.name;
    self.lbl_department.text = user.department;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
