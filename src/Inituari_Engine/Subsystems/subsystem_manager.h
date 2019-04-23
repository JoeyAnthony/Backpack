#pragma once

#include "log_manager.h"
#include "memory_manager.h"
#include "Memory/allocators.h"

struct SubsystemManager;


namespace inituari {
	//forward declerations
	namespace log_manager { struct LogManager; }
	namespace memory_manager { struct MemoryManager; }

	namespace subsystem_manager {
		//namespace sunsystem_types { struct SubsystemManager; }

		/*TODO functions to attach and detach subsystems*/
			
			void initialize(SubsystemManager& mng);

			/*#####DO NOT access subsystems from here#####*/
			namespace detail {
				
			}
	}
}

//Subsystem manager global
struct SubsystemManager {
public:
	inituari::log_manager::LogManager g_logManager;
	inituari::memory_manager::MemoryManager g_memoryManager;
};
extern SubsystemManager g_subsystemManager;