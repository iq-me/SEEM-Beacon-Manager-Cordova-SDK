/**
 @name SEEM
 @file CLBeaconRegion+SEEMBeaconRegion.h
 @copyright Glanzkinder GmbH
 */


#import <CoreLocation/CoreLocation.h>


@class SEEMBeaconRegion;
@class SEEMBeacon;


/**
 This category expands the methods from CLBeaconRegion.
 */
@interface CLBeaconRegion (SEEMBeaconRegion)

/**
 Convert the CLBeaconRegion object to SEEMBeaconRegion.
 @return You get the casted beacon.
 @since 1.0
 */
- (SEEMBeaconRegion *)SEEMBeaconRegion;

@end
