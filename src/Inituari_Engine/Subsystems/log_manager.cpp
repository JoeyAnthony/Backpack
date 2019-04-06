#include "pch.h"
#include "log_manager.h"
#include <iostream>

#if _MSC_VER
#include <Windows.h>
#endif

namespace inituari {
	namespace log_manager {
		void log(const char * msg)
		{
			
		}
		void log(const char * msg, MessageTag tag)
		{
		}
		void log_console(const char * msg)
		{
		}
		void log_console(const char * msg, MessageTag tag)
		{
		}
		void log_file(const char * msg)
		{
		}
		void log_file(const char * msg, MessageTag tag)
		{
		}
		void register_log_callback(void(*logFunc)(LogInfo))
		{
		}
		void deregister_log_callback(void(*logFunc)(LogInfo))
		{
		}
	}

	namespace log_function {

	}
}

void inituari::log_manager::log_functions::log_to_console(LogInfo info)
{
	//std::cout << info.
}

void inituari::log_manager::log_functions::log_to_file(LogInfo info)
{
}
