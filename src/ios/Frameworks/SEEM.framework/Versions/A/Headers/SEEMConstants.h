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
    SEEMBeaconEventTypeExit
} SEEMBeaconEventType;

typedef void (^BeaconAction)(SEEMBeacon *beacon, SEEMBeaconEvent *event);

#define SEEMBeaconEventTypeEnterString @"Enter"
#define SEEMBeaconEventTypeExitString @"Exit"

#define API_PATH @"/api/v1/"
#define API_URL @"api.seem-manager.com"
#define API_PORT 443

#define SEEMBeaconEventTypeToString(type) (type == SEEMBeaconEventTypeEnter ? "enter" : (type == SEEMBeaconEventTypeExit ? "exit" : "unknown"))

#define SEEMLog(args...) [SEEMLogManager log:args]

#define SEEMEnableDebugMode() [[SEEMLogManager sharedInstance] setDebugMode:YES]
#define SEEMDisableDebugMode() [[SEEMLogManager sharedInstance] setDebugMode:NO]

#define SEEM_SDK_VERSION @"1.0.3"