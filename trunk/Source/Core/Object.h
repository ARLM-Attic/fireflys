#ifndef __OBJECT_H__
#define __OBJECT_H__

namespace Fireflys
{
	class Property;
	class Serializer;

	class FF_API Object
	{
	public:
		void* operator new(size_t size);
		void operator delete(void* p);
		void* operator new[](size_t size);
		void operator delete[](void* p);
		
		virtual ~Object();
			
		virtual const char* Type()
		{
			return typeid(*this).name();
		}

		virtual const char* ToString() { return Type(); };

		uint GetPropertyCount() const;

		Property* GetProperty(uint index);

		virtual void Serialization(Serializer& sr);

	protected:
		std::vector<Property*> mPropertys;
	};
	
	class EventArg
	{

	};

	template <typename TReciver, typename TSender, typename TResult>
	class TypedEventHandler
	{
	public:
		typedef void (TReciver::*Func)(Object* sender, EventArg* ret);

		TypedEventHandler(TReciver* obj, Func func)
		{
			_obj = obj;
			_func = (Func)func;
		}

		void Invoke(TSender* sender, TResult* ret)
		{
			(_obj->*_func)(_sender, ret);
		}

		TReciver* _obj;
		TSender* _sender;
		Func	_func;
	};
}

#endif // __OBJECT_H__