/**
 @name SEEM
 @file SEEMStore.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMConstants.h"


@class SEEMBeacon;
@class SEEMBeaconActionList;
@class SEEMBeaconEvent;


/**
 The SEEMStore is responsible for loading and storing the actions and events. The data are stored in a file in the file system of the device.
 */
@interface SEEMStore : NSObject

/**
 Save an action list.
 @param actionList The list to be saved.
 @return YES if the storing was successful. Otherwise, NO.
 @since 1.0
 */
+ (BOOL)saveActionList:(SEEMBeaconActionList *)actionList;

/**
 Load the action list for an event type form a beacon.
 @param beacon The beacon to be loaded for the action list.
 @param type The action type.
 @return The action list. If action list is not available then return nil.
 @since 1.0
 */
+ (SEEMBeaconActionList *)loadActionListForBeacon:(SEEMBeacon *)beacon andEvent:(SEEMBeaconEventType)type;

/**
 Load the action list for an beacon event.
 @param event The beacon event.
 @return The action list. If action list is not available then return nil.
 @since 1.0
 */
+ (SEEMBeaconActionList *)loadActionListForBeaconEvent:(SEEMBeaconEvent *)event;

/**
 Save the request queue.
 @param requestQueue An array with all existing requests.
 @return YES if the storing was successful. Otherwise, NO.
 @since 1.0.1
 */
+ (BOOL)saveRequestQueue:(NSArray *)requestQueue;

/**
 Load all existing requests.
 @return An array with all requests.
 @since 1.0.1
 */
+ (NSMutableArray *)loadRequestQueue;

@end
