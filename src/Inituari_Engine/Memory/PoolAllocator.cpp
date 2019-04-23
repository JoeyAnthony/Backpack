#include "pch.h"
#include "PoolAllocator.h"
#include "memory_tools.h"
#include "Subsystems/memory_manager.h"
#include "debug.h"
#include "Subsystems/log_manager.h"

namespace inituari {
	PoolAllocator::PoolAllocator(memory_manager::MemoryManager& mng, size_t blockSize, size_t amount)
		:m_currentlyAllocated(0)
		,m_allocationCalls(0)
		,m_deallocationCalls(0)
		,m_blockSize(memory_tools::align_bytes(blockSize))
		,m_poolSize(m_blockSize*amount)
		,m_allocator(mng.globalAllocator)
		,m_manager(mng)
	{
		ASSERT(blockSize >= sizeof(size_t*) && "Blocksize must be larger than size_t*");
		m_ptr = mng.globalAllocator.allocate_memory(memory_tools::align_bytes(m_blockSize*amount));
		m_nextFree = m_ptr;

		char* allocation = (char*) m_ptr;

		size_t* currentBlock = (size_t*)allocation;	//index 0 to size_t
		for (u32 i = 0; i < amount-1; ++i) {
			*currentBlock = (size_t)(allocation + m_blockSize);	//Gives currentBlock a pointer to the next block casted to size_t
			currentBlock = (size_t*) *currentBlock;	//Sets currentBlock pointer to the next block
			allocation += blockSize;
		}
		//set last index to nullptr to know what the last block is
		*currentBlock = (size_t)nullptr;

		memory_manager::register_pool_allocator(mng, this);
	}

	PoolAllocator::PoolAllocator(memory_manager::MemoryManager& mng, Allocator& alloc, size_t blockSize, size_t amount)
		: m_currentlyAllocated(0)
		, m_allocationCalls(0)
		, m_deallocationCalls(0)
		, m_blockSize(memory_tools::align_bytes(blockSize))
		, m_poolSize(m_blockSize*amount)
		, m_allocator(alloc)
		, m_manager(mng)
	{
		ASSERT(blockSize >= sizeof(size_t*) && "Blocksize must be larger than size_t*");
		m_ptr = alloc.allocate_memory(memory_tools::align_bytes(m_blockSize*amount));
		m_nextFree = m_ptr;

		char* allocation = (char*)m_ptr;

		size_t* currentBlock = (size_t*)allocation;	//index 0 to size_t
		for (u32 i = 0; i < amount - 1; ++i) {
			*currentBlock = (size_t)(allocation + m_blockSize);	//Gives currentBlock a pointer to the next block casted to size_t
			currentBlock = (size_t*)*currentBlock;	//Sets currentBlock pointer to the next block
			allocation += blockSize;
		}
		//set last index to nullptr to know what the last block is
		*currentBlock = (size_t)nullptr;

		memory_manager::register_pool_allocator(mng, this);
	}

	PoolAllocator::~PoolAllocator()
	{
		//TODO destroy every block
		m_allocator.deallocate_memory(m_ptr);
		if(m_currentlyAllocated == 0)
			log_manager::log(log_manager::MessageChannel::WARNING, "Not all destructors called");
	}

	void * PoolAllocator::allocate_memory(size_t blockSize)
	{
		ASSERT(memory_tools::align_bytes(blockSize) == m_blockSize && "Blocks not the same size!");
		if (memory_tools::align_bytes(blockSize) != m_blockSize) {
			log_manager::log(log_manager::MessageChannel::ERROR ,"Blocks not the same size!");
			return nullptr;
		}

		if (m_currentlyAllocated == m_poolSize) {
			log_manager::log(log_manager::MessageChannel::ERROR, "No blocks left!");
			return nullptr;
		}

		size_t* returnPtr = (size_t*)m_nextFree;
		m_nextFree = (size_t*) *returnPtr;
		
		m_currentlyAllocated += m_blockSize;
		m_allocationCalls++;

		return returnPtr;
	}

	void PoolAllocator::deallocate_memory(void * ptr)
	{
		//assert if pointer is not between relevant memory addresses
		ASSERT(ptr <= ((char*)m_ptr + m_poolSize) && ptr >= m_ptr);
		if (!ptr)
			return;
	

		size_t* next = (size_t*)ptr; //cast our new pointer to size_t
		*next = (size_t)m_nextFree;	//save the nextFree pointer as number in our new pointer

		m_nextFree = ptr;

		m_currentlyAllocated -= m_blockSize;
		m_allocationCalls++;

		memory_manager::deregister_pool_allocator(m_manager, this);

	}

	size_t PoolAllocator::allocation_size()
	{
		return m_poolSize;
	}

	size_t PoolAllocator::currently_allocated()
	{
		return m_currentlyAllocated;
	}

	size_t PoolAllocator::allocation_calls()
	{
		return m_allocationCalls;
	}

	size_t PoolAllocator::deallocation_calls()
	{
		return m_deallocationCalls;
	}
}