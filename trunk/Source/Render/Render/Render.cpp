// render.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "render.h"


// This is an example of an exported variable
RENDER_API int nrender=0;

// This is an example of an exported function.
RENDER_API int fnrender(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see render.h for the class definition
Crender::Crender()
{
	return;
}
