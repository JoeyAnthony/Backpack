#pragma once
#include "types.h"
#define EPSILON 0.00001

namespace inituari {
	/*Returns the absolute value*/
	f32 abs(f32 a);

	/*	Returns uses an epsilon compare to determine if the floats are the same.
		standard epsilon value = 0.00001*/
	bool epsilon_compare(f32 a, f32 b, f32 epsilon = EPSILON);

	/*fast square root*/
	f32 sqrt(f32 num);

}

