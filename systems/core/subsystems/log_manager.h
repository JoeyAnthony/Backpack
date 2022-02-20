#pragma once
#include <sstream>

enum class MessageChannel { SYSTEM, MESSAGE, WARNING, ASSERT, ERROR };

/*struct for easier message passing with function pointers*/
struct LogInfo {
	const char* m_msg;
	short m_color;
	MessageChannel m_tag;
};

struct LogManager {
	//TODO make dynamic array
	short index = 0;
	void(*logFunctions[3])(LogInfo const& info);
};

namespace log_manager {
	/*logs a message with all log functions, not implemented*/
	void log(_Printf_format_string_ const char* fmt, ...);

	/*logs a message with all log functions*/
	void log(MessageChannel tag, _Printf_format_string_ const char* fmt, ...);

	/*logs a message with all log functions*/
	void log(MessageChannel tag, short color, _Printf_format_string_ const char* fmt, ...);

	/*registers a callback to a logging function*/
	void register_log_output(LogManager& mgr, void(*func)(LogInfo const& info));

	/*deregisters a callback to a logging function*/
	void deregister_log_callback(void(*logFunc)(LogInfo));

	namespace log_functions_detailed {
		/*logs to the console*/
		void print_to_console(LogInfo const& info);
		/*logs to a file*/
		void print_to_file(LogInfo const& info);

		inline const char* message_tag_string(MessageChannel tag)
		{
			switch (tag) {
			case MessageChannel::SYSTEM: return "SYSTEM";
			case MessageChannel::MESSAGE: return "MESSAGE";
			case MessageChannel::WARNING: return "WARNING";
			case MessageChannel::ASSERT: return "ASSERT";
			case MessageChannel::ERROR: return "ERROR";
			default: return "MESSAGE";
			}
		}

		/*INITIALIZE LOGMANAGER*/
		void initialize_log_manager(LogManager& mng);

	}// end namespace log_functions_detailed
}// end namespace log_manager