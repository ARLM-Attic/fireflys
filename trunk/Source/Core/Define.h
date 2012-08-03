#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>

namespace Fireflys
{
	// base type defines
	typedef unsigned char uchar;
	typedef unsigned char byte;
	typedef unsigned short ushort;
	typedef unsigned int uint;
	typedef long long int64;
	typedef unsigned long long uint64;

	typedef void* fhandle;
}

#include "allocator.h"

namespace Fireflys
{
	typedef std::string String;
}

#ifdef _WIN32
#	pragma warning(disable:4251)

#else
#	define FF_API
#	include <typeinfo>
#endif


#endif // __DEFINE_H__
