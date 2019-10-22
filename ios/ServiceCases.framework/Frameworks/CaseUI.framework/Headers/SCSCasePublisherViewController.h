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

NS_ASSUME_NONNULL_BEGIN

/**
 Possible result types for the case publisher view controller.
 
 This value is used by the `SCSCasePublisherViewControllerDelegate` protocol method.
 */
typedef NS_ENUM(NSInteger, SCSCasePublisherResult) {
    /**
     * The user canceled the case publisher.
     */
    SCSCasePublisherResultCancelled = 0,
    /**
     * A case was successfully created.
     */
    SCSCasePublisherResultCaseCreated,
    /**
     * An error was received while creating a case.
     */
    SCSCasePublisherResultError
};

@class SCSCasePublisherViewController;

/**
 Delegate protocol used to receive events about the actions performed by the 
 case publisher view controller.
 
 @see `SCSCasePublisherViewController`
 */
@protocol SCSCasePublisherViewControllerDelegate <NSObject>

@optional

/**
 Tells the delegate when the case is submitted.
 If the submission failed, this method passes the error to the delegate.
 
 @param publisher Case publisher controller sending the message.
 @param result Result of the user's action.
 @param caseId ID of the created case if one was created, and if the ID can be determined.
 @param error Error returned, if any.
 
 @see `SCSCasePublisherViewController`
 @see `SCSCasePublisherResult`
 */
- (void)casePublisher:(SCSCasePublisherViewController *)publisher didSubmitWithResult:(SCSCasePublisherResult)result withCaseId:(nullable NSString *)caseId error:(nullable NSError *)error;

/**
 Allows the delegate to hide some of the case fields from showing in the Case Publisher.
 
 @param publisher Case publisher controller sending the message.
 @param availableFields List of fields in the Case Publisher layout.
 @return Set of fields to be hidden in the Case Publisher.
 */
- (NSSet<NSString*> *)casePublisher:(SCSCasePublisherViewController *)publisher fieldsToHideFromCaseFields:(NSArray<NSString*> *)availableFields;

/**
 Allows the delegate to pass in the case field values while submitting the case.
 
 @param publisher Case publisher controller sending the message.
 @param hiddenFields Set of hidden fields in the Case Publisher.
 @return `NSDictionary` in which each entry maps the field name to the field value to be used during case submission.
 */
- (NSDictionary<NSString*, id> *)casePublisher:(SCSCasePublisherViewController *)publisher valuesForHiddenFields:(NSSet<NSString*> *)hiddenFields;

/**
 Allows the delegate to supply a custom view to display to the user when the provided result is reached.
 
 If this method is not implemented, or the result is `nil`, the case publisher will automatically provide a default value.
 The returned view will be sized as needed to fit the available space on the case publisher.

 @param publisher Case publisher controller sending the message.
 @param result    Result of the case publisher.
 @param caseId    ID of the created case if one was created, and if the ID can be determined.
 @param error     Error returned, if any.

 @return UIView instance configured for showing the result to the user, or `nil` if the default should be used.
 */
- (nullable UIView *)casePublisher:(SCSCasePublisherViewController *)publisher viewForResult:(SCSCasePublisherResult)result withCaseId:(nullable NSString *)caseId error:(nullable NSError *)error;

/**
 Allows the delegate to disable the case deflection feature in the Case Publisher. 
 By default the case deflection is enabled.
 
 @param publisher Case publisher controller sending the message.
 @return YES if the case publisher should display case deflection articles.
 */
- (BOOL)shouldEnableCaseDeflectionForPublisher:(SCSCasePublisherViewController *)publisher;

/**
 Allows the delegate to specify the case fields for which case deflection articles are displayed.
 
 @param publisher Case publisher controller sending the message.
 @param availableFields List of editable text or textarea fields in the Case Publisher layout.
 @return Set of fields to be used for  forming case deflection searchterm.
 */
- (NSSet<NSString*> *)casePublisher:(SCSCasePublisherViewController *)publisher fieldsForCaseDeflection:(NSArray<NSString*> *)availableFields;

@end

/**
 View controller that lets users create a case and submit it to Service Cloud.
 
 This controller assumes that it will be presented within an instance of `UINavigationController`.
 If you aren't pushing this controller onto a navigation controller stack, present it within
 a new navigation controller instance.
 
```
SCSCasePublisherViewController *caseController = [SCSCasePublisherViewController new];
UINavigationController *navigationController = [[UINavigationController alloc]
  initWithRootViewController:caseController];
[self presentViewController:navigationController animated:YES completion:nil];
```
 */
@interface SCSCasePublisherViewController : UIViewController

/**
 Delegate for the case publisher view controller.
 
 @see `SCSCasePublisherViewControllerDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCSCasePublisherViewControllerDelegate> *delegate;

@end

NS_ASSUME_NONNULL_END
