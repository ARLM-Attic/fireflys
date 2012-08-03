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
	class CommandLine
	{
	public:
		CommandLine();
		
		void Set(int argc, char** argv);
		
		int mArgc;
		char** mArgv;
	};
	
	class Form;
	
	class FF_API Application
	{
	public:						
		static Application& Instance();

		~Application();
				
		int Run(Form* form);
		
		void OnInit();
		
		void OnDestroy();
		
		CommandLine mCmdLine;
						
	protected:
		Application();

		SharedPtr<Form> mForm;
	};
}

#endif // __APPLICATION_H__