/**
 @name SEEM
 @file SEEMBeaconAction.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMConstants.h"


@class SEEMBeaconAction;


/**
 The SEEMBeaconAction class represents an action with any paramters.
 */
@interface SEEMBeaconAction : NSObject <NSCoding>

/**
 Id of action.
 @since 1.0
 */
@property (nonatomic, strong) NSString *actionId;

/**
 Name of action.
 @since 1.0
 */
@property (nonatomic, strong) NSString *name;

/**
 If YES, the action can be execute on offline mode. Default is YES.
 @since 1.0
 */
@property (nonatomic, readwrite) BOOL offlineExecution;

/**
 Date marking the beginning of the action. Sample 2014-01-01
 @since 1.0
 */
@property (nonatomic, strong) NSString *validityStart;

/**
 Date marking the end of the action. Sample 2014-01-01
 @since 1.0
 */
@property (nonatomic, strong) NSString *validityEnd;

/**
 Time from which the action is valid. Sample 09:00:00
 @since 1.0
 */
@property (nonatomic, strong) NSString *periodStart;

/**
 Time defining the beginning of an action. Sample 21:00:00
 @since 1.0
 */
@property (nonatomic, strong) NSString *periodEnd;

/**
 Time between two calls of the action on the current device.
 @since 1.0
 */
@property (nonatomic, readwrite) int duration;

/**
 Maximal calls of the action on the current device.
 @since 1.0
 */
@property (nonatomic, readwrite) int maxCount;

/**
 An array with locations for the area in which it is allowed to trigger the action.
 @since 1.0.1
 */
@property (nonatomic, strong) NSArray *validLocations;

/**
 The latitude for the area in which it is allowed to trigger the action.
 @since 1.0
 @deprecated 1.0.1
 */
@property (nonatomic, strong) NSNumber *validLocationLat;

/**
 The longitude for the area in which it is allowed to trigger the action.
 @since 1.0
 @deprecated 1.0.1
 */
@property (nonatomic, strong) NSNumber *validLocationLong;

/**
 The radius for the area in which it is allowed to trigger the action.
 @since 1.0
 @deprecated 1.0.1
 */
@property (nonatomic, strong) NSNumber *validLocationRad;

/**
 Counts how many times the action is executed.
 @since 1.0
 */
@property (nonatomic, readwrite) int executionCount;

/**
 Date from the last execution.
 @since 1.0
 */
@property (nonatomic, strong) NSDate *lastExecution;

/**
 Get validityStart as NSDate.
 @since 1.0
 */
@property (nonatomic, readonly) NSDate *validityStartDate;

/**
 Get validityEnd as NSDate.
 @since 1.0
 */
@property (nonatomic, readonly) NSDate *validityEndDate;

/**
 Get periodStart as NSDateComponents.
 @since 1.0
 */
@property (nonatomic, readonly) NSDateComponents *periodStartComponents;

/**
 Get periodEnd as NSDateComponents.
 @since 1.0
 */
@property (nonatomic, readonly) NSDateComponents *periodEndComponents;

/**
 List with all added action types.
 @since 1.0
 */
@property (nonatomic, strong) NSMutableArray *types;

/**
 If it is allowed to execute on given date and time than return YES. Otherwise NO.
 @param date A date for the check.
 @since 1.0
 */
- (BOOL)allowExecutionAtDate:(NSDate *)date;

/**
 If it is allowed to execute on given coordinate than return YES. Otherwise NO.
 @param latitude The latitude of coordinate for the check.
 @param longitude The longitude of coordinate for the check.
 @since 1.0
 */
- (BOOL)allowExecutionAtLatitude:(NSNumber *)latitude andLongitude:(NSNumber *)longitude;

@end
