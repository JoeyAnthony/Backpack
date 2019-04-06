#pragma once
#include "subsystem_types.h"
#include <sstream>

namespace inituari {
	namespace log_manager {
		enum class MessageType{SYSTEM, MESSAGE, WARNING, ASSERT, ERROR};
		struct LogInfo {
			char* m_msg;
			short m_color;
			MessageType m_tag;
		};

		/*logs a message with all log functions, not implemented*/ //TODO printf formatting
		void log( _Printf_format_string_ const char* fmt, ...);

		/*logs a message with all log functions*/
		void log(MessageType tag, _Printf_format_string_ const char* fmt, ...);

		/*logs a message with all log functions*/
		void log(MessageType tag, short color, _Printf_format_string_ const char* fmt, ...);

		/*registers a callback to a logging function*/
		void register_log_callback(void(*logFunc)(LogInfo));

		/*deregisters a callback to a logging function*/
		void deregister_log_callback(void(*logFunc)(LogInfo));

		namespace log_functions {
			/*logs to the console*/
			void print_to_console(LogInfo info);
			/*logs to a file*/
			void print_to_file(LogInfo info);

			inline const char* message_tag_string (MessageType tag)
			{	
				switch (tag) {
				case MessageType::SYSTEM: return "SYSTEM";
				case MessageType::MESSAGE: return "MESSAGE";
				case MessageType::WARNING: return "WARNING";
				case MessageType::ASSERT: return "ASSERT";
				case MessageType::ERROR : return "ERROR";
				}
			}
		}
	}
}