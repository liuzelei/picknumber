//
//  User.h
//  PickNumber
//
//  Created by bruce on 14-5-15.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject

@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *token;
@property (nonatomic, retain) NSString *phone; //登录账号
@property (nonatomic, retain) NSString *tel; //电话
@property (nonatomic, retain) NSString *department;
@property (nonatomic, retain) NSString *area;
@property (nonatomic, retain) NSString *no;
@property (nonatomic, assign) BOOL is_remember;

+ (User *)current_user;
- (id)initWithData:(NSString *)name phone:(NSString *)phone  token:(NSString *)token is_remember:(BOOL)is_remember;

@end
