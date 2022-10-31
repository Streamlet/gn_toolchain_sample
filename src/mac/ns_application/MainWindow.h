#pragma once

#import <Cocoa/Cocoa.h>

@interface MainWindow : NSWindow {
  NSButton* button_;
}

+ (instancetype)CreateWithSize:(NSSize)size;

@end
