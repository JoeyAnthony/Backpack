#include "pch.h"
#include <stdlib.h>

#include "allocators.h"

#include "memory_tools.h"
#include "debug.h"

namespace inituari {

	MallocAllocator::MallocAllocator():
		m_currentlyAllocated(0), m_allocationCalls(0), m_deallocationCalls(0)
	{
	}

	MallocAllocator::~MallocAllocator()
	{
		ASSERT(m_currentlyAllocated == 0);//memory leak
	}

	void * MallocAllocator::allocate_memory(size_t blockSize)
	{
		size_t bytes = memory_tools::align_bytes(blockSize);
		m_currentlyAllocated += bytes;
		m_allocationCalls++;
		return malloc(bytes);
	}

	void MallocAllocator::deallocate_memory(void* ptr)
	{
		m_deallocationCalls++;
		m_currentlyAllocated -= _msize(ptr);
		free(ptr);
	}

	size_t MallocAllocator::allocation_size()
	{
		return m_currentlyAllocated;
	}

	size_t MallocAllocator::currently_allocated()
	{
		return m_currentlyAllocated;
	}

	size_t MallocAllocator::allocation_calls()
	{
		return m_allocationCalls;
	}

	size_t MallocAllocator::deallocation_calls()
	{
		return m_deallocationCalls;
	}

}
