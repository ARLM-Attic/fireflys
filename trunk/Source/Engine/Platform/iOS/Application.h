/*
 *  Application.h
 *  Fireflys
 *
 *  Created by Adrian on 12-7-19.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Engine.h"

namespace Fireflys
{
	class FF_API Application
	{
	public:
		Application();
		~Application();
		
		void SetCommandLine(int argc, char* argv[]);
		
		int Run();
		
		static Application& Instance();
		
	protected:
		int mArgc;
		char** mArgv;
	};
}

#endif // __APPLICATION_H__