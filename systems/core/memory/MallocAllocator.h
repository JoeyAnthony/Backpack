#pragma once
#include "allocators.h"
#include "types.h"

class MallocAllocator : public Allocator {
public:
	size_t m_currentlyAllocated;
	u32 m_allocationCalls;
	u32 m_deallocationCalls;
	MallocAllocator();
	~MallocAllocator();

	// Inherited via Allocator
	void* allocate_memory(size_t blockSize);
	void deallocate_memory(void* ptr);
	size_t allocation_size();
	size_t currently_allocated();
	size_t allocation_calls();
	size_t deallocation_calls();
};
