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

@class SCSCaseListViewController;
@class SCSCaseDetailViewController;

/**
 Delegate protocol used to receive events about the actions performed by the 
 case list view controller.
 
 @see `SCSCaseListViewController`
 */
@protocol SCSCaseListViewControllerDelegate <NSObject>

@optional

/**
 Tells the delegate that the case list loaded.
 
 @param caseList Case list controller sending the message.
 
 @see `SCSCaseListViewController`
 */
- (void)caseListDidLoad:(SCSCaseListViewController*)caseList;

/**
 Tells the delegate when there's an error loading the case list.
 
 @param error Error associated with loading the case list view controller.
 
 @see `SCSCaseListViewController`
 */
- (void)caseList:(SCSCaseListViewController*)caseList didReceiveError:(NSError*)error;

/**
 Tells the delegate when a case is selected from the case list.
 If you've manually displayed a `SCSCaseListViewController`, then use this method
 to display `SCSCaseDetailViewController` with the `caseId` parameter.
 If you didn't manually display a `SCSCaseListViewController`, then the
 Case Detail view appears automatically.

 @param caseList Instance of the `CaseListViewController` class currently presented.
 
 @param caseId ID of the selected case.

 @see `SCSCaseListViewController`
 */
- (void)caseList:(SCSCaseListViewController*)caseList selectedCaseWithId:(NSString*)caseId;

@end

/**
 View controller that shows a list of cases for a particular user.
 
 This controller assumes that it will be presented within an instance of `UINavigationController`.
 If you aren't pushing this controller onto a navigation controller stack, present it within
 a new navigation controller instance.
 
```
SCSCaseListViewController *caseController = [SCSCaseListViewController new];
UINavigationController *navigationController = [[UINavigationController alloc]
    initWithRootViewController:caseController];
[self presentViewController:navigationController animated:YES completion:nil];
```
 
 @warning If you instantiate this view controller and display it manually, 
 you'll also need to display `SCSCaseDetailViewController`. When a user 
 selects a case from the case list, present your Case Detail view controller 
 from the `-[SCSCaseListViewControllerDelegate caseList:selectedCaseWithId:]` 
 method in your `SCSCaseListViewControllerDelegate` implementation. If you don't 
 do this, nothing will happen when a user taps on a specific case in the case list!
 */
@interface SCSCaseListViewController : UIViewController

/**
 Delegate for the case list view controller.
 
 @see `SCSCaseListViewControllerDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCSCaseListViewControllerDelegate> *delegate;

@end

NS_ASSUME_NONNULL_END
