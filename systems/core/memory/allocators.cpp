#include "allocators.h"
#include "Subsystems/log_manager.h"

Allocator::Allocator(Allocator const& alloc)
{
	backpack::LOG_S(BP_WARNING) << "Copying allocator! Better not do this";
}

