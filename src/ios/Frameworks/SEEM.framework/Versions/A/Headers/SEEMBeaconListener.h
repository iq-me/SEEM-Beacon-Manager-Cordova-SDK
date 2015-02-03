/**
 @name SEEM
 @file SEEMBeaconListener.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMConstants.h"


#pragma mark class prototype

@class SEEMBeaconEvent;
@class SEEMBeaconListener;
@class SEEMBeaconRegion;
@class SEEMBeacon;


#pragma mark - beacon listener delegate

/**
 The SEEMBeaconListenerDelegate protocol defines methods that a delegate of a SEEMBeaconListener object can optionally implement to intervene when beacons enter or exit.
 */
@protocol SEEMBeaconListenerDelegate <NSObject>

@required

/**
 Send after a beacon is enter.
 @param beaconListener The beacon controller which has called the method.
 @param beacon The beacon that was entered.
 @param event The information about the entered beacon.
 @since 1.0
 */
- (void)beaconListener:(SEEMBeaconListener *)beaconListener onEnterBeacon:(SEEMBeacon *)beacon withEvent:(SEEMBeaconEvent *)event;

/**
 Send after a beacon is exit.
 @param beaconListener The beacon controller which has called the method.
 @param beacon The beacon that was exit.
 @param event The information about the exited beacon.
 @since 1.0
 */
- (void)beaconListener:(SEEMBeaconListener *)beaconListener onExitBeacon:(SEEMBeacon *)beacon withEvent:(SEEMBeaconEvent *)event;

/**
 Send after a beacon get a new range.
 @param beaconListener The beacon controller which has called the method.
 @param beacon The beacon with new range.
 @since 1.0
 */
- (void)beaconListener:(SEEMBeaconListener *)beaconListener onBeaconRangeDidChanged:(SEEMBeacon *)beacon;

@end


#pragma mark - beacon listener prototype

/**
 You use the SEEMBeaconListener class to embed beacon listening in your application. To do so, you simply create a SEEMBeaconListener object, add beacon regions to this, and get enter or exit events for all added beacons.
 */
@interface SEEMBeaconListener : NSObject

/**
 The receiver’s delegate. See SEEMBeaconListenerDelegate protocol reference for the optional methods this delegate may implement.
 @see SEEMBeaconListenerDelegate
 @since 1.0
 */
@property (nonatomic, weak) id<SEEMBeaconListenerDelegate> delegate;

/**
 Set to YES if the application is in foreground. Otherwise set to NO.
 @since 1.0.3
 */
@property (nonatomic, assign) BOOL appIsActive;

/**
 Listen to a new beacon region.
 @param region The region for listening
 @return If YES, the listener had added the region. Otherwise, NO.
 @since 1.0
 */
- (BOOL)addBeaconRegion:(SEEMBeaconRegion *)region;

/**
 Stop listen to region.
 @param region Region to stop listening.
 @since 1.0
 */
- (void)removeBeaconRegion:(SEEMBeaconRegion *)region;

/**
 Stop listen to all region.
 @since 1.0
 */
- (void)removeAllBeaconRegions;

/**
 Return an array with all visible regions.
 @return Array with all regions;
 @since 1.0
 */
- (NSArray *)getAllVisibleBeaconRegions;

/**
 Return an array with all listened regions.
 @return Array with all regions.
 @since 1.0
 */
- (NSArray *)getAllMonitoredBeaconRegions;

/**
 Return an array with all visible beacons.
 @return Array with all visible beacons.
 @since 1.0
 */
- (NSArray *)getAllVisibleBeacons;

/**
 Return an array with all visible beacons for a region.
 @return Array with all visible beacons.
 @since 1.0
 */
- (NSArray *)getAllVisibleBeaconsForBeaconRegion:(SEEMBeaconRegion *)region;

/**
 Executes a handler block on enter a beacon.
 @param onEnter The handler block to execute.
 @since 1.0
 */
- (void)onEnterBeacon:(BeaconAction)onEnter;

/**
 Executes a handler block on exit a beacon.
 @param onExit The handler block to execute.
 @since 1.0
 */
- (void)onExitBeacon:(BeaconAction)onExit;

/**
 Return an array containing the objects in the receiving array for which isEqualToBeacon returns true.
 @param beacon The beacon to compare.
 @param array The array for compare with the given beacon.
 @return A new array containing all equivalent beacons.
 @since 1.0.2
 */
- (NSArray *)findBeacon:(SEEMBeacon *)beacon inArray:(NSArray *)array;

@end
