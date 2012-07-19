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

// debug macros
#define fassert assert

namespace Fireflys
{

	// container defines
	template <typename T, typename A = std::allocator<T> >
	struct flist
	{
		typedef typename std::list<T, A> type;
	};

	template <typename T, typename A = std::allocator<T> >
	struct fvector
	{
		typedef typename std::vector<T, A> type;
	};

	template <typename K, typename V, typename P = std::less<K>, typename A = std::allocator<K> >
	struct fmap
	{
		typedef typename std::map<K, V, P, A> type;
	};

	// string defines
	typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > fstring;

	typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > fwstring;

	typedef std::string String;
}

#ifdef _WIN32
#	pragma warning(disable:4251)

#else
#	define FF_API
#	include <typeinfo>
#endif


#endif // __DEFINE_H__
