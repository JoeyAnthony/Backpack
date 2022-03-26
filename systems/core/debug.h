#pragma once
#include <iostream>

#if ASSERTIONS_ENABLED

//if on msvc
#if _MSC_VER
#define debug_break() __debugbreak() ;
#else
#define debug_break raise(SIGTRAP);
#endif

	//assertion function
#define ASSERT(expr) \
	if(expr){} \
	else { \
		assert_fail(__FILE__, __LINE__, #expr);\
	}
#else
#define ASSERT()
#endif

void assert_fail(const char* file, int line, _Printf_format_string_ const char* fmt, ...);
