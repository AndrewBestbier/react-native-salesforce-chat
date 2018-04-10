//
//  SCSChatDefines.h
//  ChatUI
//
//  Created by Michael Nachbaur on 2/24/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

SC_EXTERN NSString * const SCSChatUILogIdentifier;

#ifndef SCSAppearanceImageToken
typedef NSString * SCSAppearanceImageToken NS_STRING_ENUM;
#endif

SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenActionChat;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatAgentAvatar;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenAttachmentClipIcon;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenPreChatIcon;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenDropdown;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatConnectingIcon;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatConnectingIconLarge;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenErrorLarge;

// Deprecated mappings
#define SCS_API_DEPRECATED_WITH_REPLACEMENT(__name) __API_DEPRECATED_WITH_REPLACEMENT(__name, ios(1.0,1.0))

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenActionChat")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenActionChat instead")
SC_EXTERN NSString * const kSCAppearanceChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatAgentAvatar")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenChatAgentAvatar instead")
SC_EXTERN NSString * const kSCAppearanceChatAgentAvatar;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenAttachmentClipIcon")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenAttachmentClipIcon instead")
SC_EXTERN NSString * const kSCAppearanceAttachmentClipIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenPreChatIcon")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenPreChatIcon instead")
SC_EXTERN NSString * const kSCAppearancePreChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenDropdown")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenDropdown instead")
SC_EXTERN NSString * const kSCAppearanceDropdown;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIcon")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenChatConnectingIcon instead")
SC_EXTERN NSString * const kSCAppearanceChatConnectingIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIconLarge")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenChatConnectingIconLarge instead")
SC_EXTERN NSString * const kSCAppearanceChatConnectingIconLarge;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenErrorLarge")
NS_SWIFT_UNAVAILABLE("Use SCSAppearanceImageTokenErrorLarge instead")
SC_EXTERN NSString * const kSCAppearanceErrorLarge;

