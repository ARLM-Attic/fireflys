#ifndef __CORE_H__
#define __CORE_H__

#include "Define.h"

#ifdef _WIN32
#	undef FF_API
#	ifdef FF_CORE_EXPORT
#		define FF_API __declspec(dllexport)
#	else
#		define FF_API __declspec(dllimport)
#	endif
#endif

#include "Yield.h"
#include "Filesystem.h"
#include "Object.h"
#include "Property.h"
#include "Serializer.h"
#include "Template.h"
#include "Stream.h"
#include "Serializer.h"

#endif // __CORE_H__