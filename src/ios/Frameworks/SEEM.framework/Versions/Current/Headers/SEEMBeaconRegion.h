/**
 @name SEEM
 @file SEEMBeaconRegion.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class CLBeaconRegion;


/**
 A SEEMBeaconRegion object defines a type of region that is based on the device’s proximity to a Bluetooth beacon, as opposed to a geographic location. A beacon region looks for devices whose identifying information matches the information you provide. When that device comes in range, the region triggers the delivery of an appropriate notification.
 */
@interface SEEMBeaconRegion : NSObject <NSCoding>

/**
 The UUID of the beacon being targeted. This value must not be nil.
 @since 1.0
 */
@property (nonatomic, strong) NSString *uuid;

/**
 The major value that you use to identify one or more beacons.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *major;

/**
 The minor value that you use to identify a specific beacon.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *minor;

/**
 A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
*/
@property (nonatomic, assign) BOOL notifyEntryStateOnDisplay;

/** @cond INTERNAL */
/**
 Initializes and returns a CLBeaconRegion object from self.
 @since 1.0
 */
@property (nonatomic, strong, readonly) CLBeaconRegion *CLBeaconRegion;
/** @endcond */

/** @cond INTERNAL */
/**
 Initializes and returns a region object from a CLBeaconRegion object.
 @param region The CLBeaconRegion object.
 @since 1.0
 */
- (id)initWithCLBeaconRegion:(CLBeaconRegion *)region;
/** @endcond */

/** @cond INTERNAL */
/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value, minor value and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param minor The minor value that you use to identify a specific beacon.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;
/** @endcond */

/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value, and minor value.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param minor The minor value that you use to identify a specific beacon.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid Major:(NSNumber *)major NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID and major value.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid Major:(NSNumber *)major;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @since 1.0
 */
- (id)initWithUuid:(NSString *)uuid;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value, minor value and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param minor The minor value that you use to identify a specific beacon.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value, and minor value.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param minor The minor value that you use to identify a specific beacon.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid Major:(NSNumber *)major Minor:(NSNumber *)minor;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID, major value and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid Major:(NSNumber *)major NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID and major value.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param major The major value that you use to identify one or more beacons.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid Major:(NSNumber *)major;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID and notify entry state.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid NotifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Initializes and returns a region object that targets a beacon with the specified UUID.
 @param uuid The UUID of the beacon being targeted. This value must not be nil.
 @since 1.0
 */
+ (id)beaconRegionWithUuid:(NSString *)uuid;

/**
 Returns a Boolean value that indicates whether the region object and another region object are equal.
 @param region The other region object with which to compare the region object.
 @return YES if both region objects are equal; otherwise, NO.
 @since 1.0
 */
- (BOOL)isEqualToBeaconRegion:(SEEMBeaconRegion *)region;

@end
