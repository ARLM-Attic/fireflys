//
//  main.m
//  Fireflys
//
//  Created by Adrian on 12-7-18.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Engine.h"

using namespace Fireflys;

class Test
{
public:
	int a;
	
};

class MyForm : public Form
{
public:
    virtual void OnInit()
    {
        {
            SharedPtr<Test> p1(new Test);
            SharedPtr<Test> p2(p1);
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
        
        ReadMemorySerializer rms(wms.GetMemoryStream());
        
        for (int i = 0; i < 100; ++i)
        {
            int d;
            rms << d;
            //		std::cout << d << std::endl;
        }
        
        String str;
        rms << str;
        //	std::cout << str << std::endl;		

    }
};

int main(int argc, char *argv[]) {	
	
	CommandLine& cmdline = Application::Instance().mCmdLine;
	cmdline.Set(argc, argv);
	
	return Application::Instance().Run(new MyForm);
}