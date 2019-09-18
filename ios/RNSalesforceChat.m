#import "RNSalesforceChat.h"

@import ServiceCore;
@import ServiceChat;

@implementation RNSalesforceChat

NSArray *prechatFields;
NSMutableArray *prechatEntities;
SCSChatConfiguration *chatConfiguration;

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(configLaunch:(NSDictionary *)chatSettings userSettings: (NSDictionary *)userSettings)
{
    prechatEntities = [NSMutableArray array];

    // Prechat fields
    prechatFields = @[
      [[SCSPrechatObject alloc] initWithLabel:@"Origin" value: chatSettings[@"origin"]],
      [[SCSPrechatObject alloc] initWithLabel:@"CurrencyISOCode" value: chatSettings[@"currencyISOCode"]],
      [[SCSPrechatObject alloc] initWithLabel:@"Status" value: chatSettings[@"status"]],
      [[SCSPrechatObject alloc] initWithLabel:@"ContactType__c" value: chatSettings[@"contactType"]],
      [[SCSPrechatObject alloc] initWithLabel:@"Locale__c" value: chatSettings[@"locale"]],
      [[SCSPrechatObject alloc] initWithLabel:@"Subject" value: chatSettings[@"subject"]],
      [[SCSPrechatObject alloc] initWithLabel:@"CanTroubleshootingbedone__c" value: chatSettings[@"canTSBeDone"]],
      [[SCSPrechatObject alloc] initWithLabel:@"ProductV2__c" value: chatSettings[@"product"]],
      [[SCSPrechatObject alloc] initWithLabel:@"EquipmentV2__c" value: chatSettings[@"equipment"]],
      [[SCSPrechatObject alloc] initWithLabel:@"Version__c" value: chatSettings[@"version"]],
      [[SCSPrechatObject alloc] initWithLabel:@"PointOfCustomerJourney__c" value: chatSettings[@"pointOfUserJourney"]],
      [[SCSPrechatObject alloc] initWithLabel:@"SuppliedName" value: userSettings[@"name"]],
      [[SCSPrechatObject alloc] initWithLabel:@"SuppliedEmail" value: userSettings[@"email"]],
      [[SCSPrechatObject alloc] initWithLabel:@"Email" value: userSettings[@"email"]],
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
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Email" label:@"Email"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"CanTroubleshootingbedone__c" label:@"CanTroubleshootingbedone__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"ProductV2__c" label:@"ProductV2__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"EquipmentV2__c" label:@"EquipmentV2__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"Version__c" label:@"Version__c"],
         [[SCSPrechatEntityField alloc] initWithFieldName:@"PointOfCustomerJourney__c" label:@"PointOfCustomerJourney__c"]
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
