//
//  NumberDTVC.m
//  PickNumber
//
//  Created by bruce on 14-5-19.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "NumberDTVC.h"
#import "NumberOrderVC.h"

@interface NumberDTVC ()

@end

@implementation NumberDTVC

@synthesize tel;
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
    self.title = @"详细";
    [self set_view];
	// Do any additional setup after loading the view.
}

- (void)set_view
{
    self.lbl_tel.text = tel.tel;
    self.lbl_level.text = tel.level_num;
    self.lbl_min_fee.text = tel.min_fee;
    self.lbl_pre_deposit.text = [@(tel.pre_deposit) stringValue];
    self.lbl_star_num.text = [@(tel.star_num) stringValue];
    self.lbl_status.text = tel.status;
    self.lbl_group_num.text = [@(tel.group_num) stringValue];
    self.lbl_month_num.text = [@(tel.month_num) stringValue];
    self.lbl_feature.text = tel.input_feature;
    self.lbl_input_area.text = tel.input_area;
    self.lbl_note.text = tel.note;
    
}
- (IBAction)btn_next:(id)sender {
    UIStoryboard* storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    NumberOrderVC *novc = [storyboard instantiateViewControllerWithIdentifier:@"NumberOrderVC"];
    novc.tel = tel;
    [self.navigationController pushViewController:novc animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
//    
//    return 30;
//}
@end
