//
//  XmlParser.m
//  PickNumber
//
//  Created by bruce on 14-5-16.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "XmlParser.h"
#import "ItemData.h"
#import "Tel.h"
#import "Order.h"
#import "User.h"
@implementation XmlParser

+(NSMutableArray *)load_item_datas:(NSString *)xml
{
    NSString *xml_data = [NSString stringWithFormat:@"<Root>%@</Root>",xml];
    NSMutableArray *datas = [[NSMutableArray alloc] init];
    
    NSError *error;
    
    GDataXMLDocument *doc = [[GDataXMLDocument alloc] initWithXMLString:xml_data options:0 error:&error];
    
    NSArray *elements = [doc.rootElement elementsForName:@"t1"];
    for (GDataXMLElement *item_data in elements) {
        GDataXMLElement *nameElement = [[item_data elementsForName:@"Name"] objectAtIndex:0];
        GDataXMLElement *valueElement = [[item_data elementsForName:@"Value"] objectAtIndex:0];

        ItemData *data = [[ItemData alloc] init];
        data.ikey = [nameElement stringValue];;
        data.ivalue = [valueElement stringValue];
        [datas addObject:data];
    }
    return datas;
}

+(NSMutableArray *)load_tels:(NSString *)xml
{
    NSString *xml_data = [NSString stringWithFormat:@"<Root>%@</Root>",xml];
    NSMutableArray *datas = [[NSMutableArray alloc] init];
    
    NSError *error;
    
    GDataXMLDocument *doc = [[GDataXMLDocument alloc] initWithXMLString:xml_data options:0 error:&error];
    
    NSArray *elements = [doc.rootElement elementsForName:@"t1"];
    for (GDataXMLElement *item_data in elements) {
        GDataXMLElement *tel = [[item_data elementsForName:@"TEL"] objectAtIndex:0];
        GDataXMLElement *level_num = [[item_data elementsForName:@"LevelNum"] objectAtIndex:0];
        GDataXMLElement *min_fee = [[item_data elementsForName:@"MinFee"] objectAtIndex:0];
        GDataXMLElement *status = [[item_data elementsForName:@"Status"] objectAtIndex:0];
        GDataXMLElement *input_area = [[item_data elementsForName:@"InputArea"] objectAtIndex:0];
        GDataXMLElement *input_feature = [[item_data elementsForName:@"InputFeature"] objectAtIndex:0];
        GDataXMLElement *pre_deposit = [[item_data elementsForName:@"PreDeposit"] objectAtIndex:0];
        GDataXMLElement *star_num = [[item_data elementsForName:@"StarNum"] objectAtIndex:0];
        GDataXMLElement *group_num = [[item_data elementsForName:@"GroupNum"] objectAtIndex:0];
        GDataXMLElement *cost_num = [[item_data elementsForName:@"CostNum"] objectAtIndex:0];
        GDataXMLElement *month_num = [[item_data elementsForName:@"MonthNum"] objectAtIndex:0];
        GDataXMLElement *note = [[item_data elementsForName:@"Note"] objectAtIndex:0];
        
        Tel *data = [[Tel alloc] init];
        data.tel = [tel stringValue];
        data.level_num = [level_num stringValue];
        data.min_fee = [min_fee stringValue];
        data.status = [status stringValue];
        data.input_area = [input_area stringValue];
        data.input_feature = [input_feature stringValue];
        data.pre_deposit = [[pre_deposit stringValue] integerValue];
        data.group_num = [[group_num stringValue] integerValue];
        data.month_num = [[month_num stringValue] integerValue];
        data.cost_num = [[cost_num stringValue] integerValue];
        data.star_num = [[star_num stringValue] integerValue];
        data.note = [note stringValue];
        [datas addObject:data];
    }
    return datas;
}
+(NSMutableArray *)load_orders:(NSString *)xml
{
    NSString *xml_data = [NSString stringWithFormat:@"<Root>%@</Root>",xml];
    NSMutableArray *datas = [[NSMutableArray alloc] init];
    
    NSError *error;
    
    GDataXMLDocument *doc = [[GDataXMLDocument alloc] initWithXMLString:xml_data options:0 error:&error];
    
    NSArray *elements = [doc.rootElement elementsForName:@"t1"];
    for (GDataXMLElement *item_data in elements) {
        GDataXMLElement *tel = [[item_data elementsForName:@"TEL"] objectAtIndex:0];
        GDataXMLElement *rno = [[item_data elementsForName:@"RNO"] objectAtIndex:0];
        GDataXMLElement *level = [[item_data elementsForName:@"Level"] objectAtIndex:0];
        GDataXMLElement *rdate = [[item_data elementsForName:@"RDate"] objectAtIndex:0];
        GDataXMLElement *id_card = [[item_data elementsForName:@"IDCard"] objectAtIndex:0];
        GDataXMLElement *company_name = [[item_data elementsForName:@"CompanyName"] objectAtIndex:0];
        GDataXMLElement *custom_name = [[item_data elementsForName:@"CustomName"] objectAtIndex:0];
        GDataXMLElement *packet = [[item_data elementsForName:@"Packet"] objectAtIndex:0];
        GDataXMLElement *rresult = [[item_data elementsForName:@"RResult"] objectAtIndex:0];
        GDataXMLElement *status = [[item_data elementsForName:@"Status"] objectAtIndex:0];
        GDataXMLElement *rnote = [[item_data elementsForName:@"RNote"] objectAtIndex:0];
        
        Order *order = [[Order alloc] init];
        order.phone = [tel stringValue];
        order.no = [rno stringValue];
        order.level = [level stringValue];
        order.rdate = [rdate stringValue];
        order.id_card = [id_card stringValue];
        order.company_name = [company_name stringValue];
        order.custom_name = [custom_name stringValue];
        order.packet = [packet stringValue];
        order.rresult = [self get_rresult:[rresult stringValue]];
        order.status = [self get_status:[status stringValue]];
        order.rnote = [rnote stringValue];
        
        [datas addObject:order];
    }
    return datas;
}

+(NSString *)get_rresult:(NSString *)rresult
{
    switch ([rresult integerValue]) {
        case 0:
        {
            return @"未申请";
        }
        case 1:
        {
            return @"申请";
        }
        case 2:
        {
            return @"申请成功";
        }
        case 3:
        {
            return @"申请失败";
        }
        default:
            break;
    }
    return @"";
}

+(NSString *)get_status:(NSString *)status
{
    switch ([status integerValue]) {
        case 0:
        {
            return @"正常";
        }
        case 1:
        {
            return @"锁定(本系统)";
        }
        case 2:
        {
            return @"申请成功(本系统)";
        }
        case 3:
        {
            return @"外部申请(外部系统申请)";
        }
        default:
            break;
    }
    return @"";
}
@end
