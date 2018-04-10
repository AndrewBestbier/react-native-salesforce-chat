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
#import "SCSChatCoreDefines.h"
#import "SCSChatEndReason.h"
#import "SCSChatSessionState.h"

@class SCSChat;

/**
 The `SCSChatDelegate` protocol provides information about the Live Agent Chat 
 session.

 @see `SCSChat`
 */
@protocol SCSChatDelegate <NSObject>

@optional

/**
 Delegate method invoked when the Live Agent Chat session state changes.

 @param chat     `SCSChat` instance which invoked the method.
 @param current  The new `SCSChatSessionState` which has been set on the for 
                 the Live Agent Chat session.
 @param previous The previous `SCSChatSessionState`.
 @see `SCSChat`
 @see `SCSChatSessionState`
 */
- (void)chat:(SCSChat *)chat stateDidChange:(SCSChatSessionState)current previous:(SCSChatSessionState)previous;

/**
 Delegate method invoked when a Live Agent Session Ends.

 @param chat   `SCSChat` instance which invoked the method.
 @param reason `SCSChatEndReason` describing why the session has ended.
 @param error  `NSError` instance describing the error. 
               Error codes can be referenced from `SCSChatErrorCode`.
 @see `SCSChat`
 @see `SCSChatEndReason`
 */
- (void)chat:(SCSChat *)chat didEndWithReason:(SCSChatEndReason)reason error:(NSError *)error;

/**
 Delegate method invoked if an error is raised during a Live Agent Chat session.

 @param chat  `SCSChat` instance which invoked the error.
 @param error `NSError` instance describing the error. 
              Error codes can be referenced from `SCSChatErrorCode`.
 @see `SCSChat`
 */
- (void)chat:(SCSChat *)chat didError:(NSError *)error;

/**
 Delegate method invoked when the Live Agent Session moves in the agent queue.
 
 @param chat        `SCSChat` instance which invoked the method.
 @param position    `NSNumber` instance representing position in the queue.
 
 @see `SCSChat`
 */
- (void)chat:(SCSChat *)chat didUpdateQueuePosition:(NSNumber *)position;

@end

