#include "hashing.h"

uint64_t backpack::UniqueNumber::GetNewId()
{
	uint64_t num = current_num;
	current_num++;
	return num;
};
