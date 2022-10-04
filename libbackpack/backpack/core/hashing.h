#pragma once
#include <stdint.h>

namespace backpack {

	class UniqueNumber {
		uint64_t current_num = 0;

	public:
		uint64_t GetNewId();
	};
}