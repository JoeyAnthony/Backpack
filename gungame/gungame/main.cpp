#pragma once
#include "backpack/backpack.h"
#include "backpack/world/world.h"

namespace bp = backpack;

int main() {

	// Initalize engine
	SubsystemManager subsystemManager;
	bp::initialize(subsystemManager);
	bp::LOG << "dd";
	bp::BP_World world;

	// Initialize game00
	
	return 0;
}