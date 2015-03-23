/**
 @name SEEM
 @file SEEMBeaconUuidManager.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class SEEMBeaconResponse;


/**
 Use to manage the listening UUIDs in your application by allocating a SEEMBeaconUuidManager object and handing over the UUID response.
 */
@interface SEEMBeaconUuidManager : NSObject

/**
 Process the UUID response and create an UUID list. Furthermore, create the beacon regions and start to listen.
 @param response The response to be executed.
 @since 1.0
 */
- (void)processUuidResponse:(SEEMBeaconResponse *)response;

@end
