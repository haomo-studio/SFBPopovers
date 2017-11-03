/*
 *  Copyright (C) 2011, 2012, 2013, 2014, 2015 Stephen F. Booth <me@sbooth.org>
 *  All Rights Reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 由 胡小根 <hxg@haomo-studio.com> 重写
 */

#import <Cocoa/Cocoa.h>

// ========================================
// Positioning constants
// ========================================
typedef NS_ENUM(NSUInteger, ScoPopoverPosition) {
	ScoPopoverPositionLeft          = NSMinXEdge,
	ScoPopoverPositionRight         = NSMaxXEdge,
	ScoPopoverPositionTop           = NSMaxYEdge,
	ScoPopoverPositionBottom        = NSMinYEdge,
	ScoPopoverPositionLeftTop       = 4,
	ScoPopoverPositionLeftBottom    = 5,
	ScoPopoverPositionRightTop      = 6,
	ScoPopoverPositionRightBottom   = 7,
	ScoPopoverPositionTopLeft       = 8,
	ScoPopoverPositionTopRight      = 9,
	ScoPopoverPositionBottomLeft    = 10,
	ScoPopoverPositionBottomRight   = 11
};

// ========================================
// A class that controls display of a popover
// ========================================
@interface ScoPopover : NSResponder

// ========================================
// Properties
@property (nonatomic, assign) BOOL animates;
@property (nonatomic, assign) BOOL closesWhenPopoverResignsKey;
@property (nonatomic, assign) BOOL closesWhenApplicationBecomesInactive;

// ========================================
// Creation
- (nullable id) initWithContentView:(nonnull NSView *)contentView;
- (nullable id) initWithContentViewController:(nonnull NSViewController *)contentViewController;

// ========================================
// Geometry determination
- (ScoPopoverPosition) bestPositionInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point;

// ========================================
// Show the popover- prefer these to showWindow:
- (void) displayPopoverInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point;
- (void) displayPopoverInWindow:(nonnull NSWindow *)window atPoint:(NSPoint)point chooseBestLocation:(BOOL)chooseBestLocation;

// ========================================
// Move the popover to a new attachment point (should be currently displayed)
- (void) movePopoverToPoint:(NSPoint)point;

// ========================================
// Close the popover
- (IBAction) closePopover:(nullable id)sender;

// ========================================
// Returns the popover window
- (nonnull NSWindow *) popoverWindow;

// ========================================
// Returns YES if the popover is visible
- (BOOL) isVisible;

// ========================================
// Popover window properties

// The popover's position relative to its attachment point
- (ScoPopoverPosition) position;
- (void) setPosition:(ScoPopoverPosition)position;

// The distance between the attachment point and the popover window
- (CGFloat) distance;
- (void) setDistance:(CGFloat)distance;

// The popover's border color
- (nonnull NSColor *) borderColor;
- (void) setBorderColor:(nonnull NSColor *)borderColor;

// The width of the popover window's border
- (CGFloat) borderWidth;
- (void) setBorderWidth:(CGFloat)borderWidth;

// The radius of the popover window's border
- (CGFloat) cornerRadius;
- (void) setCornerRadius:(CGFloat)cornerRadius;

// Specifies if the popover window has an arrow pointing toward the attachment point
- (BOOL) drawsArrow;
- (void) setDrawsArrow:(BOOL)drawsArrow;

// The width of the arrow, if applicable
- (CGFloat) arrowWidth;
- (void) setArrowWidth:(CGFloat)arrowWidth;

// The height of the arrow, if applicable
- (CGFloat) arrowHeight;
- (void) setArrowHeight:(CGFloat)arrowHeight;

// If the arrow is drawn by a corner of the window, specifies whether that corner should be rounded
- (BOOL) drawRoundCornerBesideArrow;
- (void) setDrawRoundCornerBesideArrow:(BOOL)drawRoundCornerBesideArrow;

// The spacing between the edge of the popover's content view and its border
- (CGFloat) viewMargin;
- (void) setViewMargin:(CGFloat)viewMargin;

// The popover's background color
- (nonnull NSColor *) backgroundColor;
- (void) setBackgroundColor:(nonnull NSColor *)backgroundColor;

// Specifies whether the popover may be moved by dragging
- (BOOL) isMovable;
- (void) setMovable:(BOOL)movable;

// Specifies whether the popover may be resized
- (BOOL) isResizable;
- (void) setResizable:(BOOL)resizable;

@end
