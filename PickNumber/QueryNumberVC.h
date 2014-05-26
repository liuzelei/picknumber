//
//  QueryNumberVC.h
//  PickNumber
//
//  Created by bruce on 14-5-17.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CLabel.h"
#import "PN.h"

@interface QueryNumberVC : UITableViewController <PNSoapBindingResponseDelegate>
{
    BOOL   datePickerIsShowing_start;
    BOOL   datePickerIsShowing_end;
    UIDatePicker *date_picker_start;
    UIDatePicker *date_picker_end;
}
@property (nonatomic,assign) BOOL datePickerIsShowing_start;
@property (nonatomic,assign) BOOL datePickerIsShowing_end;

@property (strong, nonatomic)  UIDatePicker *date_picker_start;
@property (strong, nonatomic)  UIDatePicker *date_picker_end;
@property (strong, nonatomic) IBOutlet CLabel *lbl_start_date;
@property (strong, nonatomic) IBOutlet CLabel *lbl_end_date;

@property (strong, nonatomic) IBOutlet UITextField *txt_phone;
@property (strong, nonatomic) IBOutlet UITextField *txt_no;
@property (strong, nonatomic) IBOutlet UITableViewCell *start_cell;
@property (strong, nonatomic) IBOutlet UITableViewCell *end_cell;

@end
