#include "pch.h"

#include<iostream>

#include "unit_tests.h"

#include "Memory/allocators.h"
#include "Containers/array_list.h"
#include "Subsystems/log_manager.h"
#include "Memory/MallocAllocator.h"
#include "Memory/PoolAllocator.h"
#include "Subsystems/subsystem_manager.h"
#include "Math/math.h"

namespace inituari {
	void run_all_tests()
	{
		ASSERT(true);
		malloc_allocator_test();
		array_list_test();
		pool_allocator_test();
		math_test();
	}

	void malloc_allocator_test()
	{
		MallocAllocator alloc;
		//8bit (x64) aligned
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

		log_manager::log(log_manager::MessageChannel::SYSTEM, "MallocAllocator passed all tests");
	}

	struct PoolTestOne {
		s32 a;
	};
	struct PoolTestTwo {
		u64 a;
		u64 b;
		u64 c;
		u64 d;
		u64 e;
	};

	void pool_allocator_test()
	{
		{
			PoolAllocator alloc(g_subsystemManager.g_memoryManager, sizeof(u64), 8);
			u64* data[8];
			//initialize data and check pointer range
			for (s32 i = 0; i < 8; i++) {
				void* ptr = alloc.allocate_memory(sizeof(u64));
				ASSERT(ptr <= ((char*)alloc.m_ptr + alloc.m_poolSize) && ptr >= alloc.m_ptr &&"must be in address range");
				data[i] = new(ptr) u64;
				*data[i] = i;
			}

			//check data
			for (s32 i = 0; i < 8; i++) {
				ASSERT(*data[i] == i && "Data not right");
			}

			//deallocate some and check data
			alloc.deallocate_memory(data[0]);
			alloc.deallocate_memory(data[4]);
			alloc.deallocate_memory(data[7]);

			ASSERT(*data[1] == 1);
			ASSERT(*data[2] == 2);
			ASSERT(*data[3] == 3);
			ASSERT(*data[5] == 5);
			ASSERT(*data[6] == 6);

			//allocate and intialize then check data
			data[0] = new(alloc.allocate_memory(sizeof(u64))) u64;
			data[4] = new(alloc.allocate_memory(sizeof(u64))) u64;
			data[7] = new(alloc.allocate_memory(sizeof(u64))) u64;

			*data[0] = 9;
			*data[4] = 10;
			*data[7] = 11;

			for (s32 i = 0; i < 8; i++) {
				ASSERT(*data[i] > 0 && *data[i] < 12 && "Data not right");
				alloc.deallocate_memory(data[i]);
			}
		}

		{
			MallocAllocator test_malloc;
			PoolAllocator alloc(g_subsystemManager.g_memoryManager, test_malloc, sizeof(PoolTestTwo), 8);
			PoolTestTwo* data[8];
			//initialize data and check pointer range
			for (s64 i = 0; i < 8; i++) {
				void* ptr = alloc.allocate_memory(sizeof(PoolTestTwo));
				ASSERT(ptr <= ((char*)alloc.m_ptr + alloc.m_poolSize) && ptr >= alloc.m_ptr &&"must be in address range");
				data[i] = new(ptr) PoolTestTwo;
				data[i]->a = i;
			}

			for (s32 i = 0; i < 8; i++) {
				alloc.deallocate_memory(data[i]);
			}
		}
		
		//test for poolallocator that can hold blocks with size smaller than 8 bytes
		//{
		//	PoolAllocator alloc(g_subsystemManager.g_memoryManager, sizeof(PoolTestOne), 8);
		//	PoolTestOne* data[8];
		//	//initialize data and check pointer range
		//	for (s32 i = 0; i < 8; i++) {
		//		void* ptr = alloc.allocate_memory(sizeof(PoolTestOne));
		//		ASSERT(ptr <= ((char*)alloc.m_ptr + alloc.m_poolSize) && ptr >= alloc.m_ptr &&"must be in address range");
		//		data[i] = new(ptr) PoolTestOne;
		//		data[i]->a = i;
		//	}
		//}

		log_manager::log(log_manager::MessageChannel::SYSTEM, "PoolAllocator passed all tests");
	}

