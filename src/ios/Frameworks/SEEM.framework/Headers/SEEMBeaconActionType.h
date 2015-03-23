/**
 @name SEEM
 @file SEEMBeaconActionType.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


/**
 The SEEMBeaconActionType class defines the specific attributes for an action.
 */
@interface SEEMBeaconActionType : NSObject <NSCoding>

/**
 Execute the action.
 @return If YES, the action was executed. Otherwise, NO.
 @since 1.0
 */
- (BOOL)execute;

@end
