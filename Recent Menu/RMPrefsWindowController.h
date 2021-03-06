//
//  RMPrefsWindowController.h
//  Recent Menu
//
//  Created by Tim Schröder on 09.02.11.
//  Copyright 2011 Tim Schröder. All rights reserved.
//
//  This class is partly based on Dave Batton's DBPrefsWindowController
//  http://www.mere-mortal-software.com/blog/details.php?d=2007-03-11

#import <Cocoa/Cocoa.h>
#import "SRRecorderControl.h"
#import "RMFilterFormatter.h"


@interface RMPrefsWindowController : NSWindowController <NSAnimationDelegate, NSToolbarDelegate, NSWindowDelegate> {
	NSMutableArray *toolbarIdentifiers;
	NSMutableDictionary *toolbarViews;
	NSMutableDictionary *toolbarItems;
	
	IBOutlet NSView *generalPrefsView;
	IBOutlet NSView *advancedPrefsView;
	IBOutlet NSView *queryPrefsView;
	IBOutlet NSArrayController *queryArrayController;
	IBOutlet NSTableView *queryTable;
    IBOutlet SRRecorderControl *recorderControl;
    IBOutlet NSButton *accessButton;
    IBOutlet NSSegmentedControl *launchAtLoginButton;
    IBOutlet NSTextField *accessLabel;
    
    IBOutlet NSPopover *popover;
    IBOutlet NSTextField *popoverMessageField;
		
	NSView *contentSubview;
	NSViewAnimation *viewAnimation;
    
  //  IBOutlet NSTextField *filterTextField;
}

+ (RMPrefsWindowController *)sharedPrefsWindowController;

- (void)setupToolbar;
- (void)addView:(NSView *)view label:(NSString *)label image:(NSImage *)image;

- (IBAction) showWindow:(id)sender;
- (IBAction) addQuery:(id)sender;
- (IBAction) removeQuery:(id)sender;

-(void)showGeneralPrefsPane;
-(NSWindow*)prefsWindow;
-(void)setAccessButtonTitleToRevoke;
-(void)setAccessButtonTitleToGrant;
-(IBAction)toggleAccess:(id)sender;
-(IBAction)toggleLaunchAtLogin:(id)sender;
-(void)showNeedsAccessRightsAlert;

- (void)displayViewForIdentifier:(NSString *)identifier animate:(BOOL)animate;
- (void)crossFadeView:(NSView *)oldView withView:(NSView *)newView;
- (NSRect)frameForView:(NSView *)view;

- (BOOL)shortcutRecorder:(SRRecorderControl *)aRecorder isKeyCode:(NSInteger)keyCode andFlagsTaken:(NSUInteger)flags reason:(NSString **)aReason;
- (void)shortcutRecorder:(SRRecorderControl *)aRecorder keyComboDidChange:(KeyCombo)newKeyCombo;


@end
