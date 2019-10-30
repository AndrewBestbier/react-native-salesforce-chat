#import "RNSalesforceChat.h"
//#import "AppDelegate.h"

@implementation RNSalesforceChat

NSArray *prechatFields;
NSArray *prechatEntities;
SCSChatConfiguration *chatConfiguration;
SCServiceCloud * cloud;

RCT_EXPORT_MODULE();

-(NSArray *)preChatObjects:(NSDictionary *) chatSettings userSettings: (NSDictionary *)userSettings {
    
    // Prechat objects
    NSArray * prechatObjects = @[
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
    
    return prechatObjects;
}

+(NSArray *)preChatEntityFields {
    
    // Prechat entities
    NSArray *entityFields = @[
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

    for (SCSPrechatEntityField* entityField in entityFields) {
        entityField.doCreate = YES;
    }
    
    return entityFields;
}

-(SCSPrechatEntity *) contactEntity {
    
    SCSPrechatEntityField* emailEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Email" label:@"Email"];
    emailEntityField.doCreate = NO;
    emailEntityField.doFind = YES;
    emailEntityField.isExactMatch = YES;
    
    
    // Create an entity mapping for a Contact record type
    // (All this entity stuff is only required if you
    // want to map transcript fields to other Salesforce records.)
    SCSPrechatEntity* contactEntity = [[SCSPrechatEntity alloc] initWithEntityName:@"Contact"];
    contactEntity.saveToTranscript = @"Contact";
    contactEntity.showOnCreate = YES;
    contactEntity.linkToEntityName = @"Case";
    contactEntity.linkToEntityField = @"ContactId";
    [contactEntity.entityFieldsMaps addObject:emailEntityField];
    
    return contactEntity;
}

-(SCSPrechatEntity *) caseEntity {
    
    // Create an entity mapping for a Case record type
    SCSPrechatEntity* caseEntity = [[SCSPrechatEntity alloc] initWithEntityName:@"Case"];
    caseEntity.saveToTranscript = @"Case";
    caseEntity.showOnCreate = YES;
    [caseEntity.entityFieldsMaps addObjectsFromArray:[RNSalesforceChat preChatEntityFields]];
    
    return caseEntity;
}

RCT_EXPORT_METHOD(configLaunch:(NSDictionary *)chatSettings userSettings:(NSDictionary *)userSettings)
{
    cloud = [SCServiceCloud sharedInstance];
    
    [[cloud chatCore] removeDelegate:self];
    [[cloud chatCore] addDelegate:self];
    
    prechatFields = [self preChatObjects:chatSettings userSettings:userSettings];
    prechatEntities = [[NSArray new] arrayByAddingObjectsFromArray:@[[self caseEntity], [self contactEntity]]];
}

RCT_EXPORT_METHOD(configChat:(NSString *)orgId 
                  deploymentId:(NSString *)deploymentId 
                  buttonId:(NSString *)buttonId 
                  liveAgentPod:(NSString *)liveAgentPod 
                  suppliedName:(NSString *)suppliedName)
{
    chatConfiguration =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod:liveAgentPod
                                                 orgId:orgId
                                          deploymentId:deploymentId
                                              buttonId:buttonId];

    chatConfiguration.visitorName = suppliedName;
    
    // Update config object with the pre-chat fields
    chatConfiguration.prechatFields = [[NSArray new] arrayByAddingObjectsFromArray:prechatFields];
    
    // Update config object with the entity mappings
    chatConfiguration.prechatEntities = [[NSArray new] arrayByAddingObjectsFromArray:prechatEntities];

}

RCT_EXPORT_METHOD(launch:(RCTResponseSenderBlock)callback)
{
    [[SCServiceCloud sharedInstance].chatCore determineAvailabilityWithConfiguration:chatConfiguration completion:^(NSError *error, BOOL available, NSTimeInterval estimatedWaitTime) {
        
         if (error != nil) {
            // Handle it.
            return;
         }
        
        if(available) {
            [[SCServiceCloud sharedInstance].chatUI showChatWithConfiguration:chatConfiguration showPrechat:TRUE];
            return;
        }
        
        callback(@[[NSNull null]]);
    }];
}

// SCSChatSessionDelegate
- (void)session:(id<SCSChatSession>)session didError:(NSError *)error fatal:(BOOL)fatal {
}

@end
