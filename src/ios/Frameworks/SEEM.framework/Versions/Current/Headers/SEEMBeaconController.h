/**
 @name SEEM
 @file SEEMBeaconController.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


#pragma mark class prototype

@class SEEMBeaconController;
@class SEEMBeaconRegion;
@class SEEMBeaconEvent;
@class SEEMBeacon;
@class SEEMBeaconActionTypeMessage;


#pragma mark beacon controller delegate

/**
 The SEEMBeaconControllerDelegate protocol defines methods that a delegate of a SEEMBeaconController object can optionally implement to intervene when beacons enter or exit.
 */
@protocol SEEMBeaconControllerDelegate <NSObject>

@optional

/**
 Sent after a beacon is enter.
 @param beaconController The beacon controller which has called the method.
 @param beaconEvent The information about the entered beacon.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onEnterBeacon:(SEEMBeaconEvent *)beaconEvent;

/**
 Sent after a beacon is exit.
 @param beaconController The beacon controller which has called the method.
 @param beaconEvent The information about the exited beacon.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onExitBeacon:(SEEMBeaconEvent *)beaconEvent;

/**
 Sent after a beacon proximity is changed.
 @param beaconController The beacon controller which has called the method.
 @param beaconEvent The information about the changed beacon proximity.
 @since 1.0.4
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onChangeBeaconProximity:(SEEMBeaconEvent *)beaconEvent;

/**
 Sent after a beacon get a new range.
 @param beaconController The beacon controller which has called the method.
 @param beacon The beacon with new range.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onBeaconRangeDidChanged:(SEEMBeacon *)beacon;

/**
 Sent before an event begins loading an action from backend.
 @param beaconController The beacon controller which has called the method.
 @param beaconEvent Information about the event.
 @return NSDictionary or NSArray with Information for the backend.
 @since 1.0
 */
- (id)beaconController:(SEEMBeaconController *)beaconController payloadForEvent:(SEEMBeaconEvent *)beaconEvent;

/** 
 Sent when a custom action should be called.
 @param beaconController The beacon controller which has called the method.
 @param payload Payload for event.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onCustomActionWithPayload:(id)payload beaconEvent:(SEEMBeaconEvent *)beaconEvent;

/**
 Sent when a link action should be called.
 @param beaconController The beacon controller which has called the method.
 @param url The Url the user is supposed to call up.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onLinkActionWithUrl:(NSString *)url beaconEvent:(SEEMBeaconEvent *)beaconEvent;

/**
 Sent when a message action should be called.
 @param beaconController The beacon controller which has called the method.
 @param subject The subject for the message.
 @param body The body for the message.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconController:(SEEMBeaconController *)beaconController onMessageActionWithSubject:(NSString *)subject body:(NSString *)body beaconEvent:(SEEMBeaconEvent *)beaconEvent;

@end


#pragma mark beacon controller prototype

/**
 You use the SEEMBeaconController class to embed beacon listening and event handling in your application. To do so, you simply get the SEEMBeaconController shared object and configure the api settings. You can also set the beacons to listen and call for events.
 */
@interface SEEMBeaconController : NSObject

/**
 Server port to call the client api.
 @since 1.0
 */
@property (nonatomic, readwrite) NSInteger apiPort;

/**
 Server url to call the client api.
 @since 1.0
 */
@property (nonatomic, readwrite) NSString *apiUrl;

/**
 A Boolean value determining whether the server has a valid ssl certificate.
 @since 1.0
 */
@property (nonatomic, readwrite) Boolean apiSslEnabled;

/**
 You get the api key from the SEEM manager. The api key is required for listening to beacons and communicating with the backend.
 @since 1.0
 */
@property (nonatomic, readwrite) NSString *apiKey;

/**
 The web url providing you the valid url to call the client api.
 @since 1.0
 */
@property (nonatomic, readonly) NSString *webUrl;

/**
 If YES, the UUIDs for listen get automatically from the API. Default is YES.
 @since 1.0.1
 */
@property (nonatomic, assign) BOOL autoUuidFetch;

/**
 The receiver’s delegate. See SEEMBeaconControllerDelegate protocol reference for the optional methods this delegate may implement.
 @see SEEMBeaconControllerDelegate
 @since 1.0
 */
@property (nonatomic, weak) id<SEEMBeaconControllerDelegate> delegate;

/**
 Returns a shared SEEMBeaconController object
 @since 1.0
 */
+ (id)sharedInstance;

/**
 Listen to a new beacon region with uuid, major and minor. Furthermore, you can set whether the event is allowed to call on display.
 @param uuid uuid for beacon region
 @param major major for beacon region
 @param minor minor for beacon region
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @return You get the region which was added.
 @since 1.0
 */
- (SEEMBeaconRegion *)addBeaconRegionWithUUID:(NSString *)uuid major:(NSNumber *)major minor:(NSNumber *)minor notifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Listen to a new beacon region with uuid and major. Furthermore, you can set whether the event is allowed to call on display.
 @param uuid uuid for beacon region
 @param major major for beacon region
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @return You get the region which was added.
 @since 1.0
 */
- (SEEMBeaconRegion *)addBeaconRegionWithUUID:(NSString *)uuid major:(NSNumber *)major notifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Listen to a new beacon region with uuid. Furthermore, you can set whether the event is allowed to call on display.
 @param uuid uuid for beacon region
 @param notifyEntryStateOnDisplay A Boolean indicating whether beacon notifications are sent when the device’s display is on.
 @return You get the region which was added.
 @since 1.0
 */
- (SEEMBeaconRegion *)addBeaconRegionWithUUID:(NSString *)uuid notifyEntryStateOnDisplay:(BOOL)notifyEntryStateOnDisplay;

/**
 Stop listening and remove regions from list.
 @param beaconRegion Region to remove.
 @since 1.0
 */
- (void)removeBeaconRegion:(SEEMBeaconRegion *)beaconRegion;

/**
 Stop listening and remove all regions from list.
 @since 1.0
 */
- (void)removeAllBeaconRegions;

/**
 Start listen to region.
 @param beaconRegion Region to start listening.
 @since 1.0
 */
- (void)startListeningToBeaconRegion:(SEEMBeaconRegion *)beaconRegion;

/**
 Stop listen to region.
 @param beaconRegion Region to stop listening.
 @since 1.0
 */
- (void)stopListeningToBeaconRegion:(SEEMBeaconRegion *)beaconRegion;

/**
 Stop listen to all region.
 @since 1.0
 */
- (void)stopListeningToAllBeaconRegions;

/**
 Return an array with all added regions.
 @return Array with all regions;
 @since 1.0
 */
- (NSArray *)getAllBeaconRegions;

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
- (NSArray *)getAllVisibleBeaconsForBeaconRegion:(SEEMBeaconRegion *)beaconRegion;


@end
