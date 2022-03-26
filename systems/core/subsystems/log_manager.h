#pragma once
#include <sstream>
#include "logger.h"

namespace backpack {
// All settings
#define BP_LOG(severity, color) Logger().LogWithSettings(severity, color, __FILE__, __LINE__)
// Severity
#define LOG_S(severity)			BP_LOG(severity, DEFAULT)
// Default
#define LOG						LOG_S(BP_INFO)
}
