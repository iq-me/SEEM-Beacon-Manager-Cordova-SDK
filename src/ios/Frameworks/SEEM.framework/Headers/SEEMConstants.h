/**
 @name SEEM
 @file SEEMConstants.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>
#import "SEEMLogManager.h"

@class SEEMBeacon;
@class SEEMBeaconEvent;

typedef enum {
    SEEMBeaconEventTypeEnter = 0,
    SEEMBeaconEventTypeExit = 1,
    SEEMBeaconEventTypeFarToNear = 2,
    SEEMBeaconEventTypeNearToImmediate = 3,
    SEEMBeaconEventTypeImmediateToNear = 4,
    SEEMBeaconEventTypeNearToFar = 5
} SEEMBeaconEventType;

typedef void (^BeaconAction)(SEEMBeacon *beacon, SEEMBeaconEvent *event);

#define SEEMBeaconEventTypeEnterString @"enter"
#define SEEMBeaconEventTypeExitString @"exit"
#define SEEMBeaconEventTypeFarToNearString @"far2near"
#define SEEMBeaconEventTypeNearToImmediateString @"near2immediate"
#define SEEMBeaconEventTypeImmediateToNearString @"immediate2near"
#define SEEMBeaconEventTypeNearToFarString @"near2far"

#define API_PATH @"/api/v1/"
#define API_URL @"api.seem-manager.com"
#define API_PORT 443

#define SEEMBeaconEventTypeToString(type) (type == SEEMBeaconEventTypeEnter ? SEEMBeaconEventTypeEnterString : (type == SEEMBeaconEventTypeExit ? SEEMBeaconEventTypeExitString : (type == SEEMBeaconEventTypeFarToNear ? SEEMBeaconEventTypeFarToNearString : (type == SEEMBeaconEventTypeNearToImmediate ? SEEMBeaconEventTypeNearToImmediateString : (type == SEEMBeaconEventTypeImmediateToNear ? SEEMBeaconEventTypeImmediateToNearString : (type == SEEMBeaconEventTypeNearToFar ? SEEMBeaconEventTypeNearToFarString : @"unknown"))))))

#define SEEMLog(args...) [SEEMLogManager log:args]

#define SEEMEnableDebugMode() [[SEEMLogManager sharedInstance] setDebugMode:YES]
#define SEEMDisableDebugMode() [[SEEMLogManager sharedInstance] setDebugMode:NO]

#define SEEM_SDK_VERSION @"1.0.4"