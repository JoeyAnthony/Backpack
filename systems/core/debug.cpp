#include "debug.h"
#include "Subsystems/log_manager.h"

void assert_fail(const char* file, int line, const char* fmt, ...)
{
	backpack::LOG_S(BP_ASSERT) << fmt;
	backpack::LOG_S(BP_ASSERT) << "FILE: %c : LINE %i", file, line;
	debug_break();
}
