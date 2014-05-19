//
//  OrderDetailVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "OrderDetailVC.h"

@interface OrderDetailVC ()

@end

@implementation OrderDetailVC
@synthesize order;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
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
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
