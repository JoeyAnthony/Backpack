// Inituari_Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "types.h"
#include "Engine.h"
#include "unit_tests.h"
#include "memory/allocators.h"
#include "containers/array_list.h"
#include "subsystems/memory_manager.h"
#include "subsystems/log_manager.h"
#include "subsystems/subsystem_manager.h"
#include <vector>

#include "Math/vector3.h"
#include "Math/vector4.h"

#include <immintrin.h>
using namespace backpack;

	int main()
	{
		LOG << "Hello World!\n";

		//for (int k = 1; k < 255; k++)
		//{
		//	BP_LOG(BP_INFO, k) << "noooo";
		//}

		LOG << "bytes_s32: " << sizeof(int32_t);
		LOG << "bytes_s64: " << sizeof(int64_t);
		LOG << "bytes_int: " << sizeof(int);
		LOG << "bytes_size_t: " << sizeof(size_t);
		LOG << "bytes_size_t*: " << sizeof(size_t*);
		LOG << "bytes_char: " << sizeof(char);
		LOG << "bytes_short: " << sizeof(short);

		LOG << "bytes_Allocator: " << sizeof(Allocator);
		LOG << "bytes_MallocAllocator: " << sizeof(MallocAllocator);

		backpack::INIT_ENGINE();
		run_all_tests();


		MallocAllocator alloc;

		ArrayList<s32> a(&alloc);
		array_list::push_back(a, 4);

		//inituari::ArrayList<s32> b = a;
		
		LOG << "rftrfh";
		LOG << "nfhhsoooo";
		LOG << "nosfghfooo";
		LOG << "nofdooo";
		LOG << "nofdo " << 5 << " oo";
		BP_LOG(BP_INFO, RED) << "df";
		BP_LOG(BP_INFO, BLUE) << "df";
		BP_LOG(BP_INFO, YELLOW) << "noooo";
		BP_LOG(BP_INFO, CYAN) << "noooo";
		BP_LOG(BP_INFO, PURPLE) << "noodfgdfgdfgoo";
		BP_LOG(BP_INFO, RED) << "noooo";

		LOG << "address main : " << &alloc;
		//std::cout << "address list : " << &g_subsystemManager.g_memoryManager.allocators[0] <<"\n" ;
		int beer = 4;
		int* aap = new int(7);

		//aap = &beer; //pointer itself
		*aap = 6; //value of pointer


		LOG << *aap;
		LOG <<  beer ;


		math::Vector3 v{5, 6, 7};
		math::Vector3 v2;
		
		v2 = v;

		LOG << "v : " << v.x << " " << v.y << " " << v.z;
		LOG << "v2 : " << v2.x << " " << v2.y << " " << v2.z;

		LOG << "v : " << &v;
		LOG << "v2 : " << &v2;

		return 0;
	}