#include "pch.h"
#include <iostream>

#include "Engine.h"

#include "Subsystems/subsystem_manager.h"

namespace inituari {

	void INIT_ENGINE()
	{
		//initialize subsystemmanager
		subsystem_manager::initialize(g_subsystemManager);


		//TODO initialize editor
	}
}
