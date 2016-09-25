// libgraph.cpp : Defines the exported functions for the DLL application.
//

#include "libgraph.h"

// This is an example of an exported variable
libgraph_API int nlibgraph=0;

// This is an example of an exported function.
libgraph_API int fnlibgraph(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see libgraph.h for the class definition
Clibgraph::Clibgraph()
{
    return;
}
