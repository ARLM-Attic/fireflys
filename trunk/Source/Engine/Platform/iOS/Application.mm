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
#include "Template.h"

#import <UIKit/UIKit.h>

using namespace Fireflys;

//-------------------------------------------------
CommandLine::CommandLine()
{
}

void CommandLine::Set(int argc, char** argv)
{
	mArgc = argc;
	mArgv = argv;
}

//-------------------------------------------------
//template <>
//SharedPtr<Application> Singleton<Application>::sApp = NULL;

Application& Application::Instance()
{
	static Application ins;
	return ins;
}

class Test
{
public:
	int a;
	
};

Application::Application()
{
	
	{
		SharedPtr<Test> p1(new Test);
		SharedPtr<Test> p2 = p1;
		*p2;
		Test* t = p2;
		
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
	wms.Increase(sizeof(int)*100);
	
	for (int i = 0; i < 100; ++i)
		wms << i;
	
	wms << String("你个2");
	wms << 3.14f;
	wms << 6u;
	
//	ReadMemorySerializer rms(wms.GetMemoryStream());
	
//	for (int i = 0; i < 100; ++i)
//	{
//		int d;
//		rms << d;
		//		std::cout << d << std::endl;
//	}
	
//	String str;
//	rms << str;
	//	std::cout << str << std::endl;		
	
}

Application::~Application()
{
}

int Application::Run(Form* form)
{
	mForm = new Form;
	
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(mCmdLine.mArgc, mCmdLine.mArgv, nil, nil);
    [pool release];
    return retVal;		
}

void Application::OnInit()
{
	if (mForm)
		mForm->OnInit();
}

void Application::OnDestroy()
{
	if (mForm)
		mForm->OnDestroy();
}

int main(int argc, char *argv[]) {	
	
	CommandLine& cmdline = Application::Instance().mCmdLine;
	cmdline.Set(argc, argv);
	
	return Application::Instance().Run(NULL);
}
