/**
 @name SEEM
 @file SEEMBeaconRequest.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


/**
 SEEMBeaconRequest objects represent a load request with protocol, HTTP method, body and URL scheme.
 */
@interface SEEMBeaconRequest : NSObject <NSCoding>

/**
 You get a NSURLRequest object with all configured attributes.
 @since 1.0.1
 */
@property (nonatomic, strong, readonly) NSURLRequest *request;

/**
 You get the URL parameter.
 @since 1.0.1
 */
@property (nonatomic, strong, readonly) NSString *param;

/**
 You get the HTTP method for the request.
 @since 1.0.1
 */
@property (nonatomic, strong, readonly) NSString *method;

/**
 You get the HTTP body for the request.
 @since 1.0.1
 */
@property (nonatomic, strong, readonly) NSData *body;

/**
 You get the HTTP header variables.
 @since 1.0.1
 */
@property (nonatomic, strong, readonly) NSDictionary *header;

@end
