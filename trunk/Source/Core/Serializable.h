#ifndef __SERIALIZABLE_H__
#define __SERIALIZABLE_H__

namespace Fireflys
{
	class Serializer;

	class Serializable
	{
	public:
		virtual void Serialization(Serializer& sr) = 0;
	};
}

#endif // __SERIALIZABLE_H__