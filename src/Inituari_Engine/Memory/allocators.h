#pragma once

namespace inituari {
	struct Allocator {
		Allocator() {}
		Allocator(Allocator const& alloc);
		~Allocator() {}

		/*	Allocates*/
		virtual void* allocate_memory(size_t blockSize) = 0;
		virtual void deallocate_memory(void* ptr) = 0;
		virtual size_t allocation_size() = 0;
		virtual size_t currently_allocated() = 0;
		virtual size_t allocation_calls() = 0;
		virtual size_t deallocation_calls() = 0;
	};
}

