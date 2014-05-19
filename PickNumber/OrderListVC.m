//
//  OrderListVC.m
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "OrderListVC.h"
#import "Order.h"
#import "OrderDetailTVC.h"

@interface OrderListVC ()

@end

@implementation OrderListVC

@synthesize orders;

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
    self.title=@"已完成申请单";
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [orders count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    NSArray *subviews = [[NSArray alloc] initWithArray:cell.contentView.subviews];
    for(UIView *subview in subviews) {
        [subview removeFromSuperview];
    }
    UILabel *lbl_title =[[UILabel alloc] initWithFrame:CGRectMake(15, 4, 70, 18)];
    lbl_title.font = [UIFont systemFontOfSize:13];
    UILabel *lbl_no = [[UILabel alloc] initWithFrame:CGRectMake(85, 4, 145, 18)];
    lbl_no.font = [UIFont systemFontOfSize:13];
    
    UILabel *lbl_date = [[UILabel alloc] initWithFrame:CGRectMake(15, 23, 200, 15)];
    lbl_date.font = [UIFont systemFontOfSize:13];
    UILabel *lbl_status = [[UILabel alloc] initWithFrame:CGRectMake(250, 23, 80, 15)];
    lbl_status.font = [UIFont systemFontOfSize:13];
    
    Order *order = [orders objectAtIndex:indexPath.row];
    lbl_title.text = @"申请单号:";
    lbl_no.text = order.no;
    lbl_date.text = order.rdate;
    lbl_status.text = order.status;
    
    [cell.contentView addSubview:lbl_title];
    [cell.contentView addSubview:lbl_no];
    [cell.contentView addSubview:lbl_status];
    [cell.contentView addSubview:lbl_date];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    OrderDetailTVC *odvc=[storyboard instantiateViewControllerWithIdentifier:@"OrderDetailTVC"];
    odvc.order = [orders objectAtIndex:indexPath.row];
    [self.navigationController pushViewController:odvc animated:YES];
}


@end
