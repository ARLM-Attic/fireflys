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
: mArgc(0)
, mArgv(NULL)
{
}

void Application::SetCommandLine(int argc, char* argv[])
{
	mArgc = argc;
	mArgv = argv;
}

Application::~Application()
{
}

int Application::Run()
{
    {
        SharedPtr<Application> p1(new Application);
        SharedPtr<Application> p2 = p1;
        *p2;
        p1->SetCommandLine(0, 0);
        Application* t = p2;
        
        if (p1 == p2 || p1 == NULL || NULL == p1 || t == p2) ;
    }
                      
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
    int retVal = UIApplicationMain(mArgc, mArgv, nil, nil);
    [pool release];
    return retVal;	
}

Application& Application::Instance()
{
	static Application ins;
	return ins;
}



