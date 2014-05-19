//
//  OrderDetailTVC.h
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Order.h"
@interface OrderDetailTVC : UITableViewController
{
    Order *order;
}
@property (strong, nonatomic) Order *order;
@property (strong, nonatomic) IBOutlet UILabel *lbl_tel;
@property (strong, nonatomic) IBOutlet UILabel *lbl_no;
@property (strong, nonatomic) IBOutlet UILabel *lbl_date;
@property (strong, nonatomic) IBOutlet UILabel *lbl_level;
@property (strong, nonatomic) IBOutlet UILabel *lbl_id_card;
@property (strong, nonatomic) IBOutlet UILabel *lbl_company_name;
@property (strong, nonatomic) IBOutlet UILabel *lbl_custom_name;
@property (strong, nonatomic) IBOutlet UILabel *lbl_packet;
@property (strong, nonatomic) IBOutlet UILabel *lbl_result;
@property (strong, nonatomic) IBOutlet UILabel *lbl_status;
@property (strong, nonatomic) IBOutlet UILabel *lbl_note;
@end
