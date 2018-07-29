//
//  SCSChatInterface.h
//  ChatUI
//
//  Created by Jeremy Wright on 5/4/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UNNotification;

/**
 The `SCSChatInterface` class gives you access to the UI-related features of chat,
 such as chat notifications.
 
 @see `SCSChat`
 */
@interface SCSChatInterface : NSObject

/**
 Pass an UNNotification to the Chat Interface to request that the chat feed maximize if required.
 The chat feed will only maximize if the notification was scheduled by the chat client.

 @param notification The UNNotification which chat will respond to.
 */
- (void)handleNotification:(UNNotification *)notification;

/**
 Determines whether or not a notification should be displayed in the foreground.
 Will return YES if the chat feed is not currently maximized.
 */
- (BOOL)shouldDisplayNotificationInForeground;

@end
