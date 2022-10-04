#include "iostream"
#include "core/engine.h"
#include "subsystems/subsystem_manager.h"

namespace backpack {

	void INIT_ENGINE()
	{
		//initialize subsystemmanager
		backpack::initialize(g_subsystemManager);


		//TODO initialize editor
	}
}
