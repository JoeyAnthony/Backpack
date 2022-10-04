#include "debug.h"
#include "Subsystems/log_manager.h"

#ifdef WIN32
#define DEBUGBREAK DebugBreak();
#else
// No implementation
#endif // WIN32


void assert_fail(const char* file, int line, _Printf_format_string_ const char* fmt, ...)
{
	backpack::LOG_S(BP_ASSERT) << fmt;
	backpack::LOG_S(BP_ASSERT) << "FILE: %c : LINE %i", file, line;
	DEBUGBREAK;
}
