/**
 @name SEEM
 @file SEEMBeaconActionTypeAppLink.h
 @copyright Glanzkinder GmbH
 */


#import "SEEMBeaconActionType.h"


@class AppLink;


/**
 The SEEMBeaconActionTypeAppLink class defines the specific attributes for an AppLink action.
 */
@interface SEEMBeaconActionTypeAppLink : SEEMBeaconActionType

/**
 The AppLink object for the action.
 @since 1.0.2
 */
@property (nonatomic, strong) AppLink *appLink;

@end
