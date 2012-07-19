#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include "Object.h"

namespace Fireflys
{
	class Serializer;

	class FF_API Property
	{
	public:
		virtual void Serialization(Serializer& sr) = 0;

		String mName;
	};

	template <class T>
	class PropertyT : public Property
	{
	public:
		PropertyT()
		{
			mName = typeid(T).name();
		}

		PropertyT(const T& value)
		{
			mValue = value;
		}

		T& operator =(const T& value)
		{
			mValue = value;
			return *this;
		}

		operator T()
		{
			return mValue;
		}

		virtual void Serialization(Serializer& sr)
		{
			sr << mValue;
		}

		T mValue;
	};

	typedef std::vector<Property*> PropertyVector;

	class FF_API PropertyFactory : public Object
	{
	public:
		virtual Property* Create() = 0;
	};

	typedef std::map<std::string, PropertyFactory*> PropertyFactoryMap;

	class FF_API PropertyFactoryInt : public PropertyFactory
	{
	public:
		virtual Property* Create();
	};

	class FF_API PropertyFactoryManager
	{
	public:
		bool Register(const char* type, PropertyFactory* pf);
		void Unregister(const char* type);

		PropertyFactory* GetFactory(const char* type);

		template <class T>
		PropertyFactory* GetFactory()
		{
			const char* name = typeid(T).name();
			return GetFactory(name);
		}

		static PropertyFactoryManager& Instance(); 

	protected:
		PropertyFactoryMap mFactorys;
	};
}

#endif // __PROPERTY_H__