#include "pch.h"

#include "subsystem_manager.h"
#include "log_manager.h"
#include "memory_manager.h"

namespace inituari {
	namespace subsystem_manager {

		void initialize(SubsystemManager& mng)
		{
			//g_subsystemManager.g_logManager = new log_manager::LogManager();

			//TODO depending on engine settings maybe? idk
			log_manager::log_functions_detailed::initialize_log_manager(mng.g_logManager);
			log_manager::log(log_manager::MessageChannel::SYSTEM, "Now using logmanager for logging");
			log_manager::log(log_manager::MessageChannel::SYSTEM, "Start Initializing subsystems...");
			///
			//g_subsystemManager.g_memoryManager = new memory_manager::MemoryManager();


			///
			log_manager::log(log_manager::MessageChannel::SYSTEM, "Finished Initializing subsystems");
		}
	}
}

//declaration of the subsystemManager
SubsystemManager g_subsystemManager;
