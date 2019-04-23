// Inituari_Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "types.h"
#include "Engine.h"
#include "unit_tests.h"
#include "Memory/allocators.h"
#include "Containers/array_list.h"
#include "Subsystems/memory_manager.h"
#include "Subsystems/log_manager.h"
#include "Subsystems/subsystem_manager.h"
#include <vector>
#include "Math/vector3.h"


#include <immintrin.h>
using namespace inituari;



	int main()
	{
		std::cout << "Hello World!\n";

		std::cout << "bytes_s32: " << sizeof(int32_t) << "\n";
		std::cout << "bytes_s64: " << sizeof(int64_t) << "\n";
		std::cout << "bytes_int: " << sizeof(int) << "\n";
		std::cout << "bytes_size_t: " << sizeof(size_t) << "\n";
		std::cout << "bytes_size_t*: " << sizeof(size_t*) << "\n";
		std::cout << "bytes_char: " << sizeof(char) << "\n";
		std::cout << "bytes_short: " << sizeof(short) << "\n";

		std::cout << "bytes_Allocator: " << sizeof(inituari::Allocator) << "\n";
		std::cout << "bytes_MallocAllocator: " << sizeof(inituari::MallocAllocator) << "\n";

		inituari::INIT_ENGINE();
		inituari::run_all_tests();


		MallocAllocator alloc;

		//inituari::ArrayList<s32> a(&alloc);
		//array_list::push_back(a, 4);

		////inituari::ArrayList<s32> b = a;


		//log_manager::log("noooo");
		//log_manager::log("rftrfh");
		//log_manager::log("nfhhsoooo");
		//log_manager::log("nosfghfooo");
		//log_manager::log("nofdooo");
		//log_manager::log("nofdo %i oo", 5);
		//log_manager::log("df");
		//log_manager::log("df");
		//log_manager::log("noooo");
		//log_manager::log("noooo");
		//log_manager::log("noodfgdfgdfgoo");


		//std::cout << "address main : " << &alloc << "\n";
		////std::cout << "address list : " << &g_subsystemManager.g_memoryManager.allocators[0] <<"\n" ;
		//int beer = 4;
		//int* aap = new int(7);

		////aap = &beer; //pointer itself
		//*aap = 6; //value of pointer


		//std::cout << "AAP : " << *aap << "\n";
		//std::cout << "BEER : " << beer << "\n";


		vector3 v{5, 6, 7};
		vector3 v2;
		
		v2 = v;

		std::cout << "v : " << v.x << " " << v.y << " " << v.z << "\n";
		std::cout << "v2 : " << v2.x << " " << v2.y << " " << v2.z << "\n";

		std::cout << "v : " << &v << "\n";
		std::cout << "v2 : " << &v2 << "\n";

		return 0;
	}