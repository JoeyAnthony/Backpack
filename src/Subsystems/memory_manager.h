#pragma once

#include "Memory/MallocAllocator.h"
#include "Memory/PoolAllocator.h"
#include "Containers/container_types.h"

	namespace memory_manager
	{
		static size_t m_nextAllocatrId;
		struct AllocatorInfo {
			const
			Allocator* m_allocator;
		};

		struct MemoryManager {

			MallocAllocator globalAllocator;
			ArrayList<PoolAllocator*> m_pool_allocators;
			

			MemoryManager();
			~MemoryManager();

		};

		/*Registers pool allocator*/
		void register_pool_allocator(MemoryManager& mng, PoolAllocator *  alloc);
		/*Deregisters pool allocator*/
		void deregister_pool_allocator(MemoryManager& mng, PoolAllocator * const alloc);
	}


  