/*
     File: ScreenPickerView.m
 
 */

#import "ScreenPickerView.h"

@implementation ScreenPickerView

- (NSString *)convertFloatToHex: (CGFloat) f {
    NSLog(@"%f", f);
    return [NSString stringWithFormat:@"%lX", (long) (floor(f*255.0))];
}

- (NSString *)getRedStr:(NSColor *) color {
    CGFloat f = [[self color] redComponent];
    return [self convertFloatToHex: f];
}

- (NSString *)getGreenStr:(NSColor *) color {
    CGFloat f = [[self color] greenComponent];
    return [self convertFloatToHex: f];
}

- (NSString *)getBlueStr:(NSColor *) color {
    CGFloat f = [[self color] blueComponent];
    return [self convertFloatToHex: f];
}

- (NSString *)getAlphaStr:(NSColor *) color {
    CGFloat f = [[self color] alphaComponent];
    return [self convertFloatToHex: f];
}

// @TODO 将颜色绘制到
- (void)drawColorText: (NSRect) rect {
    CGContextRef context = [[NSGraphicsContext currentContext] graphicsPort];
    
    // 写文字
    CGContextSetLineWidth(context, 1.0);
    CGContextSetRGBFillColor (context,  1, 1, 1, 1.0);
    CGFloat x = rect.size.width / 2 - 60;
    CGFloat y = rect.size.height / 2;
    NSString *colorStr = [[NSString alloc] initWithString:
                          [NSString stringWithFormat:@"R:%@, G:%@ B:%@, A:%@ ",
                           [self getRedStr:[self color]], [self getGreenStr:[self color]], [self getBlueStr:[self color]], [self getAlphaStr:[self color]]]];
    [colorStr drawInRect:CGRectMake(x, y, 160, 20) withAttributes:nil];
}

- (void)drawRect:(NSRect)rect {
    CGContextRef context = [[NSGraphicsContext currentContext] graphicsPort];
    // Clear the drawing rect.
    CGContextClearRect(context, self.bounds);

    CGFloat width = rect.size.width;
    CGFloat height = rect.size.height;

    // mask
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddEllipseInRect(path, NULL, rect);
    CGContextAddPath(context, path);
    CGContextClip(context);
    CGPathRelease(path);
    
    if (_imageRef) {
        // draw image
        CGContextSetRenderingIntent(context, kCGRenderingIntentRelativeColorimetric);
        CGContextDrawImage(context, NSRectToCGRect(self.bounds), _imageRef);
    }
    
    // draw the aperture
    CGFloat apertureSize = 6;
	CGFloat x = width / 2 - apertureSize / 2;
	CGFloat y = height / 2 - apertureSize / 2;
	CGRect apertureRect = CGRectMake(x, y, apertureSize, apertureSize);
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);
    CGContextSetShouldAntialias(context, NO);
    CGContextStrokeRect(context, apertureRect);

    // stroke outer circle
    CGContextSetShouldAntialias(context, YES);
    CGContextSetLineWidth(context, 2.0);
    CGContextStrokeEllipseInRect(context, rect);
    
    // 将颜色color绘制到界面上
    [self drawColorText: rect];
}

@end
