//
//  OrderDetailTVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "OrderDetailTVC.h"

@interface OrderDetailTVC ()

@end

@implementation OrderDetailTVC
@synthesize order;
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
    self.title=@"申请单详细";
    [self setup];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)setup
{
    self.lbl_company_name.text = order.company_name;
    self.lbl_tel.text = order.phone;
    self.lbl_no.text = order.no;
    self.lbl_level.text = order.level;
    self.lbl_id_card.text = order.id_card;
    self.lbl_date.text = order.rdate;
    self.lbl_note.text = order.rnote;
    self.lbl_status.text = order.status;
    self.lbl_packet.text = order.packet;
    self.lbl_custom_name.text = order.custom_name;
    self.lbl_result.text = order.rresult;
}

@end
