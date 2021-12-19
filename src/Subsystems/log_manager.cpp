#include "pch.h"
#include <iostream>
#include <chrono>
#include <ctime>


#include "log_manager.h"
#include "debug.h"
#include "subsystem_manager.h"

#if _MSC_VER
#include <Windows.h>
#endif

	namespace log_manager {
		void log(_Printf_format_string_ const char * fmt, ...)
		{
			log(MessageChannel::MESSAGE, fmt);
		}

		void log(MessageChannel tag, _Printf_format_string_ const char * fmt, ...)
		{
			switch (tag) {
			case MessageChannel::SYSTEM:	{ log(tag, 11, fmt); return; }
			case MessageChannel::MESSAGE:	{ log(tag, 7, fmt); return;	}
			case MessageChannel::WARNING:	{ log(tag, 14, fmt); return; }
			case MessageChannel::ASSERT:	{ log(tag, 13, fmt); return; }
			//case MessageChannel::ERROR:	{ log(tag, 12, fmt); return; }

			}
		}

		void log(MessageChannel tag, short color, _Printf_format_string_ const char * fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			int len = _vscprintf(fmt, args) + 1;
			//TODO use allocator for this one, NOT NEW
			char* msg = new char[len];
			vsprintf_s(msg, len, fmt, args);

			LogInfo info{ msg, color, tag};

			LogManager& mngr = g_subsystemManager.g_logManager;
			for (int i = 0; i < mngr.index; ++i)
			{
				mngr.logFunctions[i](info);
			}

			delete[] msg;
		}

		void register_log_output(LogManager& mgr, void(*func)(LogInfo const& info))
		{
			mgr.logFunctions[mgr.index] = func;
			mgr.index++;
		}

		void deregister_log_callback(void(*logFunc)(LogInfo))
		{
			//TODO implement with dynamic array
		}

		/*DON"T USE FUNCTIONS INSIDE THIS NAMESPACE -> LOGMANAGER ONLY*/
		namespace log_functions_detailed {
			void print_to_console(LogInfo const& info)
			{
				////https://en.cppreference.com/w/cpp/io/manip/put_time for the time format
				std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
				std::time_t time = std::chrono::system_clock::to_time_t(now);
				char buf[30];
				ctime_s(buf, sizeof(buf), &time);

				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, info.m_color);
				
				std::cout << message_tag_string(info.m_tag)  << ": " << info.m_msg << "	" <</*time*/ buf;

				SetConsoleTextAttribute(hConsole, 7); //reset color
			}

			void print_to_file(LogInfo const& info)
			{
			}
			void initialize_log_manager(LogManager & mng)
			{
				//TODO dependent on logmanager settings, file io stuff when that is ready
				register_log_output(mng, print_to_console);
				register_log_output(mng, print_to_file);

				log(MessageChannel::SYSTEM, "Logmanager initialized");
			}
		}
	}


