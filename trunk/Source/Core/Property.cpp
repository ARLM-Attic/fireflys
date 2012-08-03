#include "Private.h"
#include "Property.h"
#include "Template.h"

using namespace Fireflys;

bool PropertyFactoryManager::Register( const char* type, PropertyFactory* pf )
{
	PropertyFactoryMap::iterator it = mFactorys.find(type);
	if (it != mFactorys.end())
		return false;

	mFactorys[type] = pf;

	return true;
}

void PropertyFactoryManager::Unregister( const char* type )
{
	PropertyFactoryMap::iterator it = mFactorys.find(type);
	if (it == mFactorys.end())
		return;

	mFactorys.erase(it);
}

PropertyFactory* PropertyFactoryManager::GetFactory( const char* type )
{
    static SharedPtr<PropertyFactory> null;
	PropertyFactoryMap::iterator it = mFactorys.find(type);
	if (it == mFactorys.end())
		return null;

	return it->second;
}

PropertyFactoryManager& PropertyFactoryManager::Instance()
{
	static PropertyFactoryManager ins;
	return ins;
}

Property* Fireflys::PropertyFactoryInt::Create()
{
	return (Property*)new PropertyT<int>;
}

