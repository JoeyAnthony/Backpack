#pragma once
#include "../containers/array_list.h"
#include "../memory/MallocAllocator.h"
#include "../memory/PoolAllocator.h"

static size_t m_nextAllocatrId;
struct AllocatorInfo {
	const Allocator* m_allocator;
};

struct MemoryManager {
	MallocAllocator globalAllocator;
	ArrayList<PoolAllocator*> m_pool_allocators;

	MemoryManager();
	~MemoryManager();
};

namespace memory_manager {
	/*Registers pool allocator*/
	void register_pool_allocator(MemoryManager& mng, PoolAllocator* alloc);
	/*Deregisters pool allocator*/
	void deregister_pool_allocator(MemoryManager& mng, PoolAllocator* const alloc);
}
