/**
 @name SEEM
 @file SEEMBeaconRequestEvent.h
 @copyright Glanzkinder GmbH
 */


#import "SEEMBeaconRequest.h"


@class SEEMBeaconEvent;


/**
 SEEMBeaconEventRequest objects represent an event load request.
 The state from the requested operation.
 <UL>
 <LI>200 &rArr; beacon found - action list</LI>
 <LI>204 &rArr; beacon found - no actions</LI>
 <LI>304 &rArr; beacon found - action list not modified</LI>
 <LI>404 &rArr; beacon unknown</LI>
 <LI>500 &rArr; error</LI>
 </UL>
 */
@interface SEEMBeaconRequestEvent : SEEMBeaconRequest

/**
 The beacon event that was called.
 @since 1.0
 */
@property (nonatomic, strong) SEEMBeaconEvent *beaconEvent;

/**
 An identification string for the used smart device. You can use [[[UIDevice currentDevice] identifierForVendor] UUIDString].
 @since 1.0
 */
@property (nonatomic, strong) NSString *appUUID;

/**
 The etag is part of HTTP. It is a mechanism that HTTP provides for cache validation, and which allows the client to make conditional requests.
 @since 1.0
 */
@property (nonatomic, strong) NSString *eTag;

/**
 You can translate any information. For example you can set a dictionary with user specific data.
 @since 1.0
 */
@property (nonatomic, strong) id payload;

@end
