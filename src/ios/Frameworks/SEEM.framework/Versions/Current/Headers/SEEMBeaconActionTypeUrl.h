/**
 @name SEEM
 @file SEEMBeaconActionTypeUrl.h
 @copyright Glanzkinder GmbH
 */


#import "SEEMBeaconActionType.h"


/**
 The SEEMBeaconActionTypeUrl class defines the specific attributes for an URL action.
 */
@interface SEEMBeaconActionTypeUrl : SEEMBeaconActionType

/**
 The URL string for the action.
 @since 1.0
 */
@property (nonatomic, strong) NSString *url;

/**
 If NO, then the app is exited. Otherwise, YES:
 @since 1.0
 */
@property (nonatomic, readwrite) BOOL inApp;

/**
 The URL for the action.
 @since 1.0
 */
@property (nonatomic, readonly) NSURL *absoluteUrl;

@end
