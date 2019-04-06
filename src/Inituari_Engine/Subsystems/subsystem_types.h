#pragma once
#include "subsystem_manager.h"

#include "log_manager.h"

namespace inituari{
	namespace subsystems {
		//forward declarations
		struct SubsystemManager;
		struct LogManager;
		struct MemoryManager;
		struct RenderingManager;

		//Subsystem structs
		struct SubsystemManager {
		public:
			LogManager* m_logManager;
		};

		struct MemoryManager {

		};

		struct LogManager {
			//TODO make dynamic array
			//void(*log_functions [3])(log_manager::LogInfo);

		};
	}
}