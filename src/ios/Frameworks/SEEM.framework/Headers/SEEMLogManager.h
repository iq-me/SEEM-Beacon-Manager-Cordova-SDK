/**
 @name SEEM
 @file SEEMLogManager.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>


/**
 The SEEMLogManager can be used for the internal logging.
 */
@interface SEEMLogManager : NSObject

/**
 Returns a shared SEEMLogManager object
 @since 1.0
 */
+ (id)sharedInstance;

/**
 Write the parameters into the log.
 @since 1.0
 */
+ (void)log:(NSString *)string, ...;

/**
 If YES, debug mode is on and it is possible to write into log. Otherwise, NO.
 @since 1.0
 */
@property (nonatomic, readwrite) BOOL debugMode;

@end
