#pragma once

#include "log_manager.h"
#include "memory_manager.h"
#include "Memory/allocators.h"

struct SubsystemManager;

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

//Subsystem manager global
struct SubsystemManager {
public:
	MemoryManager g_memoryManager;
};
extern SubsystemManager g_subsystemManager;
