#include "pch.h"
#include "allocators.h"
#include "Subsystems/log_manager.h"

IIAllocator::IIAllocator(IIAllocator const & alloc)
{
	log_manager::log(log_manager::MessageChannel::WARNING, "Copying allocator! Better not do this");
}
