#include "shared_library.h"
#include <stdio.h>

int shared_library_api() {
  return printf("Hello, world! (from shared library)\n");
}
