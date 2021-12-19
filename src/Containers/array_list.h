#pragma once

#include "types.h"
#include "Memory/memory_tools.h"
#include "debug.h"

struct IIAllocator;

namespace log_manager {
	void log(_Printf_format_string_ const char* fmt, ...);
}

#define INITIAL_ARRAY_SIZE 8

template<typename T> struct IIArrayList {
	u32 m_elementCapacity;
	u32 m_reservedNumElements;
	u32 m_count;
	T* m_memBlock;

	//TODO make ref
	IIAllocator* m_allocator;

	//TODO make ref
	//ArrayList();
	IIArrayList(IIAllocator* alloc, u32 size = INITIAL_ARRAY_SIZE);
	IIArrayList(const IIArrayList<T>& other);
	~IIArrayList();

	T& operator[](u32 index);
	T const& operator[](u32 index) const;
	IIArrayList<T> const& operator=(const IIArrayList<T> other);

};

namespace array_list {
	/*frees data not being used*/
	template<typename T> void condense(IIArrayList<T>& arr);

	/*Resizes the array to newSize, if the current size is smaller t*/
	template<typename T> void resize(IIArrayList<T>& arr, u32 newSize);

	/*Insert data at index*/
	template<typename T> void insert(IIArrayList<T>& arr, size_t index, T const& data);

	/*insert data at the end of the list*/
	template<typename T> u32 push_back(IIArrayList<T>& arr,T const& data);

	/*remove data at the end of the list*/
	template<typename T> void remove_back(IIArrayList<T>& arr);

	/*remove data at index*/
	template<typename T> void remove(IIArrayList<T>& arr, u32 index);

	/*remove data at index and moves the last element to the removed one*/
	template<typename T> void remove_move_last(IIArrayList<T>& arr, u32 index);

	/*returns the maximum amount of elements the list can hold*/
	template<typename T> u32 capacity(IIArrayList<T>& arr);

	/*resized the array to the reserved size on the next push_back*/
	template<typename T> void reserve(IIArrayList<T>& arr, u32 size);

	/*clears all elements in the list*/
	template<typename T> void clear(IIArrayList<T>& arr);

	/*returns a pointer to the begin of the array*/
	template<typename T> T* begin(IIArrayList<T>& arr);

	/*returns a pointer to the begin of the array*/
	template<typename T> T const* c_begin(IIArrayList<T>& arr);

	/*returns a pointer to the end of the array*/
	template<typename T> T* end(IIArrayList<T>& arr);

	/*returns a pointer to the end of the array*/
	template<typename T> const T* c_end(IIArrayList<T>& arr);

	/*returns a pointer to a static array with the data currently in the list*/
	template<typename T> T* to_array(IIArrayList<T>& arr);

	/*returns a pointer to a static array with the data currently in the list*/
	template<typename T> const T* to_array(IIArrayList<T>& arr);

	/*returns the lenght of the list*/
	template<typename T> const u32 length(IIArrayList<T>& arr);

	/*returns the number of reserved elements*/
	template<typename T> const u32 reserved(IIArrayList<T>& arr);
}


//template<typename T>
//inline IIArrayList<T>::IIArrayList(): 
//	m_allocator(nullptr), m_count(0), m_elementCapacity(0), m_reservedNumElements(0)
//{
//}

template<typename T>
inline IIArrayList<T>::IIArrayList(IIAllocator* alloc, u32 size) :
	m_allocator(alloc), m_count(0), m_elementCapacity(0), m_reservedNumElements(0) {
	array_list::resize(*this, size);
}

template<typename T>
inline IIArrayList<T>::IIArrayList(const IIArrayList<T>& other){
}

template<typename T>
inline IIArrayList<T>::~IIArrayList(){
	for (u32 i = 0; i < m_count; ++i) {
		m_memBlock[i].~T();
	}
	m_allocator->deallocate_memory(m_memBlock);
}

template<typename T>
T & IIArrayList<T>::operator[](u32 index)
{
	if (m_elementCapacity <= index)
		ASSERT(false && "index out of bounds");
	return m_memBlock[index];
}

template<typename T>
inline T const& IIArrayList<T>::operator[](u32 index) const
{
	if (m_elementCapacity <= index)
		ASSERT(false && "index out of bounds");
	return m_memBlock[index];
		
}

template<typename T>
inline IIArrayList<T> const& IIArrayList<T>::operator=(const IIArrayList<T> other)
{
	array_list::resize(this, other.m_count);

	for (u32 i(0); i < other.m_count; ++i)
		memory_tools::initCopy(this->m_memBlock, other.m_memBlock, other.m_count);

	this->m_count = other.m_count;
	return *this;
}

