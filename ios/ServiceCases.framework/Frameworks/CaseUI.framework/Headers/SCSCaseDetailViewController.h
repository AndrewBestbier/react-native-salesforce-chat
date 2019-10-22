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

@class SCSCaseDetailViewController;

/**
 Delegate protocol used to receive events about the actions performed by 
 the case detail view controller.
 
 @see `SCSCaseDetailViewController`
 */
@protocol SCSCaseDetailViewControllerDelegate <NSObject>

@optional

/**
 Allows the delegate to hide some of the case fields from showing in the Case Detail.
 
 @param caseDetailController Case Detail View controller sending the message.
 @param availableFields List of fields available for display in Case Detail. The parameter is of type `NSArray<NSString*>*`.
 @return Set of fields to be hidden in the Case Detail. Return expected is of type `NSSet<NSString*>*`.
 */
- (NSSet<NSString*> *)caseDetail:(SCSCaseDetailViewController *)caseDetailController fieldsToHideFromCaseFields:(NSArray<NSString*> *)availableFields;

@end

/**
 View controller that lets users see the details for a particular case.
 
 Initialize this view controller with a case ID using 
 `-[SCSCaseDetailViewController initWithCaseId:]`.
 */
@interface SCSCaseDetailViewController : UIViewController

/**
 Initializes the `SCSCaseDetailViewController` with a case ID.
 
 @param caseId ID of the case to be displayed.
 */
- (instancetype)initWithCaseId:(NSString*)caseId;

/**
 Delegate for the case detail view controller.

 @see `SCSCaseDetailViewControllerDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCSCaseDetailViewControllerDelegate> *delegate;

@end

NS_ASSUME_NONNULL_END
