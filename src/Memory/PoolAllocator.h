#pragma once
#include "types.h"
#include "allocators.h"

namespace inituari {
	namespace memory_manager { struct MemoryManager; }
	struct PoolAllocator : Allocator {
		size_t m_currentlyAllocated;	//64 - 64
		size_t m_blockSize;				//128 - 64
		size_t m_poolSize;				//192 - 64
		Allocator& m_allocator;			//256 - 64
		void* m_ptr;					//320 - 64
		void* m_nextFree;				//384 - 64

		memory_manager::MemoryManager& m_manager;	//448 - 64

		u32 m_allocationCalls;		//480 - 32
		u32 m_deallocationCalls;	//512 - 32


		PoolAllocator(memory_manager::MemoryManager& mng, size_t blockSize, size_t amount);
		PoolAllocator(memory_manager::MemoryManager& mng, Allocator& alloc, size_t blockSize, size_t amount);
		~PoolAllocator();

		// Inherited via Allocator
		virtual void * allocate_memory(size_t blockSize) override;
		virtual void deallocate_memory(void * ptr) override;
		virtual size_t allocation_size() override;
		virtual size_t currently_allocated() override;
		virtual size_t allocation_calls() override;
		virtual size_t deallocation_calls() override;

	};
}
