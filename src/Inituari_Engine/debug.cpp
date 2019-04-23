#include "pch.h"
#include "debug.h"
#include "Subsystems/log_manager.h"

void inituari::assert_fail(const char * file, int line, const char * fmt, ...)
{
	log_manager::log(log_manager::MessageChannel::ASSERT, fmt);
	log_manager::log(log_manager::MessageChannel::ASSERT, "FILE: %c : LINE %i", file, line);
	debug_break();
}
