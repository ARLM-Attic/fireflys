#include "Private.h"

using namespace Fireflys;

void test()
{
	flist<int>::type intList;
	intList.push_back(1);

	flist<int64>::type intList64;
	intList64.push_back(1);

	fvector<int>::type intVector;
	intVector.push_back(1);

	fmap<fstring, int>::type intMap;
	intMap["name"] = 1;

	fmap<fwstring, int>::type wintMap;
	wintMap[L"name"] = 1;
}