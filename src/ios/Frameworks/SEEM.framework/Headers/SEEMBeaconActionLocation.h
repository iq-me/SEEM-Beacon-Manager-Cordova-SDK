/**
 @name SEEM
 @file SEEMBeaconActionLocation.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>

/**
 The SEEMBeaconActionLocation class represents a location with a radius in which it is allowed to trigger the action.
 */
@interface SEEMBeaconActionLocation : NSObject

/**
 The latitude for the area in which it is allowed to trigger the action.
 @since 1.0.1
 */
@property (nonatomic, strong) NSNumber *latitude;

/**
 The longitude for the area in which it is allowed to trigger the action.
 @since 1.0.1
 */
@property (nonatomic, strong) NSNumber *longitude;

/**
 The radius for the area in which it is allowed to trigger the action.
 @since 1.0.1
 */
@property (nonatomic, strong) NSNumber *radius;

@end
