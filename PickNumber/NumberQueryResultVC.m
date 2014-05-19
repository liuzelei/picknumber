//
//  NumberQueryResultVC.m
//  PickNumber
//
//  Created by bruce on 14-5-13.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "NumberQueryResultVC.h"
#import "NumberDTVC.h"
#import "Tel.h"
@interface NumberQueryResultVC ()

@end

@implementation NumberQueryResultVC

@synthesize tels;

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
    self.title = @"查询结果";
    self.view.tag = 11;
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
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [tels count];
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
    
    UILabel *lbl_number = [[UILabel alloc] initWithFrame:CGRectMake(15, 11, 110, 21)];
    lbl_number.font = [UIFont systemFontOfSize:15];
    UILabel *lbl_level = [[UILabel alloc] initWithFrame:CGRectMake(135, 11, 35, 21)];
    lbl_level.font = [UIFont systemFontOfSize:15];
    UILabel *lbl_region = [[UILabel alloc] initWithFrame:CGRectMake(190, 11, 100, 21)];
    lbl_region.font = [UIFont systemFontOfSize:15];
    
    Tel *tel = [tels objectAtIndex:indexPath.row];
    
    lbl_number.text = tel.tel;
    lbl_level.text = tel.level_num;
    lbl_region.text = tel.input_area;
    [cell.contentView addSubview:lbl_number];
    [cell.contentView addSubview:lbl_level];
    [cell.contentView addSubview:lbl_region];
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 44;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    UIStoryboard* storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    NumberDTVC *number_dvc = [storyboard instantiateViewControllerWithIdentifier:@"NumberDTVC"];
    number_dvc.tel = [tels objectAtIndex:indexPath.row];
    [self.navigationController pushViewController:number_dvc animated:YES];
}

@end
