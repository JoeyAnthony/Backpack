// Inituari_Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "types.h"
#include "Engine.h"
#include "unit_tests.h"
#include "Memory/allocators.h"
#include "Containers/array_list.h"

using namespace inituari;

	int main()
	{
		std::cout << "Hello World!\n";
		inituari::INIT_ENGINE();
		std::cout << "Shut down!\n";
		inituari::run_all_tests();

		std::cout << "bytes_s32: " << sizeof(int32_t) << "\n";
		std::cout << "bytes_s64: " << sizeof(int64_t) << "\n";
		std::cout << "bytes_int: " << sizeof(int) << "\n";
		std::cout << "bytes_size_t: " << sizeof(int) << "\n";
		std::cout << "bytes_char: " << sizeof(char) << "\n";
		std::cout << "bytes_short: " << sizeof(short) << "\n";

		std::cout << "bytes_Allocator: " << sizeof(inituari::Allocator) << "\n";
		std::cout << "bytes_MallocAllocator: " << sizeof(inituari::MallocAllocator) << "\n";

		MallocAllocator alloc;

		inituari::ArrayList<s32> a(&alloc);
		array_list::push_back(a, 4);

		//inituari::ArrayList<s32> b = a;


		return 0;
	}

	


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
