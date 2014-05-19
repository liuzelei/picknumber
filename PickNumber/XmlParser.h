//
//  XmlParser.h
//  PickNumber
//
//  Created by bruce on 14-5-16.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDataXMLNode.h"
#import "User.h"

@interface XmlParser : NSObject

+(NSMutableArray *)load_item_datas:(NSString *)xml;
+(NSMutableArray *)load_tels:(NSString *)xml;
+(NSMutableArray *)load_orders:(NSString *)xml;

@end
