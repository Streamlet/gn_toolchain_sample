#import "MainWindow.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        MainWindow *window = [MainWindow CreateWithSize:NSMakeSize(480, 300)];
        [window makeKeyAndOrderFront:nil];
        [window makeMainWindow];
        [app run];
    }

    return 0;
}
