/**
 @name SEEM
 @file SEEMBeaconEvent.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMConstants.h"


@class SEEMBeacon;


/**
 The SEEMBeaconEvent class represents an event that was triggered during enter or exit a beacon.
 */
@interface SEEMBeaconEvent : NSObject <NSCoding>

/**
 Initializes and returns an event object that includes a beacon with event type, execution time and user location.
 @param beacon The beacon has trigger the event.
 @param type The event type.
 @param time The execution time.
 @param latitude User location.
 @param longitude User location.
 @since 1.0
 */
- (id)initWithBeacon:(SEEMBeacon *)beacon type:(SEEMBeaconEventType)type time:(NSDate *)time latitude:(NSNumber *)latitude longitude:(NSNumber *)longitude;

/**
 Initializes and returns an event object that includes a beacon with event type and execution time.
 @param beacon The beacon has trigger the event.
 @param type The event type.
 @param time The execution time.
 @since 1.0
 */
- (id)initWithBeacon:(SEEMBeacon *)beacon type:(SEEMBeaconEventType)type time:(NSDate *)time;

/**
 Initializes and returns an event object that includes a beacon with event type, execution time and user location.
 @param beacon The beacon has trigger the event.
 @param type The event type.
 @param time The execution time.
 @param latitude User location.
 @param longitude User location.
 @since 1.0
 */
+ (id)beaconEventWithBeacon:(SEEMBeacon *)beacon type:(SEEMBeaconEventType)type time:(NSDate *)time latitude:(NSNumber *)latitude longitude:(NSNumber *)longitude;

/**
 Initializes and returns an event object that includes a beacon with event type and execution time.
 @param beacon The beacon has trigger the event.
 @param type The event type.
 @param time The execution time.
 @since 1.0
 */
+ (id)beaconEventWithBeacon:(SEEMBeacon *)beacon type:(SEEMBeaconEventType)type time:(NSDate *)time;

/**
 The beacon has triggered the event.
 @since 1.0
 */
@property (nonatomic, strong) SEEMBeacon *beacon;

/**
 The event type.
 <UL>
 <LI>SEEMBeaconEventTypeEnter</LI>
 <LI>SEEMBeaconEventTypeExit</LI>
 <LI>SEEMBeaconEventTypeFarToNearString</LI>
 <LI>SEEMBeaconEventTypeNearToImmediateString</LI>
 <LI>SEEMBeaconEventTypeImmediateToNearString</LI>
 <LI>SEEMBeaconEventTypeNearToFarString</LI>
 </UL>
 @since 1.0
 */
@property (nonatomic, assign) SEEMBeaconEventType type;

/**
 The execution time.
 @since 1.0
 */
@property (nonatomic, strong) NSDate *time;

/**
 User location.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *latitude;

/**
 User location.
 @since 1.0
 */
@property (nonatomic, strong) NSNumber *longitude;

/**
 Etag for beacon event.
 @since 1.0
 */
@property (nonatomic, strong, readonly) NSString *etag;

@end
