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
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatBotFooterMenu;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatBotAvatar;

// Deprecated mappings
#define SCS_API_DEPRECATED_WITH_REPLACEMENT(__name) __API_DEPRECATED_WITH_REPLACEMENT(__name, ios(1.0,1.0))

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenActionChat")
SC_EXTERN NSString * const kSCAppearanceChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatAgentAvatar")
SC_EXTERN NSString * const kSCAppearanceChatAgentAvatar;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenAttachmentClipIcon")
SC_EXTERN NSString * const kSCAppearanceAttachmentClipIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenPreChatIcon")
SC_EXTERN NSString * const kSCAppearancePreChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenDropdown")
SC_EXTERN NSString * const kSCAppearanceDropdown;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIcon")
SC_EXTERN NSString * const kSCAppearanceChatConnectingIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIconLarge")
SC_EXTERN NSString * const kSCAppearanceChatConnectingIconLarge;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenErrorLarge")
SC_EXTERN NSString * const kSCAppearanceErrorLarge;

