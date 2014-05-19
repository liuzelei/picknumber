//
//  PN_Params.h
//  PickNumber
//
//  Created by bruce on 14-5-15.
//  Copyright (c) 2014年 bruce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PN.h"

@interface PN_Params : NSObject

+(PN_Login *)get_pn_login_params:(NSString *)tel msg_code:(NSString *)msg_code password:(NSString *)password;
+(PN_GetMsgCode *)get_pn_get_msg_code:(NSString *)tel;
+(PN_ItemQueryList *)get_item_query_list_params:(NSString *)type_id;
+(PN_LevelQueryList *)get_pn_level_query_list:(NSString *)prefix;
+(PN_FeatureQueryList *)get_pn_feature_query_list:(NSString *)level;
+(PN_TelQueryList *)get_pn_tel_query_list_params:(NSString *)prefix level:(NSString *)level feature:(NSString *)feature
                                     include_num:(NSString *)include_num exclude_num:(BOOL)exclude_num is_area:(BOOL)is_area;
+(PN_TELRequest *)get_pn_tel_request_params:(NSString *)tel id_card:(NSString *)id_card company_name:(NSString *)company_name
                                custom_name:(NSString *)custom_name pack_et:(NSString *)pack_et note:(NSString *)note;
+(PN_TelRequestQueryList *)get_pn_tel_request_query_list_params:(NSString *)start_date end_date:(NSString *)end_date tel:(NSString *)tel rno:(NSString *)rno status:(NSString *)status;
+(PN_GetUserInfo *)get_user_info_params;
+(PN_ChangePassword *)get_pn_change_password_params:(NSString *)old_password new_password:(NSString *)new_password;
@end
