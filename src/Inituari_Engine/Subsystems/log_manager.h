#pragma once
#include "subsystem_types.h"
#include <sstream>

namespace inituari {
	namespace log_manager {
		enum class MessageTag{SYSTEM, MESSAGE, WARNING, ASSERT, ERROR};
		struct LogInfo {
			char* m_msg;
			short m_color;
			MessageTag m_tag;
		};

		/*logs a message with all log functions, not implemented*/ //TODO printf formatting
		//void log(_Printf_format_string_ const char* fmt, ...);

		/*logs a message with all log functions*/
		void log(const char* msg);

		/*logs a message with all log functions*/
		void log(const char* msg, MessageTag tag);

		/*logs a message to the console*/
		void log_console(const char* msg);

		/*logs a message to the console*/
		void log_console(const char* msg, MessageTag tag);

		/*logs a message to a logfile*/
		void log_file(const char* msg);		
		
		/*logs a message to a logfile*/
		void log_file(const char* msg, MessageTag tag);


		/*registers a callback to a logging function*/
		void register_log_callback(void(*logFunc)(LogInfo));
		/*deregisters a callback to a logging function*/
		void deregister_log_callback(void(*logFunc)(LogInfo));

		namespace log_functions {
			/*logs to the console*/
			void log_to_console(LogInfo info);
			/*logs to a file*/
			void log_to_file(LogInfo info);
		}
	}
}