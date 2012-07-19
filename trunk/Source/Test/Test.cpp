// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <cassert>
#include <iostream>

#include "core.h"

using namespace Fireflys;

void TestYield()
{
	YIELD_BEGIN

	printf("a\n");

	YIELD

	printf("b\n");

	YIELD

	printf("c\n");

	YIELD

	YIELD_END

	printf("aa\n");
	printf("bb\n");
	printf("cc\n");

}

class IntEventArg : public EventArg
{

};

class Test : public Object
{
public:
	void OnTest(Object* sender, EventArg* ret)
	{		
		std::cout << "Hello Event Handler Invoke! The Type is: " << ToString() << std::endl;
		std::cout << "Object Test is Class Object or no: " << (dynamic_cast<Object*>(this) ? "Yes" : "No") << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Test test;
	std::list<TypedEventHandler<Test, Test, IntEventArg> > evtList;
	evtList.push_back(TypedEventHandler<Test, Test, IntEventArg>(&test, &Test::OnTest));
	IntEventArg arg;
	evtList.begin()->Invoke(&test, &arg);

	PropertyFactoryManager::Instance().Register("int", new PropertyFactoryInt);
	PropertyFactoryManager::Instance().Register("float", new PropertyFactoryInt);

	MemorySerializer sr;
	PropertyFactory* pf = PropertyFactoryManager::Instance().GetFactory<int>();
	assert(pf);
	Property* p = pf->Create();
	sr << *p;

	WriteMemorySerializer wms;
	wms.Increase(sizeof(int)*10000);

	for (int i = 0; i < 10000; ++i)
		wms << i;

	wms << String("Äã¸ö2");
	wms << 3.14f;
	wms << 6u;

	ReadMemorySerializer rms(wms.GetMemoryStream());

	for (int i = 0; i < 10000; ++i)
	{
		int d;
		rms << d;
		std::cout << d << std::endl;
	}

	String str;
	rms << str;
	std::cout << str << std::endl;

	while (1)
	{
		TestYield();
		Sleep(500);
	}

	return 0;
}

