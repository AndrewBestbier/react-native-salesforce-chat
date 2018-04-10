/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <UIKit/UIKit.h>
#import "SCServiceCloudDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCServiceCloudDelegate;
@class SCAppearanceConfiguration;
@class SCSServiceConfiguration;
@class SFUserAccount;

/**
 Shared singleton class used as the primary access point for the Service SDK.
 
 Use the `+[SCServiceCloud sharedInstance]` class method to access the singleton
 for this class.
 You can access each of the SDK features with properties on this singleton:
 `SCServiceCloud.knowledge`, `SCServiceCloud.cases`, `SCServiceCloud.chat`,
 `SCServiceCloud.sos`.
 
 Configure the SDK using the `SCServiceCloud.serviceConfiguration` property.
 Customize the appearance of the interface using the
 `SCServiceCloud.appearanceConfiguration` property.
 */
NS_SWIFT_NAME(ServiceCloud)
@interface SCServiceCloud : NSObject

/**
 Returns the shared service cloud manager for this process.
 
 @return Initialized shared instace.
 */
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 Identifies the primary window where view controllers should be placed when
 presented.
 
 This value is automatically determined under most circumstances, but in the 
 event that a custom value needs to be set, the `primaryWindow` property can 
 be set to a specific window that should be used.
 */
@property (null_resettable, nonatomic, strong) UIWindow *primaryWindow;

/**
 The delegate for the service interface manager.
 
 @see `SCServiceCloudDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCServiceCloudDelegate> *delegate;

/**
 The appearance style to use in presented views and view controllers.
 
 The default value for this is `SCInterfaceStyleDefault`.  If this value is set 
 after the interface has already been presented, it results in the service 
 interface being dismissed.
 
 @warning We recommend that you only assign this property once in the
 lifetime of an application.  Changing interface styles at runtime may have
 unpredictable results, and the behavior is undefined.
 */
@property (nonatomic, copy) NSString *interfaceStyle;

/**
 Sets the appearance configuration for the service interface. If not specified,
 this value falls back to default values.
 
 @see `SCAppearanceConfiguration`
 */
@property (nonatomic, strong) SCAppearanceConfiguration *appearanceConfiguration;

/**
 Configuration object used to define the self-service parameters used to 
 enable with Cases and/or Knowledge features.
 
 @see `SCSServiceConfiguration`
 */
@property (nonatomic, strong) SCSServiceConfiguration *serviceConfiguration;

/**
 Mobile SDK user account instance to use for interactions with Salesforce.
 
 This property is automatically reset to a guest user account instance when 
 `nil` is assigned.
 */
@property (null_resettable, nonatomic, strong) SFUserAccount *account;

/**
 Sets the account property asynchronously, allowing authentication errors to 
 be received and processed by the caller.
 
 @note This setter requires a nonnull account object to be assigned.
 
 @param account User account object to set.
 @param completion Completion block invoked when the account information 
        has been validated.
 */
- (void)setAccount:(SFUserAccount *)account completion:(nullable void (^)(NSError * _Nullable))completion;

@end

@class SCSNotification;
@interface SCServiceCloud (Notifications)

/**
 Returns a concrete subclass of `SCSNotification` from a remote notification
 dictionary.
 
 Returns `nil` if the notification cannot be handled by the SDK.
 Use `-showInterfaceForNotification:` to show the view associated with this 
 notification.

 @param userInfo The remote notification dictionary.
 @see `-showInterfaceForNotification:`
 */
- (nullable SCSNotification*)notificationFromRemoteNotificationDictionary:(NSDictionary*)userInfo;

/**
 Shows the appropriate view related to the notification that is passed to this 
 method.
 
 Use `-notificationFromRemoteNotificationDictionary:` to convert an 
 `NSDictionary` into an `SCSNotification` object.
 
 @param notification The notification that determines what interface to show.
 @see `-notificationFromRemoteNotificationDictionary:`
 */
- (BOOL)showInterfaceForNotification:(SCSNotification*)notification;

@end

@class SCSActionManager;
@interface SCServiceCloud (ActionManager)

/**
 Access point for interacting with the floating action bar.

 @see `SCSActionManager`
 */
@property (nonatomic, strong, readonly) SCSActionManager *actions;

@end

NS_ASSUME_NONNULL_END
