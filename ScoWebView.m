//
//  ScoWebView.m
//  ScoPopovers
//
//  Created by hm20160509 on 2017/12/17.
//  Copyright © 2017年 sbooth.org. All rights reserved.
//

#import "ScoWebView.h"

@interface ScoWebView (Private)
@end

@implementation ScoWebView

- (BOOL)acceptsFirstMouse:(nullable NSEvent *)event
{
    return YES;
}

//- (void)webView:(WebView *)sender mouseDidMoveOverElement: (NSDictionary *)elementInformation modifierFlags:(NSUInteger) modifierFlags
//{
//    if ([[NSApp currentEvent] type] == NSLeftMouseDown)
//        NSLog(@"sco-log: ScoWebView mouseDown event occurred");
//}

- (NSView*)hitTest:(NSPoint)aPoint
{
//    NSLog(@"sco-log: ScoWebView hitTest enter");
    
    NSView * clickedView = [super hitTest:aPoint];
    
    if (clickedView == nil)
    {
        clickedView = self;
    }
    
    @try {
        if(NSPointInRect([self convertPoint:aPoint fromView:nil], [self frame]))
        {
            //if the mouse is in an active area then just perform the default operation
            if([[self window] isVisible]) {
//                NSLog(@"sco-log: ScoWebView hitTest %@", [self mainFrameURL]);
//                [[self window] makeKeyWindow];
//                NSLog(@"sco-log: ScoWebView hitTest webview");
            }
        }
    }
    @catch (NSException *e){
        NSLog(@"sco-log: ScoWebView hitTest error");
    }
    @finally {
//        NSLog(@"sco-log: ScoWebView hitTest finally");
    }
    
    return clickedView;
}

@end
