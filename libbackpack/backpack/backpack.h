#pragma once

#include "core/types.h"
#include "core/timer.h"
#include "subsystems/log_manager.h"
#include "subsystems/memory_manager.h"
#include "subsystems/subsystem_manager.h"

void* operator new[](size_t size, const char* pName, int flags, unsigned     debugFlags, const char* file, int line)
{
    return malloc(size);
}

void* operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
    return malloc(size);
}