/**
 @name SEEM
 @file SEEMBeaconActionManager.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class SEEMBeaconEvent;
@class SEEMBeaconResponse;
@class SEEMBeaconActionManager;
@class SEEMBeaconActionType;
@class SEEMBeaconAction;


/**
 The SEEMBeaconActionManagerDelegate protocol defines methods that a delegate of a SEEMBeaconActionManager object can optionally implement to intervene when beacons enter or exit.
 */
@protocol SEEMBeaconActionManagerDelegate <NSObject>

/**
 Send when a custom action should be called.
 @param manager The action manager which has called the method.
 @param payload Payload for event.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconActionManager:(SEEMBeaconActionManager *)manager onCustomActionWithPayload:(id)payload beaconEvent:(SEEMBeaconEvent *)beaconEvent;

/**
 Send when a link action should be called.
 @param manager The action manager which has called the method.
 @param url The url the user is supposed to call up.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconActionManager:(SEEMBeaconActionManager *)manager onLinkActionWithUrl:(NSString *)url beaconEvent:(SEEMBeaconEvent *)beaconEvent;

/**
 Send when a action could not be called.
 @param manager The action manager which has called the method.
 @param type The action type whose execution failed.
 @param beaconEvent Information about the event.
 @since 1.0.2
 */
- (void)beaconActionManager:(SEEMBeaconActionManager *)manager onExecuteFailed:(SEEMBeaconActionType *)type beaconEvent:(SEEMBeaconEvent *)beaconEvent;

/**
 Send when a message action should be called.
 @param manager The action manager which has called the method.
 @param subject The subject for the message.
 @param body The body for the message.
 @param beaconEvent Information about the event.
 @since 1.0
 */
- (void)beaconActionManager:(SEEMBeaconActionManager *)manager onMessageActionWithSubject:(NSString *)subject body:(NSString *)body beaconEvent:(SEEMBeaconEvent *)beaconEvent;

@end


/**
 Use to manage and to execute the event in your application by allocating a SEEMBeaconActionManager object and handing over the event response.
 */
@interface SEEMBeaconActionManager : NSObject

/**
 The receiver’s delegate.
 @see SEEMBeaconActionManagerDelegate
 @since 1.0
 */
@property (nonatomic, weak) id <SEEMBeaconActionManagerDelegate> delegate;

/**
 Process the event response and create an action list. Furthermore, execute the actions for the explicit event.
 @param response The response to be executed.
 @since 1.0
 */
- (void)processEventResponse:(SEEMBeaconResponse *)response;

/**
 Execute the given action for beacon event. 
 @param action The action to be execute.
 @param beaconEvent Information about the event.
 @param onlineStatus The online status of the device.
 @since 1.0.2
 */
- (void)executeAction:(SEEMBeaconAction *)action beaconEvent:(SEEMBeaconEvent *)beaconEvent onlineStatus:(BOOL)onlineStatus;

/**
 Execute the given action type for beacon event.
 @param type The action type to be execute.
 @param beaconEvent Information about the event.
 @since 1.0.2
 */
- (BOOL)executeActionType:(SEEMBeaconActionType *)type beaconEvent:(SEEMBeaconEvent *)beaconEvent;

@end
