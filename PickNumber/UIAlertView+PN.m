//
//  UIAlertView+PN.m
//  PickNumber
//
//  Created by bruce on 14-5-19.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "UIAlertView+PN.h"

@implementation UIAlertView (PN)

+(void)show_msg:(NSString *)msg
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:msg delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
    [alert show];
}

@end
