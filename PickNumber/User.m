//
//  User.m
//  PickNumber
//
//  Created by bruce on 14-5-15.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "User.h"

@implementation User

@synthesize name=_name,token=_token,phone=_phone,is_remember=_is_remember,area=_area,tel=_tel,no=_no,department=_department;

- (id)initWithData:(NSString *)name phone:(NSString *)phone  token:(NSString *)token is_remember:(BOOL )is_remember
{
    if ((self = [super init])) {
        self.name = name;
        self.phone = phone;
        self.token = token;
        self.is_remember = is_remember;
    }
    return self;
}

+ (User *)current_user
{
    User *user;
    if (user == nil) {
        user = [[User alloc] init];
        
        NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
        NSDictionary *userDict =  [userDefaults objectForKey:@"user"];
        if (userDict!=nil) {
            [user setValuesForKeysWithDictionary:userDict];
        }
    }
    return user;
}
@end
