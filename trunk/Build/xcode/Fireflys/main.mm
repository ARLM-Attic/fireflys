//
//  main.m
//  Fireflys
//
//  Created by Adrian on 12-7-18.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Application.h"

using namespace Fireflys;

int main(int argc, char *argv[]) {
    Application& app = Application::Instance();
	app.SetCommandLine(argc, argv);
	int ret = app.Run();
	return ret;
}
