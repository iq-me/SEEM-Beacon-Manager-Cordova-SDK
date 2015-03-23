/**
 @name SEEM
 @file SEEMBeaconActionTypeCustom.h
 @copyright Glanzkinder GmbH
 */


#import "SEEMBeaconActionType.h"


/**
 The SEEMBeaconActionTypeCustom class defines the specific attributes for a custom action.
 */
@interface SEEMBeaconActionTypeCustom : SEEMBeaconActionType

/**
 Payload for action.
 @since 1.0
 */
@property (nonatomic, strong) id payload;

@end
