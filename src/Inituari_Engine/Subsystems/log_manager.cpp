#include "pch.h"
#include "log_manager.h"
#include <iostream>
#include <iomanip>

#if _MSC_VER
#include <Windows.h>
#endif

namespace inituari {
	namespace log_manager {
		void log(const char * fmt, ...)
		{
			log(MessageType::MESSAGE, fmt);
		}

		void log(MessageType tag, const char * fmt, ...)
		{
			log(tag, 0, fmt);
		}

		void log(MessageType tag, short color, const char * fmt, ...)
		{
			va_list args;

			va_start(args, fmt);
			int len = _vscprintf(fmt, args) + 1;
			//TODO use allocator for this one, NOT NEW
			char* msg = new char[len];
			vsprintf_s(msg, len, fmt, args);

			LogInfo info{ msg, color, tag};

			//TODO
			//get logmanager from subsystemmanager
			//print message to all channels

			delete[] msg;
		}


		void register_log_callback(void(*logFunc)(LogInfo))
		{
		}
		void deregister_log_callback(void(*logFunc)(LogInfo))
		{
		}

		namespace log_functions {
			void print_to_console(LogInfo info)
			{
				//https://en.cppreference.com/w/cpp/io/manip/put_time for the time format
				std::time_t time = std::time(nullptr);

				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, info.m_color);
				std::cout << message_tag_string(info.m_tag)  << ": " << info.m_msg << /*time*/ std::put_time(std::localtime(&time), "%b %F %T")  << "/n" << std::endl;
			}

			void print_to_file(LogInfo info)
			{
			}
		}
	}
}


