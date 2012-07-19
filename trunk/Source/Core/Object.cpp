#include "Private.h"
#include "Object.h"

using namespace Fireflys;

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
