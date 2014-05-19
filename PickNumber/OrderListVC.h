//
//  OrderListVC.h
//  PickNumber
//
//  Created by bruce on 14-5-18.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OrderListVC : UITableViewController
{
    NSMutableArray *orders;
}
@property(nonatomic, strong) NSMutableArray *orders;
@end
