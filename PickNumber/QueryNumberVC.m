//
//  QueryNumberVC.m
//  PickNumber
//
//  Created by bruce on 14-5-17.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "QueryNumberVC.h"
#import "PN.h"
#import "XmlParser.h"
#import "Order.h"
#import "PN_Params.h"
#import "OrderListVC.h"
#import "UIAlertView+PN.h"
@interface QueryNumberVC ()
{
    NSDateFormatter *dateFormatter;
     NSMutableArray *datas;
}
@end

@implementation QueryNumberVC

@synthesize datePickerIsShowing_start,datePickerIsShowing_end;
- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)setup {
    
    dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    
    NSTimeInterval secondsPerDay = 24 * 60 * 60;
    NSDate *start_date = [[NSDate alloc] initWithTimeIntervalSinceNow:-secondsPerDay*2];
    NSDate *end_date = [[NSDate alloc] initWithTimeIntervalSinceNow:secondsPerDay];
    self.lbl_start_date.text = [dateFormatter stringFromDate:start_date];
    self.lbl_end_date.text = [dateFormatter stringFromDate:end_date];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setup];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    CGFloat height = self.tableView.rowHeight;
    
    if (indexPath.row == 1){
        height = self.datePickerIsShowing_start ? 162 : 0.0f;
    }
    else if(indexPath.row == 3)
    {
        height = self.datePickerIsShowing_end ? 162 : 0.0f;
    }
    return height;
}


-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0){
        if (self.datePickerIsShowing_start){
            [self hideDatePickerCell_start];
        }else {
            [self showDatePickerCell_start];
            [self hideDatePickerCell_end];
        }
    }
    else if(indexPath.row == 2){
        if (self.datePickerIsShowing_end){
            [self hideDatePickerCell_end];
        }else {
            [self showDatePickerCell_end];
            [self hideDatePickerCell_start];
        }
    }
    [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)showDatePickerCell_end
{
    self.datePickerIsShowing_end = YES;
    [self.tableView beginUpdates];
    [self.tableView endUpdates];
    self.date_picker_end.date = [dateFormatter dateFromString:self.lbl_end_date.text];
    self.date_picker_end.hidden = NO;
    self.date_picker_end.alpha = 0.0f;
    
    [UIView animateWithDuration:0.25 animations:^{
        
        self.date_picker_end.alpha = 1.0f;
        
    }];
}

- (void)hideDatePickerCell_end {
    self.datePickerIsShowing_end = NO;
    [self.tableView beginUpdates];
    [self.tableView endUpdates];
    
    [UIView animateWithDuration:0.25
                     animations:^{
                         self.date_picker_end.alpha = 0.0f;
                     }
                     completion:^(BOOL finished){
                         self.date_picker_end.hidden = YES;
                     }];
}


- (void)showDatePickerCell_start
{
    self.datePickerIsShowing_start = YES;
    [self.tableView beginUpdates];
    [self.tableView endUpdates];
    self.date_picker_start.date = [dateFormatter dateFromString:self.lbl_start_date.text];
    self.date_picker_start.hidden = NO;
    self.date_picker_start.alpha = 0.0f;
    
    [UIView animateWithDuration:0.25 animations:^{
        
        self.date_picker_start.alpha = 1.0f;
        
    }];
}

- (void)hideDatePickerCell_start {
    self.datePickerIsShowing_start = NO;
    [self.tableView beginUpdates];
    [self.tableView endUpdates];
    
    [UIView animateWithDuration:0.25
                     animations:^{
                         self.date_picker_start.alpha = 0.0f;
                     }
                     completion:^(BOOL finished){
                         self.date_picker_start.hidden = YES;
                     }];
}

- (IBAction)start_change:(UIDatePicker *)sender {
    self.lbl_start_date.text =  [dateFormatter stringFromDate:sender.date];
}

- (IBAction)end_change:(UIDatePicker *)sender {
        self.lbl_end_date.text =  [dateFormatter stringFromDate:sender.date];
}
- (IBAction)begin_edit:(id)sender {
    [self hideDatePickerCell_end];
    [self hideDatePickerCell_start];
}
- (IBAction)btn_query:(id)sender {
    [self.txt_no resignFirstResponder];
    [self.txt_phone resignFirstResponder];
    PNSoapBinding *pn = [PN PNSoapBinding];
    PN_TelRequestQueryList *params = [PN_Params get_pn_tel_request_query_list_params:self.lbl_start_date.text end_date:self.lbl_end_date.text tel:self.txt_phone.text rno:self.txt_no.text status:@"0"];
    [pn TelRequestQueryListAsyncUsingParameters:params delegate:self];
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
        
        if([bodyPart isKindOfClass:[PN_TelRequestQueryListResponse class]]) {
            PN_TelRequestQueryListResponse *body = (PN_TelRequestQueryListResponse*)bodyPart;
            if ([body.TelRequestQueryListResult.Result integerValue] == 0) {
                datas = [XmlParser load_orders:body.TelRequestQueryListResult.List];
                OrderListVC *olv = [[OrderListVC alloc] initWithNibName:nil bundle:nil];
                olv.orders = datas;
                [self.navigationController pushViewController:olv animated:YES];
            }
            else
            {
                [UIAlertView show_msg:body.TelRequestQueryListResult.ErrorDescription];
            }
        }

    }
}

@end
