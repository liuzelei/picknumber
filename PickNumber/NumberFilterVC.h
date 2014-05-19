//
//  NumberFilterVC.h
//  PickNumber
//
//  Created by bruce on 14-5-13.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ItemData.h"

@protocol DissMissDelegate

@required
- (void)setLabel:(ItemData *)item_data;
@end

@interface NumberFilterVC : UITableViewController
{
    NSMutableArray *_datas;
    UILabel *_label;
  
}
@property (nonatomic,strong) NSMutableArray *datas;
@property (nonatomic, assign) id <DissMissDelegate> dissMissDelegate;

@end
