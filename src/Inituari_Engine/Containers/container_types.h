#pragma once
#include "types.h"
#include "Memory/allocators.h" 
//#include "array_list.h"

namespace inituari {
		template<typename T> struct ArrayList {
			u32 m_elementCapacity;
			u32 m_reservedNumElements;	
			u32 m_count;
			T* m_memBlock;			
			Allocator* m_allocator;

			ArrayList();
			ArrayList(Allocator* alloc);
			ArrayList(const ArrayList<T>& other);
			~ArrayList();

			T& operator[](u32 index);
			T& const operator[](u32 index) const;
			ArrayList<T> const& operator=(const ArrayList<T> other);

		};



}
