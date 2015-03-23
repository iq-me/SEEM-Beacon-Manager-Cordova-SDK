/**
 @name SEEM
 @file NSMutableArray+RemoveWithPredicate.h
 @copyright Glanzkinder GmbH
 */


#import <Foundation/Foundation.h>

/**
 This category provides some helpful methods to use an array.
 */
@interface NSMutableArray (RemoveWithPredicate)

/**
 This method allows to delete objects by filtering with predicate.
 @param predicate The predicate for objects to be deleted.
 @since 1.0
 */
- (void)removeObjectsWithPredicate:(NSPredicate *)predicate;

@end
