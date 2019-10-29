
#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif

@import ServiceCore;
@import ServiceChat;

@interface RNSalesforceChat : NSObject <SCSChatSessionDelegate, RCTBridgeModule>
@property (nonatomic, strong) RCTResponseSenderBlock callback;
@end

