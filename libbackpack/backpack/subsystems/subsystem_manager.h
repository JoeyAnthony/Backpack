#pragma once

#include "log_manager.h"
#include "memory_manager.h"
#include "memory/allocators.h"

//Subsystem manager global
struct SubsystemManager {
public:
	MemoryManager g_memoryManager;
};

namespace backpack {

	//forward declarations
	struct LogManager;
	struct MemoryManager;

	//namespace sunsystem_types { struct SubsystemManager; }

	/*TODO functions to attach and detach subsystems*/

	void initialize(SubsystemManager& mng);

	/*#####DO NOT access subsystems from here#####*/
	namespace detail {

	}
}

extern SubsystemManager g_subsystemManager;
