#include "shared_library.h"
#include <stdio.h>

SHARED_LIBRARY_API int shared_library_api() {
  return printf("Hello, world! (from shared library)\n");
}
