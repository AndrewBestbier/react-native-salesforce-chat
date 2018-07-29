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

#import <Foundation/Foundation.h>

@class SCSChat;
@class SCSChatConfiguration;
@class UNNotification;
@protocol SCSChatDelegate;

/**
 SCSChatCompletionHandler block definition

 @param error `NSError` instance describing the error.
              Error codes can be referenced from `SCSChatErrorCode`.
 
 @param scsc  The instance of `SCSChat` the block is acting on.
 */
typedef void (^SCSChatCompletionHandler)(NSError *error, __weak SCSChat *scsc);

/**
 SCSChatAvailabilityHandler block definition

 @param error     `NSError` instance describing the error. 
                  Error codes can be referenced from `SCSChatErrorCode`.
 @param available `BOOL` representing the availability of an agent to accept 
                  a chat session.
 */
typedef void (^SCSChatAvailabilityHandler)(NSError *error, BOOL available);


/**
 
 The `SCSChat` class is the main interface to the Live Agent Chat SDK.
 This object manages the flow of Chat sessions throughout the lifetime of the app.
 
 To get an instance of this class, use the `SCServiceCloud.chat` property
 on `+[SCServiceCloud sharedInstance]`.

 `SCSChat` conforms to a multicast delegate model for messaging. Any class which
 implements the `SCSChatDelegate` protocol can be added to a list of delegates to
 receive messages asynchronously.
 
 For UI-related chat features like notifications, see `SCSChatInterface`.
 
 @see `SCSChatInterface`
 */
@interface SCSChat : NSObject

///---------------------------------
/// @name Properties
///---------------------------------

/**
 A reference to the `SCSChatConfiguration` object provided to the session on start.
 */
@property (nonatomic, readonly, strong) SCSChatConfiguration *configuration;

///---------------------------------
/// @name Session Control
///---------------------------------

/**
 This method begins the process of starting a Live Agent Chat session.
 
 Equivalent to invoking `-startSessionWithConfiguration:completion:`
 and providing a `nil` block.
 
 @param config The `SCSChatConfiguration` object which represents the session configuration.
 @see `-startSessionWithConfiguration:completion:`
 */
- (void)startSessionWithConfiguration:(SCSChatConfiguration *)config;

/**
 This method begins the process of starting a Live Agent Chat session.
 
 @note Calling `-stopSession` at any point after calling 
 `-startSessionWithConfiguration:` will not necessarily terminate a session in 
 progress. Once the user has moved past the pre-chat phase, this will trigger a
 prompt asking the user if they wish to terminate the session.

 @param config  The `SCSChatConfiguration` object which represents the session 
                configuration.
 @param block   Completion block which will be executed when the session has 
                been fully connected to all services. When the block is executed 
                the session is active and waiting for an agent to join.
                The `NSError` returned in the block will be `nil` on success.
 */
- (void)startSessionWithConfiguration:(SCSChatConfiguration *)config completion:(SCSChatCompletionHandler)block;

/**
 Stops an active or connecting session.
 
 If the user has not moved past the pre-chat phase, this will immediately
 terminate the session and clean up all resources.
 
 Equivalent to invoking `-stopSessionWithCompletion:` and providing a `nil` block.

 @see `-stopSessionWithCompletion:`
 */
- (void)stopSession;

/**
 Stops an active or connecting session.

 If the user has not moved past the pre chat phase this will immediately 
 terminate the session and clean up all resources.

 @param block Completion block which will be executed when the session has 
              fully stopped, and all connected services have been torn down.
              The `NSError` returned in the block will be `nil` on success.
 */
- (void)stopSessionWithCompletion:(SCSChatCompletionHandler)block;

/**
 Queries Live Agent to determine agent availability to accept a chat session.
 
 @param config The `SCSChatConfiguration` object which represents the session configuration.
 @param block  The completion block that executes when the availability response returns.
 */
- (void)determineAvailabilityWithConfiguration:(SCSChatConfiguration *)config completion:(SCSChatAvailabilityHandler)block;

///---------------------------------
/// @name Delegate Management
///---------------------------------

/**
 Adds an instance of an `NSObject` implementing the `SCSChatDelegate` protocol 
 to the list of delegates to notify.

 @param delegate `NSObject` instance to add.
 */
- (void)addDelegate:(NSObject<SCSChatDelegate> *)delegate;

/**
 Removes an instance of an `NSObject` implementing the `SCSChatDelegate`
 protocol from the list of delegates to notify.

 @param delegate `NSObject` instance to remove.
 */
- (void)removeDelegate:(NSObject<SCSChatDelegate> *)delegate;

@end
