/**
 @name SEEM
 @file SEEMBeaconResponse.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class SEEMBeaconRequest;


/**
 SEEMBeaconResponse objects represent an load response in a manner independent of protocol and URL scheme.
 */
@interface SEEMBeaconResponse : NSObject

/**
 The request that was loaded.
 @since 1.0.1
 */
@property (nonatomic, strong) SEEMBeaconRequest *request;

/**
 The received data.
 @since 1.0.1
 */
@property (nonatomic, strong) NSData *response;

/**
 The received header dictionary.
 @since 1.0.1
 */
@property (nonatomic, strong) NSDictionary *headerFields;

/**
 The state from the requested operation.
 @since 1.0.1
 */
@property (nonatomic, readwrite) int statusCode;

@end
