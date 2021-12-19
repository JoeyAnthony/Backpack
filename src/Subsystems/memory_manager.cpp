#include "pch.h"

#include "memory_manager.h"
#include "Containers/array_list.h"
#include "subsystem_manager.h"

namespace inituari {
	namespace memory_manager
	{
		MemoryManager::MemoryManager():
			m_pool_allocators(ArrayList<PoolAllocator*>(&g_subsystemManager.g_memoryManager.globalAllocator))
		{
		}
		MemoryManager::~MemoryManager()
		{
		}


		void register_pool_allocator(MemoryManager & mng, PoolAllocator *  alloc)
		{
			array_list::push_back(mng.m_pool_allocators, alloc);
		}

		void deregister_pool_allocator(MemoryManager & mng, PoolAllocator * const alloc)
		{
			for (u32 i = 0; i < array_list::length(mng.m_pool_allocators); i++) {
				if (mng.m_pool_allocators[i] == alloc) {
					array_list::remove_move_last(mng.m_pool_allocators, i);
				}
			}
		}

	}
}

