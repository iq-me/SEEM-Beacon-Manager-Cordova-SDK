/**
 @name SEEM
 @file SEEMBeaconActionList.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMConstants.h"


@class SEEMBeaconEvent;


/**
 The SEEMBeaconActionList class combines the beacon event with an action list and the etag for presenting the version of action list.
 */
@interface SEEMBeaconActionList : NSObject <NSCoding>

/**
 The beacon event from the action list.
 @since 1.0
 */
@property (nonatomic, strong) SEEMBeaconEvent *beaconEvent;

/**
 An array with all associated actions.
 @since 1.0
 */
@property (nonatomic, strong) NSMutableArray *actions;

/**
 Etag for beacon event.
 @since 1.0
 */
@property (nonatomic, strong) NSString *etag;

@end
