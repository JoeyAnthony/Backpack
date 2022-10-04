#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <filesystem>

#ifdef WIN32
#include <Windows.h>
#endif // WIN32

enum LogSeverity : short { BP_INFO, BP_WARNING, BP_DEBUG, BP_SYSTEM, BP_ASSERT, BP_ERROR };

#ifdef WIN32
enum LogColor : short {  BLUE=1, GREEN=2, CYAN=3, RED = 4, PURPLE=5, YELLOW=6, DEFAULT = 7};
#else
enum LogColor : short { DEFAULT, RED, BLUE, ORANGE, PURPLE, YELLOW };
#endif // WIN32


namespace backpack {

	class Logger {

		std::stringstream stream;

	public:
		short logColor;

	private:
		std::string GetChanngelString(LogSeverity tag)
		{
			switch (tag) {
			case LogSeverity::BP_INFO: return "INFO";
			case LogSeverity::BP_WARNING: return "WARNING";
			case LogSeverity::BP_DEBUG: return "DEBUG";
			case LogSeverity::BP_SYSTEM: return "SYSTEM";
			case LogSeverity::BP_ASSERT: return "ASSERT";
			default: return "INFO";
			}
		}

	public:

		std::stringstream& LogWithSettings(const LogSeverity& channel = BP_INFO, short color = DEFAULT, const char* file = "", size_t line = 0) {
			logColor = color;
			std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
			std::time_t now_c = std::chrono::system_clock::to_time_t(now);
			std::tm now_tm = *std::localtime(&now_c);
			char buffer[30];
			strftime(buffer, sizeof(buffer), "%F %X", &now_tm);
			
			stream << buffer << " ";
			stream << std::this_thread::get_id() << " ";
			stream << std::filesystem::path(file).filename() << " ";
			stream << line << " ";
			stream << GetChanngelString(channel);
			stream << ": ";
			return stream;
		}

		Logger(): logColor(DEFAULT) {

		}

		~Logger() {
#ifdef WIN32
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, logColor);
#endif // WIN32

			std::cout << stream.str() << std::endl;

#ifdef WIN32
			SetConsoleTextAttribute(hConsole, 7); //reset color
#endif // WIN32
		}
	};

}
