/**
 @name SEEM
 @file SEEMBeaconRequestQueue.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


@class SEEMBeaconRequest;
@class SEEMBeaconResponse;
@class SEEMBeaconRequestQueue;


/**
 The SEEMBeaconRequestQueueDelegate protocol describes methods that should be implemented by the delegate for an instance of the SEEMBeaconRequestQueue class.
 */
@protocol SEEMBeaconRequestQueueDelegate <NSObject>

/**
 Tells the delegate that all messages enqueued for an event have been delivered.
 @param queue The queue has finished operation.
 @param response The event response that has finished loading.
 @since 1.0.1
 */
- (void)beaconRequestQueue:(SEEMBeaconRequestQueue *)queue onReceiveResponse:(SEEMBeaconResponse *)response;

@end


/**
 The SEEMBeaconRequestQueue class regulates the execution of a set of SEEMBeaconRequest objects. After being added to a queue, an operation remains in that queue until it is task is finished. Operations within the queue (but not yet executing) are organized according to priority levels and inter-operation object dependencies and executed accordingly. An application may create multiple operation queues and submit operations to any of them.
 */
@interface SEEMBeaconRequestQueue : NSObject

/**
 The receiver’s delegate.
 @see SEEMBeaconRequestQueueDelegate
 @since 1.0.1
 */
@property (nonatomic, weak) id <SEEMBeaconRequestQueueDelegate> delegate;

/**
 Add request to queue.
 @param request The request for loading.
 @since 1.0.1
 */
- (void)addBeaconRequest:(SEEMBeaconRequest *)request;

/**
 Starts the queue.
 @since 1.0.1
 */
- (void)processQueue;

@end
