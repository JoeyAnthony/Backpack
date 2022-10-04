#include "subsystem_manager.h"
#include "log_manager.h"
#include "memory_manager.h"


namespace backpack {

	void initialize(SubsystemManager& mng)
	{
		//g_subsystemManager.g_logManager = new log_manager::LogManager();

		//TODO depending on engine settings maybe? idk
		backpack::LOG_S(BP_SYSTEM) << "Now using logmanager for logging";
		backpack::LOG_S(BP_SYSTEM) << "Start Initializing subsystems...";
		///
		//g_subsystemManager.g_memoryManager = new memory_manager::MemoryManager();

		///
		backpack::LOG_S(BP_SYSTEM) << "Finished Initializing subsystems";
	}
}

//declaration of the subsystemManager
SubsystemManager g_subsystemManager;
