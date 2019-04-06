#pragma once
#include <iostream>

namespace inituari {

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
		std::cout << __FILE__ << ", " << __LINE__ << std::endl; \
		debug_break() \
	}

#endif
}