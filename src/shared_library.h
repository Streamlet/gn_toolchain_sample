#pragma once

#ifdef _WIN32
#ifdef SHARED_LIBRARY_EXPORTING
#define SHARED_LIBRARY_API __declspec(dllexport)
#else
#define SHARED_LIBRARY_API __declspec(dllimport)
#endif
#elif
#else
#endif

SHARED_LIBRARY_API int shared_library_api();
