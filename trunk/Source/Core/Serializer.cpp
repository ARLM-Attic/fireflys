#include "Private.h"
#include "Serializer.h"
#include "Property.h"
#include "Object.h"
#include "Stream.h"


namespace Fireflys
{
	Serializer::~Serializer()
	{
	}

	MemorySerializer::MemorySerializer()
		: mCache(NULL)
	{

	}

	MemorySerializer::MemorySerializer( SharedPtr<MemoryStream>& stream )
		: mCache(stream)
	{
	}

	MemorySerializer::MemorySerializer( uint size )
	{
		Increase(size);
	}


	MemorySerializer::~MemorySerializer()
	{
	}


	Serializer& MemorySerializer::operator<<( uint& v )
	{
		return *this;
	}

	Serializer& MemorySerializer::operator<<( int& v )
	{
		return *this;
	}

	Serializer& MemorySerializer::operator<<( float& v )
	{

		return *this;
	}

	Serializer& MemorySerializer::operator<<( String& v )
	{

		return *this;
	}

	void MemorySerializer::Increase( uint size )
	{
		const uint CACHE_SIZE = 1024;

		if (NULL == mCache)
		{
			mCache = new MemoryStream(std::max(size, CACHE_SIZE));
		}		
		else if (mCache->GetLeftSize() < size)
		{
			MemoryStream* newCache = new MemoryStream((mCache->GetSize() / CACHE_SIZE + 1) * CACHE_SIZE);
			memcpy(newCache->GetBuffer(), mCache->GetBuffer(), mCache->GetValidSize());
			newCache->SetCur(mCache->GetValidSize());

			//delete mCache;
			mCache = newCache;
		}
	}

	Serializer& Serializer::operator<<( const uint& v )
	{
		return *this;
	}

	Serializer& Serializer::operator<<( const int& v )
	{
		return *this;
	}

	Serializer& Serializer::operator<<( const float& v )
	{
		return *this;
	}

	Serializer& Serializer::operator<<( const String& v )
	{
		return *this;
	}
	
	WriteMemorySerializer::~WriteMemorySerializer()
	{
	}		

	Serializer& WriteMemorySerializer::operator<<( uint& v )
	{
		Increase(sizeof(int));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( int& v )
	{
		Increase(sizeof(int));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( float& v )
	{
		Increase(sizeof(float));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( String& v )
	{
		Increase(sizeof(uint) + (v.length() + 1) * sizeof(String::size_type));
		mCache->Write(v);

		return *this;
	}


	Serializer& WriteMemorySerializer::operator<<( const uint& v )
	{
		Increase(sizeof(int));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( const int& v )
	{
		Increase(sizeof(int));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( const float& v )
	{
		Increase(sizeof(float));
		mCache->Write(v);

		return *this;
	}

	Serializer& WriteMemorySerializer::operator<<( const String& v )
	{
		Increase(sizeof(uint) + (v.length() + 1) * sizeof(String::size_type));
		mCache->Write(v);

		return *this;
	}

	ReadMemorySerializer::ReadMemorySerializer( SharedPtr<MemoryStream>& stream )
		: MemorySerializer(stream)
	{
		mCache->SetCur(0);
	}
    
    ReadMemorySerializer::~ReadMemorySerializer()
    {
        
    }

	Serializer& ReadMemorySerializer::operator<<( uint& v )
	{
		mCache->Read(v);

		return *this;
	}

	Serializer& ReadMemorySerializer::operator<<( int& v )
	{
		mCache->Read(v);

		return *this;
	}

	Serializer& ReadMemorySerializer::operator<<( float& v )
	{
		mCache->Read(v);

		return *this;
	}

	Serializer& ReadMemorySerializer::operator<<( String& v )
	{
		mCache->Read(v);

		return *this;
	}

	FF_API Serializer& operator << (Serializer& sr, Object& o)
	{
		o.Serialization(sr);

		return sr;
	}

	FF_API Serializer& operator << (Serializer& sr, Property& p)
	{
		p.Serialization(sr);

		return sr;
	}
}
