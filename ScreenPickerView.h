/*
     File: ScreenPickerView.h
 
 */

#import <Cocoa/Cocoa.h>

@interface ScreenPickerView : NSView

@property (nonatomic, readwrite) CGImageRef imageRef;
@property (nonatomic) NSColor* color;

@end
