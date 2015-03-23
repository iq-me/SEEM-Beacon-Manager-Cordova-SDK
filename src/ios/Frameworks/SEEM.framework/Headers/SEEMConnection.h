/**
 @name SEEM
 @file SEEMConnection.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


#pragma mark class prototype

@class SEEMBeaconEventRequest;
@class SEEMBeaconEventResponse;
@class SEEMConnection;
@class SEEMBeaconResponse;
@class SEEMBeaconRequest;


/**
 The SEEMConnectionDelegate protocol describes methods that should be implemented by the delegate for an instance of the SEEMConnection class.
 */
@protocol SEEMConnectionDelegate <NSObject>

/**
 Sent after a SEEMConnection finishes loading a response.
 @param connection The connection has finished loading.
 @param response The response that has finished loading.
 @since 1.0.1
 */
- (void)connection:(SEEMConnection *)connection onBeaconResponse:(SEEMBeaconResponse *)response;

@end


/**
 By using a SEEMConnection object you can load the contents of the API by providing a request object. The interface for SEEMConnection is sparse, providing only the control to start asynchronous loads of a request. You perform most of your configuration on the request object itself.
 */
@interface SEEMConnection : NSObject <NSURLSessionDelegate>

/**
 The receiver’s delegate.
 @see SEEMConnectionDelegate
 @since 1.0
 */
@property (nonatomic, weak) id <SEEMConnectionDelegate> delegate;


/**
 Begins to load the data for the request.
 @param request The request for loading.
 @since 1.0.1
 */
- (void)sendBeaconRequest:(SEEMBeaconRequest *)request;

@end
