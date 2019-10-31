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
#import <CaseCore/CaseCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface SCCaseInterface (CaseUI)

/**
 Controls the visibility of the case publisher interface, with an optional animation.
 This method shows the case publisher UI for guest users and shows the case 
 list UI for authenticated users.

 @param interfaceVisible `YES` to make the appearance visible, otherwise it will be hidden.
 @param animated         `YES` to animate, otherwise `NO`.
 @param completionBlock  Optional block to invoke when the interface change is completed.
 
 @see `-showCreateCasePublisher:completion:`
 */
- (void)setInterfaceVisible:(BOOL)interfaceVisible animated:(BOOL)animated completion:(nullable dispatch_block_t)completionBlock;

/**
 Indicates whether or not the case publisher interface is currently visible.  
 Setting this value will present or dismiss the interface in an unanimated fashion.
 
 @see `-setInterfaceVisible:animated:completion:`
 */
@property (nonatomic, assign, getter=isInterfaceVisible) BOOL interfaceVisible;

/**
 Shows the case publisher UI.

 @param completionBlock  Optional block to invoke when the interface is presented.
 @see `-showCreateCasePublisher:completion:`
 */
- (void)showCreateCasePublisher:(dispatch_block_t)completionBlock __deprecated_msg("Please use showCreateCasePublisher:completion: instead.");

/**
 Shows the case publisher UI.
 
 @param animated         `YES` to animate, otherwise `NO`.
 @param completionBlock  Optional block to invoke when the interface is presented.

 @see `-setInterfaceVisible:animated:completion:`
 @see `SCServiceCloud.account`
 */
- (void)showCreateCasePublisher:(BOOL)animated completion:(nullable dispatch_block_t)completionBlock;

@end

NS_ASSUME_NONNULL_END
