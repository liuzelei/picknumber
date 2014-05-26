//
//  PN_Params.m
//  PickNumber
//
//  Created by bruce on 14-5-15.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import "PN_Params.h"
#import "AppConstants.h"
#import "OpenUDID.h"
#import "User.h"


@implementation PN_Params

+(PN_GetUserInfo *)get_user_info_params
{
    PN_GetUserInfo *params = [PN_GetUserInfo new];
    params.APPID = APP_ID;
    params.UserToken = [User current_user].token;
    return params;
}

+(PN_GetUpdateInfo *)get_update_info_params
{
    PN_GetUpdateInfo *params = [PN_GetUpdateInfo new];
    params.APPID = APP_ID;
    params.UserToken = [User current_user].token;
    params.SystemType = [NSNumber numberWithInt:1];
    params.Version = VERSION;
    return params;
}

+(PN_ChangePassword *)get_pn_change_password_params:(NSString *)old_password new_password:(NSString *)new_password
{
    PN_ChangePassword *params = [PN_ChangePassword new];
    params.APPID = APP_ID;
    params.UserToken = [User current_user].token;
    params.OldPassword = old_password;
    params.NewPassword = new_password;
    return params;
}

+(PN_Login *)get_pn_login_params:(NSString *)tel msg_code:(NSString *)msg_code password:(NSString *)password
{
    PN_Login *pn_login_params = [PN_Login new];
    pn_login_params.TEL = tel;
    pn_login_params.MsgCode = msg_code;
    pn_login_params.Password = @"";
    pn_login_params.APPID = APP_ID;
    pn_login_params.IMSI = [OpenUDID value];
    pn_login_params.SystemType = [NSNumber numberWithInt:1];
    pn_login_params.Version = VERSION;
    return pn_login_params;
}

+(PN_GetMsgCode *)get_pn_get_msg_code:(NSString *)tel
{
    PN_GetMsgCode *pn_get_msg_code_params = [PN_GetMsgCode new];
    pn_get_msg_code_params.APPID = APP_ID;
    pn_get_msg_code_params.TEL = tel;
    return pn_get_msg_code_params;
}

+(PN_ItemQueryList *)get_item_query_list_params:(NSString *)type_id
{
    PN_ItemQueryList *pn_item_query_list = [PN_ItemQueryList new];
    pn_item_query_list.APPID = APP_ID;
    pn_item_query_list.UserToken = [User current_user].token;
    pn_item_query_list.TypeID = [NSNumber numberWithInteger:[type_id integerValue]];
    return pn_item_query_list;
}

+(PN_LevelQueryList *)get_pn_level_query_list:(NSString *)prefix
{
    PN_LevelQueryList *pn_level_query_list_params = [PN_LevelQueryList new];
    pn_level_query_list_params.APPID = APP_ID;
    pn_level_query_list_params.UserToken = [User current_user].token;
    pn_level_query_list_params.Prefix = prefix;
    return pn_level_query_list_params;
}

+(PN_FeatureQueryList *)get_pn_feature_query_list:(NSString *)level
{
    PN_FeatureQueryList *pn_feature_query_list_params = [PN_FeatureQueryList new];
    pn_feature_query_list_params.APPID = APP_ID;
    pn_feature_query_list_params.UserToken = [User current_user].token;
    pn_feature_query_list_params.Level = [NSNumber numberWithInteger:[level integerValue]];
    return pn_feature_query_list_params;
}

+(PN_TelQueryList *)get_pn_tel_query_list_params:(NSString *)prefix level:(NSString *)level feature:(NSString *)feature
                                     include_num:(NSString *)include_num exclude_num:(BOOL)exclude_num
                                         is_area:(BOOL)is_area
{
    
    PN_TelQueryList *pn_tel_query_list_params = [PN_TelQueryList new];
    pn_tel_query_list_params.APPID = APP_ID;
    pn_tel_query_list_params.UserToken = [User current_user].token;
    pn_tel_query_list_params.Prefix = prefix;
    pn_tel_query_list_params.Level = [NSNumber numberWithInteger:[level integerValue]];
//    [NSNumber numberWithInteger:[level integerValue]>=0 ? [level integerValue] : 0 ];
    pn_tel_query_list_params.Feature = feature;
    pn_tel_query_list_params.IncludeNum = include_num ==nil ? @"" : include_num;
    pn_tel_query_list_params.ExcludeNum = exclude_num ? @"4" : @"";
    pn_tel_query_list_params.IsArea = [NSNumber numberWithInteger:is_area ? 1 : 0];
    pn_tel_query_list_params.TELNum = [NSNumber numberWithInteger:PAGECOUNT];
    return pn_tel_query_list_params;
}

+(PN_TELRequest *)get_pn_tel_request_params:(NSString *)tel id_card:(NSString *)id_card company_name:(NSString *)company_name
                                custom_name:(NSString *)custom_name pack_et:(NSString *)pack_et note:(NSString *)note
{
    PN_TELRequest *pn_tel_request_params = [PN_TELRequest new];
    pn_tel_request_params.APPID = APP_ID;
    pn_tel_request_params.UserToken = [User current_user].token;
    pn_tel_request_params.TEL = tel;
    pn_tel_request_params.IDCard = id_card;
    pn_tel_request_params.CompanyName = company_name;
    pn_tel_request_params.CustomName = custom_name;
    pn_tel_request_params.Packet = pack_et;
    pn_tel_request_params.Note = note;
    return pn_tel_request_params;
}

+(PN_TELRequestDetail *)get_pn_tel_request_detail:(NSString *)no
{
    PN_TELRequestDetail *pn_tel_request_detail_params = [PN_TELRequestDetail new];
    pn_tel_request_detail_params.APPID = APP_ID;
    pn_tel_request_detail_params.UserToken = [User current_user].token;
    pn_tel_request_detail_params.RNO = no;
    return pn_tel_request_detail_params;
}

+(PN_TelRequestQueryList *)get_pn_tel_request_query_list_params:(NSString *)start_date end_date:(NSString *)end_date tel:(NSString *)tel rno:(NSString *)rno status:(NSString *)status
{
    PN_TelRequestQueryList *pn_tel_request_query_params = [PN_TelRequestQueryList new];
    pn_tel_request_query_params.APPID = APP_ID;
    pn_tel_request_query_params.UserToken = [User current_user].token;
    pn_tel_request_query_params.BDate = start_date;
    pn_tel_request_query_params.EDate = end_date;
    pn_tel_request_query_params.TEL = tel==nil ? @"" : tel;
    pn_tel_request_query_params.RNO = rno==nil ? @"" : rno;
    pn_tel_request_query_params.RequestStatus = [NSNumber numberWithInteger:[status integerValue]];
    return pn_tel_request_query_params;
}

@end
