//
//  GreetingsManager.h
//  universal-framework
//
//  Created by Muhammed Yerlikaya on 10.08.2020.
//  Copyright © 2020 gurhub. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GreetingsManager : NSObject

/**
 *
 * Gets the Singleton instance
 *
 */
+ (instancetype)shared;

/**
 *
 * Name for the Greetings!
 *
 */
@property (nonatomic, retain) NSString *name;

/**
*
* The Greetings on the terminal.
*
*/
+ (NSString*)greetings;

@end

NS_ASSUME_NONNULL_END
