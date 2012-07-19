#include "Private.h"
#include "Stream.h"

using namespace Fireflys;

MemoryStream::MemoryStream( uint size )
: mSize(size)
{
	mBuffer = new byte[size];
	mCur = mBuffer;
}

MemoryStream::~MemoryStream()
{
	delete[] mBuffer;
}

void MemoryStream::Write( const uint& data )
{
	assert(GetLeftSize() > 0);

	*(uint*)mCur = data;
	mCur += sizeof(uint);
}

void MemoryStream::Write( const int& data )
{
	assert(GetLeftSize() > 0);

	*(int*)mCur = data;
	mCur += sizeof(int);
}

void MemoryStream::Write( const float& data )
{
	assert(GetLeftSize() > 0);

	*(float*)mCur = data;
	mCur += sizeof(float);
}

void MemoryStream::Write( const String& data )
{
	assert(GetLeftSize() > 0);

	uint bytes = (data.length() + 1) * sizeof(String::size_type);
	Write(bytes);

	memcpy(mCur, data.c_str(), bytes);
	mCur += bytes;
}

void MemoryStream::Read( uint& data )
{
	assert(GetLeftSize() > 0);

	data = *(uint*)mCur;
	mCur += sizeof(uint);
}

void MemoryStream::Read( int& data )
{
	assert(GetLeftSize() > 0);

	data = *(int*)mCur;
	mCur += sizeof(int);
}

void MemoryStream::Read( float& data )
{
	assert(GetLeftSize() > 0);

	data = *(float*)mCur;
	mCur += sizeof(float);
}

void MemoryStream::Read( String& data )
{
	assert(GetLeftSize() > 0);

	uint bytes = 0;
	Read(bytes);

	uint size = bytes / sizeof(String::size_type);

	data.resize(size);

	memcpy((void*)data.c_str(), mCur, size);

	mCur += bytes;
}

uint MemoryStream::GetSize() const
{
	return mSize;
}

uint MemoryStream::GetLeftSize() const
{
	return (uint)(mBuffer + mSize - mCur);
}

uint MemoryStream::GetValidSize() const
{
	return (uint)(mCur - mBuffer);
}

byte* MemoryStream::GetBuffer()
{
	return mBuffer;
}

void MemoryStream::SetCur( uint cur )
{
	mCur = mBuffer + cur;
}