//implementation
namespace array_list {

		template<typename T>
		inline void condense(IIArrayList<T>& arr)
		{
			if (arr.m_count < arr.m_elementCapacity){
				arr.m_reservedNumElements = arr.m_count;
				resize(arr, arr.m_count);
			}
		}

		template<typename T>
		inline void resize(IIArrayList<T>& arr, u32 newSize)
		{
			u32 newAllocSize = newSize;
			if (arr.m_reservedNumElements > newSize)
				newAllocSize = arr.m_reservedNumElements;

			T* newMem = static_cast<T*>(arr.m_allocator->allocate_memory(newAllocSize * sizeof(T)));

			if (arr.m_count > 0) { //only copy when there are elements
				memory_tools::initCopy(newMem, arr.m_memBlock, arr.m_count);
				for (u32 i = 0; i < arr.m_count; ++i) {
					memory_tools::destroyPtr(arr.m_memBlock + i);
				}
			}
			if(arr.m_elementCapacity > 0) //only deallocate when there is capacity
				arr.m_allocator->deallocate_memory(arr.m_memBlock);

			arr.m_memBlock = newMem;
			arr.m_elementCapacity = newAllocSize;
		}

		template<typename T>
		inline void insert(IIArrayList<T>& arr, size_t index, const T & data)
		{
			if (arr.m_count < 0) {
				resize(arr, INITIAL_ARRAY_SIZE);
				//ASSERT(false && "capacity not enough, resizing");
			}
			if (arr.m_count >= arr.m_elementCapacity) {
				//ASSERT(false && "capacity not enough, resizing");
				resize(arr, arr.m_elementCapacity * 2);
			}
			memory_tools::shift<T>(arr.m_memBlock + index, arr.m_count - index, 1);
			new (arr.m_memBlock+index) T(data);
			arr.m_count++;
		}

		template<typename T>
		inline u32 push_back(IIArrayList<T>& arr, const T & data)
		{
			if (arr.m_count == arr.m_elementCapacity)
				resize(arr, arr.m_elementCapacity * 2);
			new(end(arr)) T(data);
			arr.m_count++;
			return arr.m_count-1;
		}

		template<typename T>
		inline void remove_back(IIArrayList<T>& arr)
		{
			//arr[m_count - 1] = nullptr;
			if (arr.m_count <= 0) {
				log_manager::log("array empty!");
				return;
			}
			arr.m_count--;
		}

		template<typename T>
		inline void remove(IIArrayList<T>& arr, u32 index)
		{
			if (index < 0 || index > arr.m_count) {
				log_manager::log("out of bounds!");
				return;
			}
			memory_tools::shift(arr.m_memBlock+index+1, arr.m_count - index, -1);
			arr.m_count--;
			//TODO destruct obj
		}

		template<typename T>
		inline void remove_move_last(IIArrayList<T>& arr, u32 index)
		{
			if (index < 0 || index > arr.m_count - 1) {
				log_manager::log("out of bounds!");
				return;
			}
			memory_tools::memMove<T>(&arr[index], end(arr), 1);
			arr.m_count--;
		}

		template<typename T>
		inline u32 capacity(IIArrayList<T>& arr)
		{
			return arr.m_elementCapacity;
		}

		template<typename T>
		inline void reserve(IIArrayList<T>& arr, u32 size)
		{
			arr.m_reservedNumElements = size;
		}

		template<typename T>
		inline void clear(IIArrayList<T>& arr)
		{
			for (u32 i = 0; i < arr.m_count; ++i) {
				memory_tools::destroyPtr(arr.m_memBlock + i);
			}
			arr.m_count = 0;
		}

		template<typename T>
		inline T * begin(IIArrayList<T>& arr)
		{
			return arr.m_memBlock;
		}

		template<typename T>
		T const * c_begin(IIArrayList<T>& arr)
		{
			return arr.m_memBlock;
		}

		template<typename T>
		T * end(IIArrayList<T>& arr)
		{
			return arr.m_memBlock+arr.m_count;
		}

		template<typename T>
		const T * c_end(IIArrayList<T>& arr)
		{
			return arr.m_memBlock + arr.m_count;
		}

		template<typename T>
		inline T * to_array(IIArrayList<T>& arr)
		{
			//TODO "to array" not implemented
			return NULL;
		}

		template<typename T>
		inline const u32 length(IIArrayList<T>& arr)
		{
			return arr.m_count;
		}

		template<typename T>
		inline const u32 reserved(IIArrayList<T>& arr)
		{
			return arr.m_reservedNumElements;
		}
	}

	namespace queue {
		template<typename T> void push_front();
		template<typename T> void remove_front();
	}

