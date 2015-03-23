/**
 @name SEEM
 @file SEEMBeaconActionTypeMessage.h
 @copyright Glanzkinder GmbH
 */


#import "SEEMBeaconActionType.h"


/**
 The SEEMBeaconActionTypeMessage class defines the specific attributes for a message action.
 */
@interface SEEMBeaconActionTypeMessage : SEEMBeaconActionType

/**
 The subject for the message.
 @since 1.0
 */
@property (nonatomic, strong) NSString *subject;

/**
 The body for the message.
 @since 1.0
 */
@property (nonatomic, strong) NSString *body;

/**
 YES if it is sent as local message. NO if the developer must define the sending process.
 @since 1.0
 */
@property (nonatomic, readwrite) BOOL isLocalPush;

@end