	void array_list_test()
	{
		MallocAllocator alloc;
		ArrayList<int> l(&alloc);
		//resizes and checking size of the allocator
		array_list::resize(l, 8);
		array_list::resize(l, 15);
		array_list::resize(l, 30);
		array_list::resize(l, 100);
		ASSERT(alloc.currently_allocated() == 400);

		//initializing 100 ints and checking data
		for(int i = 0; i < 100; ++i){
			array_list::push_back(l, i);
		}
		ASSERT(l.m_count == 100);
		for (int i = 0; i < 100; ++i) {
			ASSERT(l[i] == i);
		}

		//resizing with data and checking data
		array_list::resize(l, 200);
		for (int i = 0; i < 100; ++i) {
			ASSERT(l[i] == i);
		}
		ASSERT(alloc.currently_allocated() == 800);

		//test condense
		array_list::condense(l);
		ASSERT(l.m_count == 100);
		ASSERT(alloc.currently_allocated() == 400);

		//testing inserts
		array_list::insert(l, 25, 15);
		array_list::insert(l, 50, 10);
		array_list::insert(l,78, 7);
		ASSERT(l[50] == 10);
		ASSERT(l[25] == 15);
		ASSERT(l[78] == 7);
		ASSERT(l.m_count == 103);

		//test remove and clear
		array_list::clear(l);
		ASSERT(l.m_count == 0);
		for (int i = 0; i < 100; ++i) {
			array_list::push_back(l, i);
		}//clearing and resetting array with 100 elements
		array_list::condense(l);
		ASSERT(l.m_count == 100);
		ASSERT(alloc.currently_allocated() == 400);
		for (int i = 0; i < 100; ++i) {
			ASSERT(l[i] == i);
		}

		array_list::remove(l, 88);
		array_list::remove(l, 56);
		array_list::remove(l, 20);
		array_list::condense(l);
		ASSERT(l.m_count == 97);
		ASSERT(alloc.currently_allocated() == 392);
		//for (int i = 0; i < 97; ++i) {
		//	std::cout << l[i] << "\n" ;
		//} //print numbers
		for (int i = 0; i < 97; ++i) {
			ASSERT(l[i] != 20);
			ASSERT(l[i] != 56);
			ASSERT(l[i] != 88);
		}

		//test remove back
		for (int i = 0; i < 100; ++i) {
			array_list::remove_back(l);
		}
		ASSERT(l.m_count == 0);
		ASSERT(alloc.currently_allocated() == 392);

		////default constructor test
		//ArrayList<int> construct;
		//array_list::resize(construct, 100);
		//for (int i = 0; i < 100; ++i) {
		//	array_list::push_back(construct, i);
		//}
		//ASSERT(construct.m_allocator->allocation_calls() == 2 && "not allocating right");

		//ArrayList<int> l2 = ArrayList<int>();

		log_manager::log(log_manager::MessageChannel::SYSTEM, "ArrayList passed all tests");
	}

	void math_test()
	{
		//epsilonCompare test
		ASSERT(epsilon_compare(5, 5));
		ASSERT(!epsilon_compare(4, 5));
		ASSERT(epsilon_compare((1.f / 5.f) * (5.f*5.f), 5.f));
		ASSERT(!epsilon_compare(1.f / 4.f * (4.f*4.f), 5.f));

		ASSERT(!epsilon_compare(0.002, 0.003));
		ASSERT(epsilon_compare(0.003, 0.003));

		ASSERT(!epsilon_compare(0.00003, 0.00004));
		ASSERT(epsilon_compare(0.000075, 0.00007));//limit

		//sqrt
		ASSERT(epsilon_compare(sqrt(16), 4.f, 0.001f));
		ASSERT(epsilon_compare(sqrt(25), 5.f, 0.001f));
		ASSERT(epsilon_compare(sqrt(3), 1.73205080757f, 0.001f));
	}

	void memory_manager_test()
	{

	}

}