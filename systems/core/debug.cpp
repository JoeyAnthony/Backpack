#include "debug.h"
#include "Subsystems/log_manager.h"

void assert_fail(const char* file, int line, const char* fmt, ...)
{
	log_manager::log(MessageChannel::ASSERT, fmt);
	log_manager::log(MessageChannel::ASSERT, "FILE: %c : LINE %i", file, line);
	debug_break();
}
