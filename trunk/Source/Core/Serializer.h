#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Template.h"

namespace Fireflys
{
	class Object;
	class Property;

	class FF_API Serializer
	{
	public:
		virtual ~Serializer();
		
		virtual Serializer& operator << (uint& v) = 0;

		virtual Serializer& operator << (int& v) = 0;

		virtual Serializer& operator << (float& v) = 0;

		virtual Serializer& operator << (String& v) = 0;

		virtual Serializer& operator << (const uint& v);

		virtual Serializer& operator << (const int& v);

		virtual Serializer& operator << (const float& v);

		virtual Serializer& operator << (const String& v);

	};

	class MemoryStream;
	class FF_API MemorySerializer : public Serializer
	{
	public:
		MemorySerializer();

		MemorySerializer(uint size);

		MemorySerializer(SharedPtr<MemoryStream>& stream);

		~MemorySerializer();

		void Increase(uint size);

		virtual Serializer& operator << (uint& v);

		virtual Serializer& operator << (int& v);

		virtual Serializer& operator << (float& v);

		virtual Serializer& operator << (String& v);

		SharedPtr<MemoryStream>& GetMemoryStream() { return mCache; }

	protected:
		SharedPtr<MemoryStream> mCache;
	};

	class FF_API WriteMemorySerializer : public MemorySerializer
	{
	public:
		~WriteMemorySerializer();
		
		virtual Serializer& operator << (uint& v);

		virtual Serializer& operator << (int& v);

		virtual Serializer& operator << (float& v);

		virtual Serializer& operator << (String& v);

		virtual Serializer& operator << (const uint& v);

		virtual Serializer& operator << (const int& v);

		virtual Serializer& operator << (const float& v);

		virtual Serializer& operator << (const String& v);
	};

	class FF_API ReadMemorySerializer : public MemorySerializer
	{
	public:
		ReadMemorySerializer(SharedPtr<MemoryStream>& stream);
        ~ReadMemorySerializer();

		virtual Serializer& operator << (uint& v);

		virtual Serializer& operator << (int& v);

		virtual Serializer& operator << (float& v);

		virtual Serializer& operator << (String& v);
	};

	FF_API Serializer& operator << (Serializer& sr, Object& o);

	FF_API Serializer& operator << (Serializer& sr, Property& p);
}

#endif // __SERIALIZER_H__