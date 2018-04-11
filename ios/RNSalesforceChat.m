#import "RNSalesforceChat.h"

@import ServiceCore;
@import ServiceChat;

@implementation RNSalesforceChat

NSMutableArray *prechatFields;
NSMutableArray *prechatEntities;
SCSChatConfiguration *chatConfiguration;

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(configLaunch:(NSString *)subject origin:(NSString *)origin currencyISOCode: (NSString *)currencyISOCode status: (NSString *)status contactType:(NSString *)contactType locale:(NSString *)locale partnerEngineerEmail:(NSString *)partnerEngineerEmail partnerEngineer:(NSString *)partnerEngineer suppliedName:(NSString *)suppliedName)
{
    prechatFields = [NSMutableArray array];
    prechatEntities = [NSMutableArray array];
    
    // Prechat fields
    SCSPrechatTextInputObject* subjectField = [[SCSPrechatTextInputObject alloc]
                                               initWithLabel:NSLocalizedString(@"Subject", nil)];
    subjectField.required = YES;
    subjectField.keyboardType = UIKeyboardTypeDefault;
    [prechatFields addObject:subjectField];
    SCSPrechatObject* originField = [[SCSPrechatObject alloc]
                                     initWithLabel:@"Origin" value: origin];
    [prechatFields addObject:originField];
    SCSPrechatObject* currencyISOCodeField = [[SCSPrechatObject alloc]
                                              initWithLabel:@"CurrencyISOCode" value: currencyISOCode];
    [prechatFields addObject:currencyISOCodeField];
    SCSPrechatObject* statusField = [[SCSPrechatObject alloc]
                                     initWithLabel:@"Status" value: status];
    [prechatFields addObject:statusField];
    SCSPrechatObject* contactTypeField = [[SCSPrechatObject alloc]
                                          initWithLabel:@"ContactType__c" value: contactType];
    [prechatFields addObject:contactTypeField];
    SCSPrechatObject* localeField = [[SCSPrechatObject alloc]
                                     initWithLabel:@"Locale__c" value: locale];
    [prechatFields addObject:localeField];
    SCSPrechatObject* partnerEngineerEmailField = [[SCSPrechatObject alloc]
                                                   initWithLabel:@"PartnerEngineerEmail__c" value: partnerEngineerEmail];
    [prechatFields addObject:partnerEngineerEmailField];
    SCSPrechatObject* suppliedNameField = [[SCSPrechatObject alloc]
                                           initWithLabel:@"SuppliedName" value: suppliedName];
    [prechatFields addObject:suppliedNameField];
    SCSPrechatObject* partnerEngineerField = [[SCSPrechatObject alloc]
                                              initWithLabel:@"PartnerEngineerRef__c" value: partnerEngineer];
    [prechatFields addObject:partnerEngineerField];
    
    // Prechat entities
    SCSPrechatEntityField* subjectEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Subject" label:@"Subject"];
    SCSPrechatEntity* subjectEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"Subject"];
    [subjectEntity.entityFieldsMaps addObject:subjectEntityField];
    [prechatEntities addObject: subjectEntity];
    subjectEntity.saveToTranscript = @"Case";
    subjectEntity.linkToEntityField = @"Subject";
    
    SCSPrechatEntityField* originEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Origin" label:@"Origin"];
    SCSPrechatEntity* originEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"Origin"];
    [originEntity.entityFieldsMaps addObject:originEntityField];
    [prechatEntities addObject: originEntity];
    originEntity.saveToTranscript = @"Case";
    originEntity.linkToEntityField = @"Origin";
    
    
    SCSPrechatEntityField* currencyISOCodeEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"CurrencyISOCode" label:@"CurrencyISOCode"];
    SCSPrechatEntity* currencyISOCodeEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"CurrencyISOCode"];
    [currencyISOCodeEntity.entityFieldsMaps addObject:currencyISOCodeEntityField];
    [prechatEntities addObject: currencyISOCodeEntity];
    currencyISOCodeEntity.saveToTranscript = @"Case";
    currencyISOCodeEntity.linkToEntityField = @"CurrencyISOCode";
    
    SCSPrechatEntityField* statusEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Status" label:@"Status"];
    SCSPrechatEntity* statusEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"Status"];
    [statusEntity.entityFieldsMaps addObject:statusEntityField];
    [prechatEntities addObject: statusEntity];
    statusEntity.saveToTranscript = @"Case";
    statusEntity.linkToEntityField = @"Status";
    
    SCSPrechatEntityField* contactTypeEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"ContactType__c" label:@"ContactType__c"];
    SCSPrechatEntity* contactTypeEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"ContactType__c"];
    [contactTypeEntity.entityFieldsMaps addObject:contactTypeEntityField];
    [prechatEntities addObject: contactTypeEntity];
    contactTypeEntity.saveToTranscript = @"Case";
    contactTypeEntity.linkToEntityField = @"ContactType__c";
    
    SCSPrechatEntityField* localeEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"Locale__c" label:@"Locale__c"];
    SCSPrechatEntity* localeEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"Locale__c"];
    [localeEntity.entityFieldsMaps addObject:localeEntityField];
    [prechatEntities addObject: localeEntity];
    localeEntity.saveToTranscript = @"Case";
    localeEntity.linkToEntityField = @"Locale__c";
    
    SCSPrechatEntityField* partnerEngineerEmailEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"PartnerEngineerEmail__c" label:@"PartnerEngineerEmail__c"];
    SCSPrechatEntity* partnerEngineerEmailEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"PartnerEngineerEmail__c"];
    [partnerEngineerEmailEntity.entityFieldsMaps addObject:partnerEngineerEmailEntityField];
    [prechatEntities addObject: partnerEngineerEmailEntity];
    partnerEngineerEmailEntity.saveToTranscript = @"Case";
    partnerEngineerEmailEntity.linkToEntityField = @"PartnerEngineerEmail__c";
    
    SCSPrechatEntityField* suppliedNameEntityField = [[SCSPrechatEntityField alloc] initWithFieldName: @"SuppliedName" label:@"SuppliedName"];
    SCSPrechatEntity* suppliedNameEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"SuppliedName"];
    [suppliedNameEntity.entityFieldsMaps addObject:suppliedNameEntityField];
    [prechatEntities addObject: suppliedNameEntity];
    suppliedNameEntity.saveToTranscript = @"Case";
    suppliedNameEntity.linkToEntityField = @"SuppliedName";
    
    SCSPrechatEntityField* partnerEngineerEntityField = [[SCSPrechatEntityField alloc] initWithFieldName:@"PartnerEngineerRef__c" label:@"PartnerEngineerRef__c"];
    SCSPrechatEntity* partnerEngineerEntity = [[SCSPrechatEntity alloc] initWithEntityName: @"PartnerEngineerRef__c"];
    [partnerEngineerEntity.entityFieldsMaps addObject:partnerEngineerEntityField];
    partnerEngineerEntity.saveToTranscript = @"Case";
    partnerEngineerEntity.linkToEntityField = @"PartnerEngineerRef__c";
    [prechatEntities addObject: partnerEngineerEntity];
}

RCT_EXPORT_METHOD(configChat:(NSString *)orgId deploymentId:(NSString *)deploymentId buttonId: (NSString *) buttonId: (NSString *) liveAgentPod)
{
    chatConfiguration =
    [[SCSChatConfiguration alloc] initWithLiveAgentPod: liveAgentPod
                                                 orgId: orgId
                                          deploymentId: deploymentId
                                              buttonId: buttonId];
    
    [chatConfiguration.prechatFields addObjectsFromArray:prechatFields];
    [chatConfiguration.prechatEntities addObjectsFromArray: prechatEntities];
    
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

