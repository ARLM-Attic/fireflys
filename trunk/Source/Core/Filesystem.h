#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

namespace Fireflys
{
	class Archive;

	class FF_API FileSystem
	{
	public:
		virtual Archive* Open(const String& filepath) = 0;
		virtual void Close(const String& filepath) = 0;
	};
}

#endif // __FILESYSTEM_H__