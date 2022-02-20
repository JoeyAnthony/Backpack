#include "allocators.h"
#include "Subsystems/log_manager.h"

Allocator::Allocator(Allocator const& alloc)
{
	log_manager::log(MessageChannel::WARNING, "Copying allocator! Better not do this");
}

