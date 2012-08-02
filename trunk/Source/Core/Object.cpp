#include "Private.h"
#include "Object.h"

using namespace Fireflys;

void* Object::operator new(size_t size)
{
	return malloc(size);
}

void Object::operator delete(void* p)
{
	free(p);
}

void* Object::operator new[](size_t size)
{
	return malloc(size);
}

void Object::operator delete[](void* p)
{
	free(p);
}

Object::~Object()
{
}

uint Object::GetPropertyCount() const
{
	return mPropertys.size();
}

Property* Object::GetProperty( uint index )
{
	assert(index < mPropertys.size());

	if (index >= mPropertys.size())
		return NULL;

	return mPropertys[index];
}


void Object::Serialization( Serializer& sr )
{
	for (uint i = 0; i < mPropertys.size(); ++i)
		sr << *mPropertys[i];
}
