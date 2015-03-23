/**
 @name SEEM
 @file CLBeacon+SEEMBeacon.h
 @copyright Glanzkinder GmbH
 */


#import <CoreLocation/CoreLocation.h>


@class SEEMBeacon;


/**
 This category expands the methods from CLBeacon.
 */
@interface CLBeacon (SEEMBeacon)

/**
 Convert the CLBeacon object to SEEMBeacon.
 @return You get the casted beacon.
 @since 1.0
 */
- (SEEMBeacon *)SEEMBeacon;

@end
