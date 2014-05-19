#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
@class PN_Login;
@class PN_LoginResponse;
@class PN_LoginResult;
@class PN_GetMsgCode;
@class PN_GetMsgCodeResponse;
@class PN_GetMsgCodeResult;
@class PN_ItemQueryList;
@class PN_ItemQueryListResponse;
@class PN_ItemQueryListResult;
@class PN_LevelQueryList;
@class PN_LevelQueryListResponse;
@class PN_LevelQueryListResult;
@class PN_TelQueryList;
@class PN_TelQueryListResponse;
@class PN_TelQueryListResult;
@class PN_TELRequest;
@class PN_TELRequestResponse;
@class PN_TELRequestResult;
@class PN_TelRequestQueryList;
@class PN_TelRequestQueryListResponse;
@class PN_TelRequestQueryListResult;
@class PN_TELRequestDetail;
@class PN_TELRequestDetailResponse;
@class PN_TELRequestDetailResult;
@class PN_TELRequested;
@class PN_TELRequestedResponse;
@class PN_TELRequestedResult;
@class PN_GetUserInfo;
@class PN_GetUserInfoResponse;
@class PN_GetUserInfoResult;
@class PN_GetUpdateInfo;
@class PN_GetUpdateInfoResponse;
@class PN_GetUpdateInfoResult;
@class PN_ChangePassword;
@class PN_ChangePasswordResponse;
@class PN_ChangePasswordResult;
@class PN_FeatureQueryList;
@class PN_FeatureQueryListResponse;
@class PN_FeatureQueryListResult;
@interface PN_Login : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * TEL;
	NSString * Password;
	NSString * MsgCode;
	NSString * IMSI;
	NSNumber * SystemType;
	NSString * Version;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_Login *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * TEL;
@property (retain) NSString * Password;
@property (retain) NSString * MsgCode;
@property (retain) NSString * IMSI;
@property (retain) NSNumber * SystemType;
@property (retain) NSString * Version;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_LoginResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * UserToken;
	NSString * UserName;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_LoginResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * UserToken;
