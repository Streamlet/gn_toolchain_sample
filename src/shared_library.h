#pragma once

#if defined(_WIN32)
#ifdef SHARED_LIBRARY_EXPORTING
#define SHARED_LIBRARY_API __declspec(dllexport)
#else
#define SHARED_LIBRARY_API __declspec(dllimport)
#endif
#else
#ifdef SHARED_LIBRARY_EXPORTING
#define SHARED_LIBRARY_API __attribute__((visibility("default")))
#else
#define SHARED_LIBRARY_API
#endif
#endif

SHARED_LIBRARY_API int shared_library_api();
