#pragma once

namespace inituari {

	struct Allocator {
		Allocator() {}
		~Allocator() {}

		/*	Allocates*/
		virtual void* allocate_memory(size_t blockSize) = 0;
		virtual void deallocate_memory(void* ptr) = 0;
		virtual size_t allocation_size() = 0;
		virtual size_t currently_allocated() = 0;
		virtual size_t allocation_calls() = 0;
		virtual size_t deallocation_calls() = 0;
	};

	struct MallocAllocator : public Allocator {
		size_t m_currentlyAllocated;
		size_t m_allocationCalls;
		size_t m_deallocationCalls;
		void* m_ptr;

		MallocAllocator();
		~MallocAllocator();

		// Inherited via Allocator
		 void * allocate_memory(size_t blockSize) ;
		 void deallocate_memory(void* ptr) ;
		 size_t allocation_size();
		 size_t currently_allocated() ;
		 size_t allocation_calls() ;
		 size_t deallocation_calls();
	};

	struct PoolAllocator : Allocator {
		const size_t byteSize;
		void* ptr;
	};
}

