//
//  FireflysAppDelegate.h
//  Fireflys
//
//  Created by Adrian on 12-7-18.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FireflysViewController;

@interface FireflysAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    FireflysViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet FireflysViewController *viewController;

@end

