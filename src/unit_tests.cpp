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
#include "Math/mat3.h"
#include "Math/mat4.h"
#include "Math/vector2.h"
#include "Math/vector3.h"
#include "Math/vector4.h"

namespace inituari {

	bool vector2_compare(math::Vector2 a, math::Vector2 b, f32 epsilon = EPSILON) {
		bool comp = true;
		if (!math::epsilon_compare(a.x, b.x, epsilon))comp = false;
		if (!math::epsilon_compare(a.y, b.y, epsilon))comp = false;

		return comp;
	}

	bool vector3_compare(math::Vector3 a, math::Vector3 b, f32 epsilon = EPSILON) {
		bool comp = true;
		if (!math::epsilon_compare(a.x, b.x, epsilon))comp = false;
		if (!math::epsilon_compare(a.y, b.y, epsilon))comp = false;
		if (!math::epsilon_compare(a.z, b.z, epsilon))comp = false;

		return comp;
	}

	bool vector4_compare(math::Vector4 a, math::Vector4 b, f32 epsilon = EPSILON) {
		bool comp = true;
		if (!math::epsilon_compare(a.x, b.x, epsilon))comp = false;
		if (!math::epsilon_compare(a.y, b.y, epsilon))comp = false;
		if (!math::epsilon_compare(a.z, b.z, epsilon))comp = false;
		if (!math::epsilon_compare(a.w, b.w, epsilon))comp = false;

		return comp;
	}

	bool matrix_compare(math::Mat4 a, math::Mat4 b, f32 epsilon = EPSILON) {
		bool comp = true;
		if (!math::epsilon_compare(a.m00, b.m00, epsilon))comp = false;
		if (!math::epsilon_compare(a.m01, b.m01, epsilon))comp = false;
		if (!math::epsilon_compare(a.m02, b.m02, epsilon))comp = false;
		if (!math::epsilon_compare(a.m03, b.m03, epsilon))comp = false;
		if (!math::epsilon_compare(a.m10, b.m10, epsilon))comp = false;
		if (!math::epsilon_compare(a.m11, b.m11, epsilon))comp = false;
		if (!math::epsilon_compare(a.m12, b.m12, epsilon))comp = false;
		if (!math::epsilon_compare(a.m13, b.m13, epsilon))comp = false;
		if (!math::epsilon_compare(a.m20, b.m20, epsilon))comp = false;
		if (!math::epsilon_compare(a.m21, b.m21, epsilon))comp = false;
		if (!math::epsilon_compare(a.m22, b.m22, epsilon))comp = false;
		if (!math::epsilon_compare(a.m23, b.m23, epsilon))comp = false;
		if (!math::epsilon_compare(a.m30, b.m30, epsilon))comp = false;
		if (!math::epsilon_compare(a.m31, b.m31, epsilon))comp = false;
		if (!math::epsilon_compare(a.m32, b.m32, epsilon))comp = false;
		if (!math::epsilon_compare(a.m33, b.m33, epsilon))comp = false;
		return comp;
	}

	bool matrix_compare(math::Mat3 a, math::Mat3 b, f32 epsilon = EPSILON) {
		bool comp = true;
		if (!math::epsilon_compare(a.m00, b.m00, epsilon))comp = false;
		if (!math::epsilon_compare(a.m01, b.m01, epsilon))comp = false;
		if (!math::epsilon_compare(a.m02, b.m02, epsilon))comp = false;
		if (!math::epsilon_compare(a.m10, b.m10, epsilon))comp = false;
		if (!math::epsilon_compare(a.m11, b.m11, epsilon))comp = false;
		if (!math::epsilon_compare(a.m12, b.m12, epsilon))comp = false;
		if (!math::epsilon_compare(a.m20, b.m20, epsilon))comp = false;
		if (!math::epsilon_compare(a.m21, b.m21, epsilon))comp = false;
		if (!math::epsilon_compare(a.m22, b.m22, epsilon))comp = false;
		return comp;
	}
}

