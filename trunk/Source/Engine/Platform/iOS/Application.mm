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

Application::Application()
{
}

Application::~Application()
{
}

int Application::Run(Form* form)
{
	mForm = form;
	
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

