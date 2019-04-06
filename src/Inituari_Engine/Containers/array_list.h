#pragma once
#include <stdlib.h>

#include "types.h"
#include "container_types.h"
#include "Memory/memory_tools.h"

#define INITIAL_ARRAY_SIZE 8

namespace inituari {

	namespace array_list {
		/*Shrinks the allocation to the used size, or the given size as long it is bigger than the used size*/
		template<typename T> void shrink();

		/*Resizes the array to newSize, if the size is smaller t*/
		template<typename T> void resize(ArrayList<T>& arr, u32 newSize);

		/*Insert data at index*/
		template<typename T> void insert(ArrayList<T>& arr, size_t index, const T& data);

		/*insert data at the end of the list*/
		template<typename T> s32 push_back(ArrayList<T>& arr, const T& data);

		/*remove data at the end of the list*/
		template<typename T> void remove_back(ArrayList<T>& arr);

		/*remove data at index*/
		template<typename T> void remove(ArrayList<T>& arr, s32 index);

		/*remove data at index and moves the last element to the removed one*/
		template<typename T> void remove_move_last(ArrayList<T>& arr, s32 index);

		/*returns the maximum amount of elements the list can hold*/
		template<typename T> s32 capacity(ArrayList<T>& arr);

		/*resized the array to the reserved size on the next push_back*/
		template<typename T> void reserve(ArrayList<T>& arr, u32 size);

		/*clears all elements in the list*/
		template<typename T> void clear(ArrayList<T>& arr);

		/*returns a pointer to the begin of the array*/
		template<typename T> T* begin(ArrayList<T>& arr);

		/*returns a pointer to the begin of the array*/
		template<typename T> T const* c_begin(ArrayList<T>& arr);

		/*returns a pointer to the end of the array*/
		template<typename T> T* end(ArrayList<T>& arr);

		/*returns a pointer to the end of the array*/
		template<typename T> const T* c_end(ArrayList<T>& arr);

		/*returns a pointer to a static array with the data currently in the list*/
		template<typename T> T* to_array(ArrayList<T>& arr);

		/*returns a pointer to a static array with the data currently in the list*/
		template<typename T> const T* to_array(ArrayList<T>& arr);

		/*returns the lenght of the list*/
		template<typename T> const s32 length(ArrayList<T>& arr);

		/*returns the number of reserved elements*/
		template<typename T> const s32 reserved(ArrayList<T>& arr);
	}

	template<typename T>
	inline ArrayList<T>::ArrayList(): m_count(0), m_elementCapacity(0), m_reservedNumElements(0){
		//TODO use global allocator
		//array_list::resize(this, INITIAL_ARRAY_SIZE);
	}

	template<typename T>
	inline ArrayList<T>::ArrayList(Allocator * alloc) : m_allocator(alloc), m_count(0), m_elementCapacity(0), m_reservedNumElements(0) {
		array_list::resize(*this, INITIAL_ARRAY_SIZE);
	}

	template<typename T>
	inline ArrayList<T>::ArrayList(const ArrayList<T>& other){
	}

	template<typename T>
	inline ArrayList<T>::~ArrayList(){
		for (u32 i = 0; i < m_count; ++i) {
			m_memBlock[i].~T();
		}
		m_allocator->deallocate_memory(m_memBlock);
	}

	template<typename T>
	T & ArrayList<T>::operator[](u32 index)
	{
		ASSERT(m_elementCapacity > index);
		return m_memBlock[index];
	}

	template<typename T>
	inline T & const ArrayList<T>::operator[](u32 index) const
	{
		ASSERT(m_elementCapacity > index);
		return m_memBlock[index];
		
	}

	template<typename T>
	inline ArrayList<T> const& ArrayList<T>::operator=(const ArrayList<T> other)
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
			inline void shrink()
			{
			}

			template<typename T>
			inline void resize(ArrayList<T>& arr, u32 newSize)
			{
				u32 newAllocSize = newSize;
				if (arr.m_count > newSize)
					return;
				if (arr.m_reservedNumElements > newSize)
					newAllocSize = arr.m_reservedNumElements;

				T* newMem = static_cast<T*>(arr.m_allocator->allocate_memory(newSize * sizeof(T)));

				if (arr.m_count != 0) {
					memory_tools::initCopy(newMem, arr.m_memBlock, std::abs(int(arr.m_count - 1)));
					for (u32 i = 0; i < arr.m_count; ++i) {
						memory_tools::destroyPtr(arr.m_memBlock + i);
					}

					arr.m_allocator->deallocate_memory(arr.m_memBlock);
				}
				arr.m_memBlock = newMem;
				arr.m_elementCapacity = newSize;
			}

			template<typename T>
			inline void insert(ArrayList<T>& arr, size_t index, const T & data)
			{
				if (arr.m_count > arr.m_elementCapacity - 1) {
					std::cout << "capacity not enough" << std::endl;
					ASSERT(false);//TODO needs output
					return;
				}
				memory_tools::shift<T>(arr.m_memBlock + index, arr.m_count - index, 1);
				new (arr.m_memBlock[index]) T(data); //TODO do the right mem operator
			}

			template<typename T>
			inline s32 push_back(ArrayList<T>& arr, const T & data)
			{
				new(end(arr)) T(data);
				arr.m_count++;
				return arr.m_count-1;
			}

			template<typename T>
			inline void remove_back(ArrayList<T>& arr)
			{
				//arr[m_count - 1] = nullptr;
				if (arr.m_count <= 0)
					return; //TODO needs output
				arr.m_count--;
			}

			template<typename T>
			inline void remove(ArrayList<T>& arr, s32 index)
			{
				if (index < 0 || index > arr.m_count-1) {
					//TODO needs output
					return;
				}
				memory_tools::shift(arr[index + 1], arr.m_count - index, -1);
			}

			template<typename T>
			inline void remove_move_last(ArrayList<T>& arr, s32 index)
			{
				if (index < 0 || index > arr.m_count - 1) {
					//TODO needs output
					return;
				}
				memory_tools::memMove(arr[index], end(arr) - 1, 1);
			}

			template<typename T>
			inline s32 capacity(ArrayList<T>& arr)
			{
				return arr.m_elementCapacity;
			}

			template<typename T>
			inline void reserve(ArrayList<T>& arr, u32 size)
			{
				arr.m_reservedNumElements = size;
			}

			template<typename T>
			inline void clear(ArrayList<T>& arr)
			{
				arr.m_count = 0;
			}

			template<typename T>
			inline T * begin(ArrayList<T>& arr)
			{
				return arr.m_memBlock;
			}

			template<typename T>
			T const * c_begin(ArrayList<T>& arr)
			{
				return arr.m_memBlock;
			}

			template<typename T>
			T * end(ArrayList<T>& arr)
			{
				return arr.m_memBlock+arr.m_count;
			}

			template<typename T>
			const T * c_end(ArrayList<T>& arr)
			{
				return arr.m_memBlock + arr.m_count;
			}

			template<typename T>
			inline T * to_array(ArrayList<T>& arr)
			{
				//TODO "to array" not implemented
				return NULL;
			}

			template<typename T>
			inline const s32 length(ArrayList<T>& arr)
			{
				return arr.m_count;
			}

			template<typename T>
			inline const s32 reserved(ArrayList<T>& arr)
			{
				return arr.m_reservedNumElements;
			}
		}

		namespace queue {
			template<typename T> void push_front();
			template<typename T> void remove_front();
		}
}