namespace inituari {
	void run_all_tests()
	{
		ASSERT(true);
		malloc_allocator_test();
		array_list_test();
		pool_allocator_test();
		//math_test();
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
		ASSERT(math::epsilon_compare(5, 5));
		ASSERT(!math::epsilon_compare(4, 5));
		ASSERT(math::epsilon_compare((1.f / 5.f) * (5.f*5.f), 5.f));
		ASSERT(!math::epsilon_compare(1.f / 4.f * (4.f*4.f), 5.f));

		ASSERT(!math::epsilon_compare(0.002f, 0.003f));
		ASSERT(math::epsilon_compare(0.003f, 0.003f));

		ASSERT(!math::epsilon_compare(0.00003f, 0.00004f));
		ASSERT(math::epsilon_compare(0.000075f, 0.00007f));//limit

		//sqrt not super accurate
		ASSERT(math::epsilon_compare(math::sqrt(16), 4.f, 0.001f));
		ASSERT(math::epsilon_compare(math::sqrt(25), 5.f, 0.001f));
		ASSERT(math::epsilon_compare(math::sqrt(3), 1.73205080757f, 0.001f));

		{
			//vector2
			math::Vector2 v1{ 5.6f, 1.3f };
			math::Vector2 v2{ 5.6f, 1.3f };
			math::Vector2 v3{ 1.6f, 56.3f };

			ASSERT(vector2_compare(v1, v2) && "vectors not the same");
			ASSERT(!vector2_compare(v1, v3) && "vectors must be different");
			ASSERT(vector2_compare((v1 + v3), math::vector2(7.2f, 57.6f)) && "adding went wrong");
			ASSERT(vector2_compare((v1 - v3), math::vector2(4.0f, -55.f)) && "subtracting went wrong");
			ASSERT(vector2_compare((v1 * v3), math::vector2(8.96f, 73.19f)) && "multiplying went wrong");
			ASSERT(vector2_compare((v1 * 5.f), math::vector2(28.f, 6.5f)) && "multiplying went wrong");
			ASSERT(vector2_compare((v1 / 5.f), math::vector2(1.12f, 0.26f)) && "division went wrong");
		}

		{
			math::Vector2 vt1{ 5.6f, 1.3f };
			math::Vector2 vt2{ 1.6f, 56.3f };
			vt1 *= vt2; //test
			ASSERT(vector2_compare(vt1, math::vector2(8.96f, 73.19f)) && "multiplying went wrong");
		}

		{
			math::Vector2 vt1{ 5.6f, 1.3f };
			math::Vector2 vt2{ 1.6f, 56.3f };
			vt1 += vt2;//test
			ASSERT(vector2_compare(vt1, math::vector2(7.2f, 57.6f)) && "adding went wrong");
		}

		{
			math::Vector2 vt1{ 5.6f, 1.3f };
			math::Vector2 vt2{ 1.6f, 56.3f };
			vt1 *= 5.f;//test
			ASSERT(vector2_compare(vt1, math::vector2(28.f, 6.5f)) && "multiplying went wrong");
		}

		{
			math::Vector2 vt2{ 1.6f, 56.3f };
			ASSERT(math::epsilon_compare(math::magnitude(vt2), 56.32273f, 0.01f) && "magnitude went wrong");
		}

		{
			math::Vector2 vt2{ 1.6f, 56.3f };
			ASSERT(math::epsilon_compare(math::magnitude_squared(vt2), (1.6f*1.6f + 56.3f*56.3f)) && "magnitude squared went wrong");
		}

		{
			math::Vector2 vt1{ 5.6f, 1.3f };
			math::Vector2 vt2{ 1.6f, 56.3f };
			ASSERT(math::epsilon_compare(math::dot(vt1, vt2), 82.15f) && "dot product went wrong");
		}

		{
			math::Vector2 vt2{ 1.6f, 56.3f };
			ASSERT(math::epsilon_compare(math::magnitude(math::unit(vt2)), 1.f, 0.001f) && "unit vector went wrong");
		}

		{
			//vector3
			math::Vector3 v1{ 5.6f, 1.3f, 8.9f };
			math::Vector3 v2{ 5.6f, 1.3f, 8.9f };
			math::Vector3 v3{ 1.6f, 56.3f, 2.9f };

			ASSERT(vector3_compare(v1, v2) && "vectors not the same");
			ASSERT(!vector3_compare(v1, v3) && "vectors must be different");
			ASSERT(vector3_compare((v1 + v3), math::vector3(7.2f, 57.6f, 11.8f)) && "adding went wrong");
			ASSERT(vector3_compare((v1 - v3), math::vector3(4.0f, -55.f, 6.f)) && "subtracting went wrong");
			ASSERT(vector3_compare((v1 * v3), math::vector3(8.96f, 73.19f, 25.81f)) && "multiplying went wrong");
			ASSERT(vector3_compare((v1 * 5.f), math::vector3(28.f, 6.5f, 44.5)) && "multiplying went wrong");
			ASSERT(vector3_compare((v1 / 5.f), math::vector3(1.12f, 0.26f, 1.78f)) && "division went wrong");
		}

		{
			math::Vector3 vt1{ 5.6f, 1.3f, 8.9f };
			math::Vector3 vt2{ 1.6f, 56.3f, 2.9f };
			vt1 *= vt2; //test
			ASSERT(vector3_compare(vt1, math::vector3(8.96f, 73.19f, 25.81f)) && "multiplying went wrong");
		}

		{
			math::Vector3 vt1{ 5.6f, 1.3f, 8.9f };
			math::Vector3 vt2{ 1.6f, 56.3f, 2.9f };
			vt1 += vt2;//test
			ASSERT(vector3_compare(vt1, math::vector3(7.2f, 57.6f, 11.8f)) && "adding went wrong");
		}

		{
			math::Vector3 vt1{ 5.6f, 1.3f, 8.9f };
			vt1 *= 5.f;//test
			ASSERT(vector3_compare(vt1, math::vector3(28.f, 6.5f, 44.5)) && "multiplying went wrong");
		}

		{
			math::Vector3 vt2{ 1.6f, 56.3f, 2.9f };
			ASSERT(math::epsilon_compare(math::magnitude(vt2), 56.39734f, 0.01f) && "magnitude went wrong");
		}

		{
			math::Vector3 vt2{ 1.6f, 56.3f, 2.9f };
			ASSERT(math::epsilon_compare(math::magnitude_squared(vt2), (1.6f*1.6f + 56.3f*56.3f + 2.9f*2.9f)) && "magnitude squared went wrong");
		}

		{
			math::Vector3 vt2{ 1.6f, 56.3f, 2.9f };
			ASSERT(math::epsilon_compare(math::magnitude(math::unit(vt2)), 1.f, 0.001f) && "unity vector went wrong");
		}

		{
			//vector4
			math::Vector4 v1{ 5.6f, 1.3f, 8.9f, 20.1f };
			math::Vector4 v2{ 5.6f, 1.3f, 8.9f, 20.1f };
			math::Vector4 v3{ 1.6f, 56.3f, 2.9f, 38.4f };

			ASSERT(vector4_compare(v1, v2) && "vectors not the same");
			ASSERT(!vector4_compare(v1, v3) && "vectors must be different");
			ASSERT(vector4_compare((v1 + v3), math::vector4(7.2f, 57.6f, 11.8f, 58.5f)) && "adding went wrong");
			ASSERT(vector4_compare((v1 - v3), math::vector4(4.0f, -55.f, 6.f, -18.3f)) && "subtracting went wrong");
			ASSERT(vector4_compare((v1 * v3), math::vector4(8.96f, 73.19f, 25.81f, 771.84f)) && "multiplying went wrong");
			ASSERT(vector4_compare((v1 * 5.f), math::vector4(28.f, 6.5f, 44.5, 100.5f)) && "multiplying went wrong");
			ASSERT(vector4_compare((v1 / 5.f), math::vector4(1.12f, 0.26f, 1.78f, 4.02f)) && "division went wrong");
		}

		{
			math::Vector4 vt1{ 5.6f, 1.3f, 8.9f, 20.1f };
			math::Vector4 vt2{ 1.6f, 56.3f, 2.9f, 38.4f };
			vt1 *= vt2; //test
			ASSERT(vector4_compare(vt1, math::vector4(8.96f, 73.19f, 25.81f, 771.84f)) && "multiplying went wrong");
		}

		{
			math::Vector4 vt1{ 5.6f, 1.3f, 8.9f, 20.1f };
			math::Vector4 vt2{ 1.6f, 56.3f, 2.9f, 38.4f };
			vt1 += vt2;//test
			ASSERT(vector4_compare(vt1, math::vector4(7.2f, 57.6f, 11.8f, 58.5f)) && "adding went wrong");
		}

		{
			math::Vector4 vt1{ 5.6f, 1.3f, 8.9f, 20.1f };
			vt1 *= 5.f;//test
			ASSERT(vector4_compare(vt1, math::vector4(28.f, 6.5f, 44.5, 100.5f)) && "multiplying went wrong");
		}

		{
			math::Vector4 vt2{ 1.6f, 56.3f, 2.9f, 38.4f };
			ASSERT(math::epsilon_compare(math::magnitude(vt2), 68.22917f, 0.01f) && "magnitude went wrong");
		}

		{
			math::Vector4 vt2{ 1.6f, 56.3f, 2.9f, 38.4f };
			ASSERT(math::epsilon_compare(math::magnitude_squared(vt2), (1.6f*1.6f + 56.3f*56.3f + 2.9f*2.9f + 38.4f*38.4f)) && "magnitude squared went wrong");
		}

		{
			math::Vector4 vt2{ 1.6f, 56.3f, 2.9f, 38.4f };
			ASSERT(math::epsilon_compare(math::magnitude(math::unit(vt2)), 1.f, 0.001f) && "unit vector went wrong");
		}

		//mat3
		{
			math::Mat3 A{5, 8, 574,
						47, 55, 0,
						2, 43, 9};

			math::Mat3 B( 9, 6, 7, 
						25, 33, 77,
						274, 51, 35); //test constructor

			math::Mat3 C{ 14, 14, 581,
						72, 88, 77, 
						276, 94, 44 };
			ASSERT(matrix_compare((A + B), C) && "matrix addition went wrong");
			ASSERT( matrix_compare(A+=B, C)  && "matrix addition went wrong");

		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };

			math::Mat3 B{ 9, 6, 7,
						25, 33, 77,
						274, 51, 35 };

			math::Mat3 C{ -4, 2, 567,
						22, 22, -77,
						-272, -8, -26 };

			ASSERT(matrix_compare((A - B), C) && "matrix subtraction went wrong");
			ASSERT(matrix_compare((A -= B), C) && "matrix subtraction went wrong");
		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };

