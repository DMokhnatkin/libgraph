#pragma once

// Following macro ifdef is used to define special symbol
// for dynamic library on Windows.
#ifdef _WIN32
#ifdef libgraph_EXPORTS
#define libgraph_API __declspec(dllexport)
#else
#define libgraph_API __declspec(dllimport)
#endif
#else
#define libgraph_API
#endif
