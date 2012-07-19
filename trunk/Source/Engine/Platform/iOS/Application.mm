/*
 *  Application.cpp
 *  Fireflys
 *
 *  Created by Adrian on 12-7-19.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Engine.h"
#include "Application.h"

#import <UIKit/UIKit.h>

using namespace Fireflys;

Application::Application()
: _argc(0)
, _argv(NULL)
{
}

void Application::SetCommandLine(int argc, char* argv[])
{
	_argc = argc;
	_argv = argv;
}

Application::~Application()
{
}

int Application::Run()
{
	PropertyFactoryManager::Instance().Register(typeid(int).name(), new PropertyFactoryInt);
	PropertyFactoryManager::Instance().Register(typeid(float).name(), new PropertyFactoryInt);
	
	MemorySerializer sr;
	PropertyFactory* pf = PropertyFactoryManager::Instance().GetFactory<int>();
	assert(pf);
	Property* p = pf->Create();
	sr << *p;
	
	WriteMemorySerializer wms;
	wms.Increase(sizeof(int)*10000);
	
	for (int i = 0; i < 10000; ++i)
		wms << i;
	
	wms << String("你个2");
	wms << 3.14f;
	wms << 6u;
	
	ReadMemorySerializer rms(wms.GetMemoryStream());
	
	for (int i = 0; i < 10000; ++i)
	{
		int d;
		rms << d;
		//		std::cout << d << std::endl;
	}
	
	String str;
	rms << str;
	//	std::cout << str << std::endl;		

	
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(_argc, _argv, nil, nil);
    [pool release];
    return retVal;	
}

Application& Application::Instance()
{
	static Application ins;
	return ins;
}



