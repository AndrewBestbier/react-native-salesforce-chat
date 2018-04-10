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

#ifndef __SCCDefines_h__
#define __SCCDefines_h__

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

SC_EXTERN NSString * const SCInterfaceStyleDefault;

// Authentication
typedef NSString * SCServiceType NS_STRING_ENUM;
SC_EXTERN SCServiceType const SCServiceTypeCases;
SC_EXTERN SCServiceType const SCServiceTypeKnowledge;

SC_EXTERN NSString * const SCServiceCloudErrorDomain;
SC_EXTERN NSString * const SCSOAuthInvalidSessionId;

// Error Domain
SC_EXTERN NSString * const SCServiceErrorDomain;

/**
 * Possible error response codes when authenticating a user with your Salesforce org.
 */
typedef NS_ENUM(NSInteger, SCServiceErrorCode) {
    /**
     * Error condition when the session has expired or is invalid.
     */
    SCServiceUserSessionExpiredOrInvalidError = 401,
    /**
     * Error condition when the request to authenticate a user is refused by the server.
     */
    SCServiceUserRequestRefusedError = 403,
    /**
     * Error condition when the requested resource is not found on the server.
     */
    SCServiceUserResourceNotFoundError = 404,
};

typedef NSString * SCSAppearanceColorToken NS_STRING_ENUM;

/// The brand primary color key, used for primary visual elements such as header colors.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandPrimary;

/// The brand secondary color key, used for action button colors.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandSecondary;

/// The color key typically used for icons or text being placed on a brand primary element.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandPrimaryInverted;

/// The color key used for actionable labels placed on brand secondary elements, such as action buttons and case submit buttons.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandSecondaryInverted;

/// The navigation background color key.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenNavbarBackground;

/// The navigation bar text/button color key.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenNavbarInverted;

/// The primary contrast color key, used for the majority of text.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastPrimary;

/// The secondary contrast color key, used for sub category header text.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastSecondary;

/// The tertiary contrast color key is a calculated value used for unselected article backgrounds, footer backgrounds, and other secondary areas.
/// The value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 10% alpha applied.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastTertiary;

/// The quaternary contrast color key is a calculated value used for the tint coloring of accessory images.
/// This value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 50% alpha applied.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastQuaternary;

/// The contrast inverted color key, used for areas where high contrast are needed.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastInverted;

/// The feedback primary color key, used to indicate success or good state.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackPrimary;

/// The feedback secondary color key, used to indicate failure or bad state.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackSecondary;

/// The feedback tertiary color key, used to for indication of non binary states.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackTertiary;

/// The overlay background brand color key, used for semi-transparent overlay colors.
SC_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenOverlay;


#ifndef SCSAppearanceImageToken
typedef NSString * SCSAppearanceImageToken NS_STRING_ENUM;
#endif

SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenClose;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenNoConnection;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenDone;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenBack;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenGenericError;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenWhiteBubble;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSubmitButtonPreviousArrow;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSubmitButtonNextArrow;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenMinimizeButton;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenError;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenNoAccess;
SC_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenCountBadgeBackground;

/// Branding text label constant names
typedef NSString * SCSAppearanceLabelToken NS_STRING_ENUM;

SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenArticleListTitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenArticleListSummary;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCategoryListTitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseFeedItemBody;

// Case branding tokens
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListTitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListDate;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListSubTitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseDetailTitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseDetailSubtitle;
SC_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseFeedTitle;

// Actions

typedef NSString * SCSAction NS_EXTENSIBLE_STRING_ENUM;

SC_EXTERN SCSAction const SCSActionCaseInterface;
SC_EXTERN SCSAction const SCSActionCasePublisher;
SC_EXTERN SCSAction const SCSActionCaseList;
SC_EXTERN SCSAction const SCSActionArticleSearch;
SC_EXTERN SCSAction const SCSActionChatInterface;

// Default sort indexes for the built-in action items.
typedef enum : NSUInteger {
    SCSActionItemDefaultSortArticleSearch = 10,
    SCSActionItemDefaultSortCaseInterface = 20,
    SCSActionItemDefaultSortChatInterface = 30,
    SCSActionItemDefaultSortSOSInterface  = 40,
} SCSActionItemDefaultSort;

// Notifications
SC_EXTERN NSString * const SCUServiceUserAccountChangedNotification;

//Remote notification payload
SC_EXTERN NSString * const SCSNotificationPayloadKeyCaseId;

// Live agent Logging
SC_EXTERN NSString * const SCServiceCloudLoggingErrorDomain;

#endif
