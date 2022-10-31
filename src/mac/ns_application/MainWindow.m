#import "MainWindow.h"

@interface MyView : NSView
@end

@implementation MyView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

    [[NSColor colorWithSRGBRed:1.0 green:1.0 blue:0 alpha:0.5] set];
    NSRectFill(self.frame);

    NSFont *font = [NSFont systemFontOfSize:20.0];
    NSSize szView = self.frame.size;
    NSRect rcText = NSMakeRect(0,
                               (szView.height - font.pointSize) / 2,
                               szView.width,
                               font.pointSize);

    NSMutableParagraphStyle *style = [[NSMutableParagraphStyle alloc] init];
    style.alignment = NSTextAlignmentCenter;
    NSMutableDictionary *attr = [[NSMutableDictionary alloc] init];
    [attr setValue:style forKey:NSParagraphStyleAttributeName];
    [attr setValue:font forKey:NSFontAttributeName];

    NSString *text = @"Hello, world!";
    [text drawInRect:rcText withAttributes:attr];
}

@end

@implementation MainWindow

+ (instancetype)CreateWithSize:(NSSize)size {
    NSRect rc = NSMakeRect(0, 0, size.width, size.height);
    NSUInteger uiStyle = NSWindowStyleMaskClosable |
                         NSWindowStyleMaskMiniaturizable |
                         NSWindowStyleMaskResizable |
                         NSWindowStyleMaskTitled;
    NSBackingStoreType backingStoreStyle = NSBackingStoreBuffered;
    MainWindow* window = [[super alloc] initWithContentRect:rc
                                                styleMask:uiStyle
                                                backing:backingStoreStyle
                                                defer:NO];

    [window center];
    [window setTitle:@"MacAppHelloWorld"];
    [window setContentView:[[MyView alloc] init]];

    window->button_ = [NSButton buttonWithTitle:@"Click Me" target:window action:nil];
    [window->button_ setAction:@selector(buttonClick:)];
    [window.contentView addSubview:window->button_];
    
    [[NSNotificationCenter defaultCenter] addObserver:window selector:@selector(windowDidResize:) name:NSWindowDidResizeNotification object:window];
    [window resizeButton];

    [[NSNotificationCenter defaultCenter] addObserver:window selector:@selector(windowWillClose:) name:NSWindowWillCloseNotification object:window];
    
    [window initMenu];

    return window;
}

- (void) initMenu {
    NSMenuItem *menuApp = [[NSMenuItem alloc] init];
    menuApp.submenu = [[NSMenu alloc] init];

    NSMenuItem *menuAppAbout = [[NSMenuItem alloc] initWithTitle:@"About"
                                                           action:@selector(onAppAbout:)
                                                           keyEquivalent:@""];
    [menuAppAbout setTarget:self];
    NSMenuItem *menuAppQuit = [[NSMenuItem alloc] initWithTitle:@"Quit"
                                                           action:@selector(onAppQuit:)
                                                           keyEquivalent:@"q"];
    [menuApp.submenu addItem:menuAppAbout];
    [menuApp.submenu addItem:[NSMenuItem separatorItem]];
    [menuApp.submenu addItem:menuAppQuit];

    NSApplication *app = [NSApplication sharedApplication];
    app.mainMenu = [[NSMenu alloc] init];
    [app.mainMenu addItem:menuApp];
}

- (void) resizeButton {
    button_.frame = NSMakeRect((self.frame.size.width - button_.frame.size.width) / 2,
                               (self.frame.size.height - button_.frame.size.height) / 4,
                               button_.frame.size.width,
                               button_.frame.size.height);
}

- (void)windowDidResize:(NSNotification *)notification {
    [self resizeButton];
}

- (void)windowWillClose:(NSNotification *)notification {
    [NSApp terminate:self];
}

- (void)buttonClick:(id)sender {
    CFOptionFlags result;
    CFUserNotificationDisplayAlert(0,
                                   kCFUserNotificationNoteAlertLevel,
                                   nil,
                                   nil,
                                   nil,
                                   CFSTR("Message"),
                                   CFSTR("Button Clicked!"),
                                   CFSTR("OK"),
                                   nil,
                                   nil,
                                   &result);
}

- (void) onAppAbout:(id)sender {
    CFOptionFlags result;
    CFUserNotificationDisplayAlert(0,
                                   kCFUserNotificationNoteAlertLevel,
                                   nil,
                                   nil,
                                   nil,
                                   CFSTR("About"),
                                   CFSTR("Copyright (C) Streamlet 2022. All rights reserved."),
                                   CFSTR("OK"),
                                   nil,
                                   nil,
                                   &result);
}

- (void) onAppQuit:(id)sender {
    [NSApp terminate:self];
}

@end
