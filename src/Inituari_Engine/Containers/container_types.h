#pragma once
#include "types.h"

namespace inituari {
#define INITIAL_ARRAY_SIZE 8

	struct Allocator;

		template<typename T> struct ArrayList {
			u32 m_elementCapacity;
			u32 m_reservedNumElements;	
			u32 m_count;
			T* m_memBlock;

			//TODO make ref
			Allocator* m_allocator;

			//TODO make ref
			//ArrayList();
			ArrayList(Allocator* alloc, u32 size = INITIAL_ARRAY_SIZE);
			ArrayList(const ArrayList<T>& other);
			~ArrayList();

			T& operator[](u32 index);
			T const&  operator[](u32 index) const;
			ArrayList<T> const& operator=(const ArrayList<T> other);

		};



}
