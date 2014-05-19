//
//  Tel.h
//  PickNumber
//
//  Created by bruce on 14-5-16.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Tel : NSObject

@property (nonatomic, retain) NSString *tel;
@property (nonatomic, retain) NSString *level_num;
@property (nonatomic, retain) NSString *min_fee;
@property (nonatomic, retain) NSString *status;
@property (nonatomic, retain) NSString *input_area;
@property (nonatomic, retain) NSString *input_feature;
@property (nonatomic, assign) NSInteger pre_deposit;
@property (nonatomic, assign) NSInteger star_num;
@property (nonatomic, assign) NSInteger group_num;
@property (nonatomic, assign) NSInteger cost_num;
@property (nonatomic, assign) NSInteger month_num;
@property (nonatomic, retain) NSString *note;
@end
