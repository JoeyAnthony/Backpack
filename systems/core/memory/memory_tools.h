#pragma once
namespace memory_tools {
	size_t align_bytes(size_t num);
	template <class T> void initCopy(T* dst, T* src, int count);
	template <class T> void addressCopy(T* dst, T* srs, int count);
	template <class T> void initMove(T* dst, T* src, int count);
	template <class T> void initMove(T* dst, T* src, int count);
	template <class T> void memMove(T* dst, T* src, int count);
	template <class T> void shift(T* start, size_t count, int offset);
	template <class T> void destroyPtr(T* ptr);
}

namespace memory_tools {

	//Aligns the number of given bytes to 32 or 64 bits
	inline size_t align_bytes(size_t num) {

		if (sizeof(void*) == 4)
			return num + (4 - (num % 4)) % 4;
		else
			return num + (8 - (num % 8)) % 8;
	}

	//copies data from src to dst with copy constructor
	template <class T>
	inline void initCopy(T* dst, T* src, int count)
	{
		for (int i = 0; i < count; i++)
		{
			new(dst + i) T(*(src + i));
		}
	}

	//basically memcpy
	template <class T>
	inline void addressCopy(T* dst, T* srs, int count)
	{
		memcpy(dst, srs, count * sizeof(T));
	}
	//moves data from src to dst with move constructor
	template <class T>
	inline void initMove(T* dst, T* src, int count)
	{
		for (int i = 0; i < count; i++)
		{
			new (dst + i) T(std::move(*(src + i)));

			//printf("num: %i ",*a);
			//(ptr)T(std::move(*(src + 1)));
		}
	}

	//moves data from src to dst without move constructor, Does not destroy the src :not implemented
	template <class T>
	inline void memMove(T* dst, T* src, int count)
	{

	}

	//shifts memory block with offset, overlap while shifting back?
	template<class T>
	inline void shift(T* start, size_t count, int offset)
	{
		//shift memory
		memcpy(start + offset, start, count * sizeof(T));
	}

	template<class T>
	inline void destroyPtr(T* ptr)
	{
		ptr->~T();
	}

}
