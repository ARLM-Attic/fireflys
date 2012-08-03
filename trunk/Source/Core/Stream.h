#ifndef __STREAM_H__
#define __STREAM_H__

namespace Fireflys
{
	class Stream
	{
	public:
        virtual ~Stream();
        
		virtual void Write(const uint& data) = 0;

		virtual void Write(const int& data) = 0;

		virtual void Write(const float& data) = 0;

		virtual void Write(const String& data) = 0;

		virtual void Read(uint& data) = 0;

		virtual void Read(int& data) = 0;

		virtual void Read(float& data) = 0;

		virtual void Read(String& data) = 0;
	};

	class FF_API MemoryStream : public Stream
	{
	public:
		MemoryStream(uint size);
		virtual ~MemoryStream();

		virtual void Write(const uint& data);

		virtual void Write(const int& data);

		virtual void Write(const float& data);

		virtual void Write(const String& data);

		virtual void Read(uint& data);

		virtual void Read(float& data);

		virtual void Read(int& data);

		virtual void Read(String& data);

		uint GetSize() const;

		uint GetLeftSize() const;

		uint GetValidSize() const;

		byte* GetBuffer();

		void SetCur(uint cur);

	protected:
		byte* mBuffer;
		byte* mCur;
		uint mSize;
	};

}

#endif // __MEMORY_STREAM_H__