@property (retain) NSString * UserName;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_LoginResponse : NSObject {
	
/* elements */
	PN_LoginResult * LoginResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_LoginResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_LoginResult * LoginResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetMsgCode : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * TEL;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetMsgCode *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * TEL;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetMsgCodeResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetMsgCodeResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetMsgCodeResponse : NSObject {
	
/* elements */
	PN_GetMsgCodeResult * GetMsgCodeResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetMsgCodeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_GetMsgCodeResult * GetMsgCodeResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ItemQueryList : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSNumber * TypeID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ItemQueryList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSNumber * TypeID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ItemQueryListResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * List;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ItemQueryListResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * List;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ItemQueryListResponse : NSObject {
	
/* elements */
	PN_ItemQueryListResult * ItemQueryListResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ItemQueryListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_ItemQueryListResult * ItemQueryListResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_LevelQueryList : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * Prefix;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_LevelQueryList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * Prefix;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_LevelQueryListResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * List;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_LevelQueryListResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * List;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_LevelQueryListResponse : NSObject {
	
/* elements */
	PN_LevelQueryListResult * LevelQueryListResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_LevelQueryListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_LevelQueryListResult * LevelQueryListResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelQueryList : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * Prefix;
	NSNumber * Level;
	NSString * Feature;
	NSString * IncludeNum;
	NSString * ExcludeNum;
	NSNumber * IsArea;
	NSNumber * TELNum;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelQueryList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * Prefix;
@property (retain) NSNumber * Level;
@property (retain) NSString * Feature;
@property (retain) NSString * IncludeNum;
@property (retain) NSString * ExcludeNum;
@property (retain) NSNumber * IsArea;
@property (retain) NSNumber * TELNum;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelQueryListResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * List;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelQueryListResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * List;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelQueryListResponse : NSObject {
	
/* elements */
	PN_TelQueryListResult * TelQueryListResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelQueryListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_TelQueryListResult * TelQueryListResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequest : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * TEL;
	NSString * IDCard;
	NSString * CompanyName;
	NSString * CustomName;
	NSString * Packet;
	NSString * Note;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequest *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * TEL;
@property (retain) NSString * IDCard;
@property (retain) NSString * CompanyName;
@property (retain) NSString * CustomName;
@property (retain) NSString * Packet;
@property (retain) NSString * Note;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
	NSString * RNO;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
@property (retain) NSString * RNO;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestResponse : NSObject {
	
/* elements */
	PN_TELRequestResult * TELRequestResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_TELRequestResult * TELRequestResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelRequestQueryList : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * BDate;
	NSString * EDate;
	NSString * TEL;
	NSString * RNO;
	NSNumber * RequestStatus;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelRequestQueryList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * BDate;
@property (retain) NSString * EDate;
@property (retain) NSString * TEL;
@property (retain) NSString * RNO;
@property (retain) NSNumber * RequestStatus;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelRequestQueryListResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * List;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelRequestQueryListResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * List;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TelRequestQueryListResponse : NSObject {
	
/* elements */
	PN_TelRequestQueryListResult * TelRequestQueryListResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TelRequestQueryListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_TelRequestQueryListResult * TelRequestQueryListResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestDetail : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * RNO;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestDetail *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * RNO;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestDetailResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
	NSString * TEL;
	NSString * RNO;
	NSString * Level;
	NSString * RDate;
	NSString * IDCard;
	NSString * Packet;
	NSString * CompanyName;
	NSString * CustomName;
	NSString * RResult;
	NSNumber * Status;
	NSString * RNote;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestDetailResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
@property (retain) NSString * TEL;
@property (retain) NSString * RNO;
@property (retain) NSString * Level;
@property (retain) NSString * RDate;
@property (retain) NSString * IDCard;
@property (retain) NSString * Packet;
@property (retain) NSString * CompanyName;
@property (retain) NSString * CustomName;
@property (retain) NSString * RResult;
@property (retain) NSNumber * Status;
@property (retain) NSString * RNote;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestDetailResponse : NSObject {
	
/* elements */
	PN_TELRequestDetailResult * TELRequestDetailResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestDetailResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_TELRequestDetailResult * TELRequestDetailResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequested : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * BDate;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequested *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * BDate;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestedResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
	NSNumber * SuccessNum;
	NSNumber * FailedNum;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestedResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
@property (retain) NSNumber * SuccessNum;
@property (retain) NSNumber * FailedNum;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_TELRequestedResponse : NSObject {
	
/* elements */
	PN_TELRequestedResult * TELRequestedResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_TELRequestedResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_TELRequestedResult * TELRequestedResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUserInfo : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUserInfo *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUserInfoResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
	NSString * Name;
	NSString * TEL;
	NSString * LoginName;
	NSString * CompanyName;
	NSString * AreaName;
	NSString * WorkNo;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUserInfoResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
@property (retain) NSString * Name;
@property (retain) NSString * TEL;
@property (retain) NSString * LoginName;
@property (retain) NSString * CompanyName;
@property (retain) NSString * AreaName;
@property (retain) NSString * WorkNo;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUserInfoResponse : NSObject {
	
/* elements */
	PN_GetUserInfoResult * GetUserInfoResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUserInfoResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_GetUserInfoResult * GetUserInfoResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUpdateInfo : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSNumber * SystemType;
	NSString * Version;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUpdateInfo *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSNumber * SystemType;
@property (retain) NSString * Version;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUpdateInfoResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
	NSString * URL;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUpdateInfoResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
@property (retain) NSString * URL;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_GetUpdateInfoResponse : NSObject {
	
/* elements */
	PN_GetUpdateInfoResult * GetUpdateInfoResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_GetUpdateInfoResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_GetUpdateInfoResult * GetUpdateInfoResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ChangePassword : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSString * OldPassword;
	NSString * NewPassword;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ChangePassword *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSString * OldPassword;
@property (retain) NSString * NewPassword;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ChangePasswordResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ChangePasswordResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_ChangePasswordResponse : NSObject {
	
/* elements */
	PN_ChangePasswordResult * ChangePasswordResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_ChangePasswordResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_ChangePasswordResult * ChangePasswordResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_FeatureQueryList : NSObject {
	
/* elements */
	NSString * APPID;
	NSString * UserToken;
	NSNumber * Level;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_FeatureQueryList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * APPID;
@property (retain) NSString * UserToken;
@property (retain) NSNumber * Level;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_FeatureQueryListResult : NSObject {
	
/* elements */
	NSNumber * Result;
	NSString * List;
	NSString * ErrorDescription;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_FeatureQueryListResult *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * Result;
@property (retain) NSString * List;
@property (retain) NSString * ErrorDescription;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface PN_FeatureQueryListResponse : NSObject {
	
/* elements */
	PN_FeatureQueryListResult * FeatureQueryListResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (PN_FeatureQueryListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) PN_FeatureQueryListResult * FeatureQueryListResult;
/* attributes */
- (NSDictionary *)attributes;
@end
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xsd.h"
#import "PN.h"
@class PNSoapBinding;
@class PNSoap12Binding;
@interface PN : NSObject {
	
}
+ (PNSoapBinding *)PNSoapBinding;
+ (PNSoap12Binding *)PNSoap12Binding;
@end
@class PNSoapBindingResponse;
@class PNSoapBindingOperation;
@protocol PNSoapBindingResponseDelegate <NSObject>
- (void) operation:(PNSoapBindingOperation *)operation completedWithResponse:(PNSoapBindingResponse *)response;
@end
@interface PNSoapBinding : NSObject <PNSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(PNSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (PNSoapBindingResponse *)LoginUsingParameters:(PN_Login *)aParameters ;
- (void)LoginAsyncUsingParameters:(PN_Login *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)GetMsgCodeUsingParameters:(PN_GetMsgCode *)aParameters ;
- (void)GetMsgCodeAsyncUsingParameters:(PN_GetMsgCode *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)ItemQueryListUsingParameters:(PN_ItemQueryList *)aParameters ;
- (void)ItemQueryListAsyncUsingParameters:(PN_ItemQueryList *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)LevelQueryListUsingParameters:(PN_LevelQueryList *)aParameters ;
- (void)LevelQueryListAsyncUsingParameters:(PN_LevelQueryList *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)TelQueryListUsingParameters:(PN_TelQueryList *)aParameters ;
- (void)TelQueryListAsyncUsingParameters:(PN_TelQueryList *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)TELRequestUsingParameters:(PN_TELRequest *)aParameters ;
- (void)TELRequestAsyncUsingParameters:(PN_TELRequest *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)TelRequestQueryListUsingParameters:(PN_TelRequestQueryList *)aParameters ;
- (void)TelRequestQueryListAsyncUsingParameters:(PN_TelRequestQueryList *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)TELRequestDetailUsingParameters:(PN_TELRequestDetail *)aParameters ;
- (void)TELRequestDetailAsyncUsingParameters:(PN_TELRequestDetail *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)TELRequestedUsingParameters:(PN_TELRequested *)aParameters ;
- (void)TELRequestedAsyncUsingParameters:(PN_TELRequested *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)GetUserInfoUsingParameters:(PN_GetUserInfo *)aParameters ;
- (void)GetUserInfoAsyncUsingParameters:(PN_GetUserInfo *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)GetUpdateInfoUsingParameters:(PN_GetUpdateInfo *)aParameters ;
- (void)GetUpdateInfoAsyncUsingParameters:(PN_GetUpdateInfo *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)ChangePasswordUsingParameters:(PN_ChangePassword *)aParameters ;
- (void)ChangePasswordAsyncUsingParameters:(PN_ChangePassword *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
- (PNSoapBindingResponse *)FeatureQueryListUsingParameters:(PN_FeatureQueryList *)aParameters ;
- (void)FeatureQueryListAsyncUsingParameters:(PN_FeatureQueryList *)aParameters  delegate:(id<PNSoapBindingResponseDelegate>)responseDelegate;
@end
@interface PNSoapBindingOperation : NSOperation {
	PNSoapBinding *binding;
	PNSoapBindingResponse *response;
	id<PNSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) PNSoapBinding *binding;
@property (readonly) PNSoapBindingResponse *response;
@property (nonatomic, assign) id<PNSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate;
@end
@interface PNSoapBinding_Login : PNSoapBindingOperation {
	PN_Login * parameters;
}
@property (retain) PN_Login * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_Login *)aParameters
;
@end
@interface PNSoapBinding_GetMsgCode : PNSoapBindingOperation {
	PN_GetMsgCode * parameters;
}
@property (retain) PN_GetMsgCode * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_GetMsgCode *)aParameters
;
@end
@interface PNSoapBinding_ItemQueryList : PNSoapBindingOperation {
	PN_ItemQueryList * parameters;
}
@property (retain) PN_ItemQueryList * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_ItemQueryList *)aParameters
;
@end
@interface PNSoapBinding_LevelQueryList : PNSoapBindingOperation {
	PN_LevelQueryList * parameters;
}
@property (retain) PN_LevelQueryList * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_LevelQueryList *)aParameters
;
@end
@interface PNSoapBinding_TelQueryList : PNSoapBindingOperation {
	PN_TelQueryList * parameters;
}
@property (retain) PN_TelQueryList * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_TelQueryList *)aParameters
;
@end
@interface PNSoapBinding_TELRequest : PNSoapBindingOperation {
	PN_TELRequest * parameters;
}
@property (retain) PN_TELRequest * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequest *)aParameters
;
@end
@interface PNSoapBinding_TelRequestQueryList : PNSoapBindingOperation {
	PN_TelRequestQueryList * parameters;
}
@property (retain) PN_TelRequestQueryList * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_TelRequestQueryList *)aParameters
;
@end
@interface PNSoapBinding_TELRequestDetail : PNSoapBindingOperation {
	PN_TELRequestDetail * parameters;
}
@property (retain) PN_TELRequestDetail * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequestDetail *)aParameters
;
@end
@interface PNSoapBinding_TELRequested : PNSoapBindingOperation {
	PN_TELRequested * parameters;
}
@property (retain) PN_TELRequested * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequested *)aParameters
;
@end
@interface PNSoapBinding_GetUserInfo : PNSoapBindingOperation {
	PN_GetUserInfo * parameters;
}
@property (retain) PN_GetUserInfo * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_GetUserInfo *)aParameters
;
@end
@interface PNSoapBinding_GetUpdateInfo : PNSoapBindingOperation {
	PN_GetUpdateInfo * parameters;
}
@property (retain) PN_GetUpdateInfo * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_GetUpdateInfo *)aParameters
;
@end
@interface PNSoapBinding_ChangePassword : PNSoapBindingOperation {
	PN_ChangePassword * parameters;
}
@property (retain) PN_ChangePassword * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_ChangePassword *)aParameters
;
@end
@interface PNSoapBinding_FeatureQueryList : PNSoapBindingOperation {
	PN_FeatureQueryList * parameters;
}
@property (retain) PN_FeatureQueryList * parameters;
- (id)initWithBinding:(PNSoapBinding *)aBinding delegate:(id<PNSoapBindingResponseDelegate>)aDelegate
	parameters:(PN_FeatureQueryList *)aParameters
;
@end
@interface PNSoapBinding_envelope : NSObject {
}
+ (PNSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface PNSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
@class PNSoap12BindingResponse;
@class PNSoap12BindingOperation;
@protocol PNSoap12BindingResponseDelegate <NSObject>
- (void) operation:(PNSoap12BindingOperation *)operation completedWithResponse:(PNSoap12BindingResponse *)response;
@end
@interface PNSoap12Binding : NSObject <PNSoap12BindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(PNSoap12BindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (PNSoap12BindingResponse *)LoginUsingParameters:(PN_Login *)aParameters ;
- (void)LoginAsyncUsingParameters:(PN_Login *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)GetMsgCodeUsingParameters:(PN_GetMsgCode *)aParameters ;
- (void)GetMsgCodeAsyncUsingParameters:(PN_GetMsgCode *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)ItemQueryListUsingParameters:(PN_ItemQueryList *)aParameters ;
- (void)ItemQueryListAsyncUsingParameters:(PN_ItemQueryList *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)LevelQueryListUsingParameters:(PN_LevelQueryList *)aParameters ;
- (void)LevelQueryListAsyncUsingParameters:(PN_LevelQueryList *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)TelQueryListUsingParameters:(PN_TelQueryList *)aParameters ;
- (void)TelQueryListAsyncUsingParameters:(PN_TelQueryList *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)TELRequestUsingParameters:(PN_TELRequest *)aParameters ;
- (void)TELRequestAsyncUsingParameters:(PN_TELRequest *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)TelRequestQueryListUsingParameters:(PN_TelRequestQueryList *)aParameters ;
- (void)TelRequestQueryListAsyncUsingParameters:(PN_TelRequestQueryList *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)TELRequestDetailUsingParameters:(PN_TELRequestDetail *)aParameters ;
- (void)TELRequestDetailAsyncUsingParameters:(PN_TELRequestDetail *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)TELRequestedUsingParameters:(PN_TELRequested *)aParameters ;
- (void)TELRequestedAsyncUsingParameters:(PN_TELRequested *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)GetUserInfoUsingParameters:(PN_GetUserInfo *)aParameters ;
- (void)GetUserInfoAsyncUsingParameters:(PN_GetUserInfo *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)GetUpdateInfoUsingParameters:(PN_GetUpdateInfo *)aParameters ;
- (void)GetUpdateInfoAsyncUsingParameters:(PN_GetUpdateInfo *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)ChangePasswordUsingParameters:(PN_ChangePassword *)aParameters ;
- (void)ChangePasswordAsyncUsingParameters:(PN_ChangePassword *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
- (PNSoap12BindingResponse *)FeatureQueryListUsingParameters:(PN_FeatureQueryList *)aParameters ;
- (void)FeatureQueryListAsyncUsingParameters:(PN_FeatureQueryList *)aParameters  delegate:(id<PNSoap12BindingResponseDelegate>)responseDelegate;
@end
@interface PNSoap12BindingOperation : NSOperation {
	PNSoap12Binding *binding;
	PNSoap12BindingResponse *response;
	id<PNSoap12BindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) PNSoap12Binding *binding;
@property (readonly) PNSoap12BindingResponse *response;
@property (nonatomic, assign) id<PNSoap12BindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate;
@end
@interface PNSoap12Binding_Login : PNSoap12BindingOperation {
	PN_Login * parameters;
}
@property (retain) PN_Login * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_Login *)aParameters
;
@end
@interface PNSoap12Binding_GetMsgCode : PNSoap12BindingOperation {
	PN_GetMsgCode * parameters;
}
@property (retain) PN_GetMsgCode * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_GetMsgCode *)aParameters
;
@end
@interface PNSoap12Binding_ItemQueryList : PNSoap12BindingOperation {
	PN_ItemQueryList * parameters;
}
@property (retain) PN_ItemQueryList * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_ItemQueryList *)aParameters
;
@end
@interface PNSoap12Binding_LevelQueryList : PNSoap12BindingOperation {
	PN_LevelQueryList * parameters;
}
@property (retain) PN_LevelQueryList * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_LevelQueryList *)aParameters
;
@end
@interface PNSoap12Binding_TelQueryList : PNSoap12BindingOperation {
	PN_TelQueryList * parameters;
}
@property (retain) PN_TelQueryList * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_TelQueryList *)aParameters
;
@end
@interface PNSoap12Binding_TELRequest : PNSoap12BindingOperation {
	PN_TELRequest * parameters;
}
@property (retain) PN_TELRequest * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequest *)aParameters
;
@end
@interface PNSoap12Binding_TelRequestQueryList : PNSoap12BindingOperation {
	PN_TelRequestQueryList * parameters;
}
@property (retain) PN_TelRequestQueryList * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_TelRequestQueryList *)aParameters
;
@end
@interface PNSoap12Binding_TELRequestDetail : PNSoap12BindingOperation {
	PN_TELRequestDetail * parameters;
}
@property (retain) PN_TELRequestDetail * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequestDetail *)aParameters
;
@end
@interface PNSoap12Binding_TELRequested : PNSoap12BindingOperation {
	PN_TELRequested * parameters;
}
@property (retain) PN_TELRequested * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_TELRequested *)aParameters
;
@end
@interface PNSoap12Binding_GetUserInfo : PNSoap12BindingOperation {
	PN_GetUserInfo * parameters;
}
@property (retain) PN_GetUserInfo * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_GetUserInfo *)aParameters
;
@end
@interface PNSoap12Binding_GetUpdateInfo : PNSoap12BindingOperation {
	PN_GetUpdateInfo * parameters;
}
@property (retain) PN_GetUpdateInfo * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_GetUpdateInfo *)aParameters
;
@end
@interface PNSoap12Binding_ChangePassword : PNSoap12BindingOperation {
	PN_ChangePassword * parameters;
}
@property (retain) PN_ChangePassword * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_ChangePassword *)aParameters
;
@end
@interface PNSoap12Binding_FeatureQueryList : PNSoap12BindingOperation {
	PN_FeatureQueryList * parameters;
}
@property (retain) PN_FeatureQueryList * parameters;
- (id)initWithBinding:(PNSoap12Binding *)aBinding delegate:(id<PNSoap12BindingResponseDelegate>)aDelegate
	parameters:(PN_FeatureQueryList *)aParameters
;
@end
@interface PNSoap12Binding_envelope : NSObject {
}
+ (PNSoap12Binding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface PNSoap12BindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