			math::Mat3 B{ 9, 6, 7,
						25, 33, 77,
						274, 51, 35 };

			math::Mat3 C{ 157521, 29568, 20741,
						1798, 2097, 4564,
						3559, 1890, 3640 };

			ASSERT(matrix_compare((A * B), C) && "matrix multiplication went wrong");
			ASSERT(matrix_compare((A *= B), C) && "matrix multiplication went wrong");
		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };

			math::Mat3 C{ -60, -96, -6888,
						-564, -660, 0,
						-24, -516, -108 };

			ASSERT(matrix_compare((A * -12), C) && "matrix number multiplication went wrong");
			
		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };
			math::Vector3 v{ 1.6f, 56.3f, 2.9f };

			math::Vector3 C{2123.f, 3171.7f, 2450.2};
			ASSERT(vector3_compare(A * v, C)  && "matrix vector multiplication went wrong");
		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };
			ASSERT(matrix_compare(math::inverse_of(A) * A, math::identity_mat3()) && "matrix inversion went wrong");
			ASSERT(matrix_compare(math::invert(A) * A, math::identity_mat3()) && "matrix inversion went wrong");
		}

		{
			math::Mat3 A{ 5, 8, 574,
						47, 55, 0,
						2, 43, 9, };

			//ASSERT(matrix_compare(math::transpose_of(A) * A, math::identity_mat3()) && "matrix inversion went wrong");
			//ASSERT(matrix_compare(math::transpose(A) * A, math::identity_mat3()) && "matrix inversion went wrong");
		}
		log_manager::log(log_manager::MessageChannel::SYSTEM, "All math tests passed");
	}

	void memory_manager_test()
	{

	}

}


