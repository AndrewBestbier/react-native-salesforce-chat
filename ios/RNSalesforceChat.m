#import "RNSalesforceChat.h"

@import ServiceCore;
@import ServiceChat;

@implementation RNSalesforceChat

NSArray *prechatFields;
NSMutableArray *prechatEntities;
SCSChatConfiguration *chatConfiguration;

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(configLaunch:(NSString *)subject origin:(NSString *)origin currencyISOCode: (NSString *)currencyISOCode status: (NSString *)status contactType:(NSString *)contactType locale:(NSString *)locale suppliedEmail:(NSString *)suppliedEmail email:(NSString *)email suppliedName:(NSString *)suppliedName)
{
    prechatEntities = [NSMutableArray array];

    // Prechat fields
    prechatFields = @[
      [[SCSPrechatObject alloc] initWithLabel:@"Origin" value: origin],
      [[SCSPrechatObject alloc] initWithLabel:@"CurrencyISOCode" value: currencyISOCode],
      [[SCSPrechatObject alloc] initWithLabel:@"Status" value: status],
      [[SCSPrechatObject alloc] initWithLabel:@"ContactType__c" value: contactType],
      [[SCSPrechatObject alloc] initWithLabel:@"Locale__c" value: locale],
      [[SCSPrechatObject alloc] initWithLabel:@"SuppliedName" value: suppliedName],
      [[SCSPrechatObject alloc] initWithLabel:@"SuppliedEmail" value: suppliedEmail],
      [[SCSPrechatObject alloc] initWithLabel:@"Email" value: email],
      [[SCSPrechatObject alloc] initWithLabel:@"Subject" value: subject],
    ];

    // Prechat entities
    NSArray *caseEntityFields = @[
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Subject" label:@"Subject"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Origin" label:@"Origin"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"CurrencyISOCode" label:@"CurrencyIsoCode"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Status" label:@"Status"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"ContactType__c" label:@"ContactType__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Locale__c" label:@"Locale__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"SuppliedName" label:@"SuppliedName"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"SuppliedEmail" label:@"SuppliedEmail"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Email" label:@"Email"]
    ];

    for (SCSPrechatEntityField* entityField in caseEntityFields) {
        entityField.doCreate = YES;
    }

    SCSPrechatEntity* caseEntity = [[SCSPrechatEntity alloc] initWithEntityName:@"Case"];
    caseEntity.saveToTranscript = @"Case";
    caseEntity.showOnCreate = YES;
    [caseEntity.entityFieldsMaps addObjectsFromArray: caseEntityFields];
    [prechatEntities addObject:caseEntity];

    SCSPrechatEntityField* emailEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Email" label:@"Email"];
    emailEntityField.doCreate = NO;
    emailEntityField.doFind = YES;
    emailEntityField.isExactMatch = YES;

    SCSPrechatEntity* contactEntity = [[SCSPrechatEntity alloc] initWithEntityName:@"Contact"];
    contactEntity.saveToTranscript = @"Contact";
    contactEntity.showOnCreate = YES;
    contactEntity.linkToEntityName = @"Case";
    contactEntity.linkToEntityField = @"ContactId";
    [contactEntity.entityFieldsMaps addObject:emailEntityField];
    [prechatEntities addObject:contactEntity];
}

RCT_EXPORT_METHOD(configChat:(NSString *)orgId deploymentId:(NSString *)deploymentId buttonId:(NSString *)buttonId liveAgentPod:(NSString *)liveAgentPod suppliedName:(NSString *)suppliedName)
{
    chatConfiguration =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod: liveAgentPod
                                                 orgId: orgId
                                          deploymentId: deploymentId
                                              buttonId: buttonId];

    chatConfiguration.visitorName = suppliedName;
    [chatConfiguration.prechatFields addObjectsFromArray:prechatFields];
    [chatConfiguration.prechatEntities addObjectsFromArray:prechatEntities];

}

RCT_EXPORT_METHOD(launch:(RCTResponseSenderBlock)callback)
{
    [[SCServiceCloud sharedInstance].chat
     determineAvailabilityWithConfiguration:chatConfiguration
     completion:^(NSError *error, BOOL available) {

         if (error != nil) {
             // Handle error
         }
         else if (available) {
             [[SCServiceCloud sharedInstance].chat startSessionWithConfiguration:chatConfiguration];
         }
         else {
             // Disable button or warn user that no agents are available
             callback(@[[NSNull null]]);
         }
     }];
}

@end
