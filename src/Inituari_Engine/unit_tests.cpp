#include "pch.h"

#include "unit_tests.h"

#include "Memory/allocators.h"
#include "Containers/array_list.h"

namespace inituari {
	void run_all_tests()
	{
		ASSERT(true);
		malloc_allocator_test();
	}

	void malloc_allocator_test()
	{
		MallocAllocator alloc;
		void* p1 = alloc.allocate_memory(1021);
		ASSERT(alloc.currently_allocated() == 1024);
		void* p2 = alloc.allocate_memory(505);
		ASSERT(alloc.currently_allocated() == 512 + 1024);
		alloc.deallocate_memory(p1);
		ASSERT(alloc.currently_allocated() == 512);
		alloc.deallocate_memory(p2);
		ASSERT(alloc.currently_allocated() == 0);
		
		size_t a = alloc.allocation_calls();

		ASSERT(alloc.allocation_calls() == 2);
		ASSERT(alloc.deallocation_calls() == 2);

		void* ptrs[100];
		for (int i = 0; i < 100; i++)
		{
			ptrs[i] = alloc.allocate_memory(64);
		}
		for (int i = 0; i < 100; i++)
		{
			alloc.deallocate_memory(ptrs[i]);
		}
		ASSERT(alloc.currently_allocated() == 0);
	}

	void array_list_test()
	{
		ArrayList<int> l;
		array_list::resize(l, 8);
	}

}