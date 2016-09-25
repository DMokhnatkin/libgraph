#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the libgraph_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// libgraph_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef libgraph_EXPORTS
#define libgraph_API __declspec(dllexport)
#else
#define libgraph_API __declspec(dllimport)
#endif

// This is an example of a class exported from the libgraph.dll
class libgraph_API Clibgraph
{
public:
    Clibgraph();
    // TODO: add your methods here.
};

// This is an example of an exported variable
extern libgraph_API int nlibgraph;

// This is an example of an exported function.
libgraph_API int fnlibgraph(void);
