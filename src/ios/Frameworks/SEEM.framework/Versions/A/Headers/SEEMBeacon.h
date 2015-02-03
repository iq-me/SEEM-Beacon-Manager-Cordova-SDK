/**
 @name SEEM
 @file SEEMBeacon.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class CLBeacon;
@class SEEMBeaconRegion;


/**
 The SEEMBeacon class represents a beacon that was encountered during region monitoring. You do not create instances of this class directly. The SEEMBeaconListener object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
 */
@interface SEEMBeacon : NSObject <NSCoding>

/**
 The UUID of the beacon.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSString *uuid;

/**
 The most significant value in the beacon.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSNumber *major;

/**
 The least significant value in the beacon.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSNumber *minor;

/**
 The relative distance to the beacon. 
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *proximity;

/**
 The received signal strength of the beacon, measured in decibels.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *rssi;

/**
 The accuracy of the proximity value, measured in meters from the beacon.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *accuracy;

/** @cond INTERNAL */
/**
 Initializes and returns a beacon object from a CLBeacon object.
 @param beacon The CLBeacon object.
 @since 1.0
 */
- (id)initWithCLBeacon:(CLBeacon *)beacon;
/** @endcond */

/** @cond INTERNAL */
/**
 Initializes and returns a beacon object with the specified UUID, major value, and minor value.
 @param uuid The UUID of the beacon.
 @param major The most significant value in the beacon.
 @param minor The least significant value in the beacon.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor;
/** @endcond */

/**
 Returns a Boolean value that indicates whether the beacon object and another beacon object are equal.
 @param beacon The other beacon object with which to compare the beacon object.
 @return YES if both beacon objects are equal; otherwise, NO.
 @since 1.0
 */
- (BOOL)isEqualToBeacon:(SEEMBeacon *)beacon;

/**
 Returns a Boolean value that indicates whether the beacon object is included in a region or not.
 @param region The region to check.
 @return YES if the beacon is in region; otherwise, NO.
 */
- (BOOL)inRegion:(SEEMBeaconRegion *)region;

@end
