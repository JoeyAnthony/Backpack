// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "backpack/core/types.h"
#include "backpack/core/engine.h"
#include "unit_tests.h"
#include "backpack/memory/allocators.h"
#include "backpack/containers/array_list.h"
#include "backpack/subsystems/memory_manager.h"
#include "backpack/subsystems/log_manager.h"
#include "backpack/subsystems/subsystem_manager.h"
#include <vector>
#include <chrono>

#include "backpack/Math/vector3.h"
#include "backpack/Math/vector4.h"

#include <immintrin.h>

// Tests
#include "backpack/World/updateloop.h"
//#include "EASTL/vector.h"

using namespace backpack;

class OOPComponent {
	virtual void update() = 0;
};
class HealthComponent: public OOPComponent {
	float health = 100;
public:
	void update() override {
		health -= (std::rand() % 50);
	}
	bool isDead() {
		if (health <= 0) {
			return true;
		}
		return false;
	}
};
class OOPTest {
	float x = 15;
	float y = 80;
	float z = 90;
	float x2 = 15;
	float y2 = 80;
	float z2 = 90;
	float x3 = 15;
	float y3 = 80;
	float z3 = 90;
	float x4 = 15;
	float y4 = 80;
	float z4 = 90;

	HealthComponent health;
public:
	bool alive = true;
	void update() {
		health.update();
		if (health.isDead()) {
			alive = false;
		}
	}
};

class Test {
	std::vector<OOPTest*> oop;
	uint32_t objectCount = 100000;
	uint64_t iterations = 1000000;
	std::chrono::high_resolution_clock::duration OOPElapsed;

public:
	void ExecuteOOPTest() {
		for (int i = 0; i < objectCount; i++) {
			oop.push_back(new OOPTest());
		}

		std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();
		for (int itr = 0; itr < iterations; itr++) {
			// update loop
			int size = oop.size();
			for (int i = 0; i < size; i++) {
				oop[i]->update();
			}

			for (int i = 0; i < size; i++) {
				if (!oop[i]->alive) {
					oop.erase(oop.begin() + i);
				}
			}

			int addUp = objectCount - oop.size();
			for (int i = 0; i < addUp; i++) {
				oop.push_back(new OOPTest());
			}
			BP_LOG(BP_INFO, CYAN) << "Iteration: " << itr;
		}
		oop.clear();
		BP_LOG(BP_INFO, CYAN) << "Finished OOP test";

		std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();
		OOPElapsed = after - before;
		BP_LOG(BP_INFO, CYAN) << "Seconds: " << std::chrono::duration_cast<std::chrono::seconds>(OOPElapsed).count() << " nano: " << OOPElapsed.count();
	}
};

	int main()
	{
		//Quick tests
		UpdateLoop loop;
		initUpdateLoop(loop);
		updateFrameTime(loop);


		// Tests
		backpack::INIT_ENGINE();
		//run_all_tests();

		std::cout << "Hello World!\n";

		//for (int k = 1; k < 255; k++)
		//{
		//	BP_LOG(BP_INFO, k) << "noooo";
		//}




		//MallocAllocator alloc;

		//ArrayList<s32> a(&alloc);
		//array_list::push_back(a, 4);

		//inituari::ArrayList<s32> b = a;
		
		//LOG << "rftrfh";
		//LOG << "nfhhsoooo";
		//LOG << "nosfghfooo";
		//LOG << "nofdooo";
		//LOG << "nofdo " << 5 << " oo";
		//BP_LOG(BP_INFO, RED) << "df";
		//BP_LOG(BP_INFO, BLUE) << "df";
		//BP_LOG(BP_INFO, YELLOW) << "noooo";
		//BP_LOG(BP_INFO, CYAN) << "noooo";
		//BP_LOG(BP_INFO, PURPLE) << "noodfgdfgdfgoo";
		//BP_LOG(BP_INFO, RED) << "noooo";

		//LOG << "address main : " << &alloc;
		////std::cout << "address list : " << &g_subsystemManager.g_memoryManager.allocators[0] <<"\n" ;
		//int beer = 4;
		//int* aap = new int(7);

		////aap = &beer; //pointer itself
		//*aap = 6; //value of pointer


		//LOG << *aap;
		//LOG <<  beer ;


		//math::Vector3 v{5, 6, 7};
		//math::Vector3 v2;
		//
		//v2 = v;

		//LOG << "v : " << v.x << " " << v.y << " " << v.z;
		//LOG << "v2 : " << v2.x << " " << v2.y << " " << v2.z;

		//LOG << "v : " << &v;
		//LOG << "v2 : " << &v2;

		return 0;
	}