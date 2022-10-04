#pragma once
#include "../types.h"
#define EPSILON 0.00001

namespace math {
	/*Returns the absolute value*/
	f32 abs(f32 num);
	/*Returns absolute*/
	s32 abs_intr(s32 num);

	/*	Returns uses an epsilon compare to determine if the floats are the same.
		standard epsilon value = 0.00001*/
	bool epsilon_compare(f32 a, f32 b, f32 epsilon = EPSILON);

	/*fast square root*/
	f32 sqrt(f32 num);

	f32 sin(f32 num);
	f32 cos(f32 num);
	f32 tan(f32 num);

	f32 asin(f32 num);
	f32 acos(f32 num);
	f32 atan(f32 num);
	f32 atan2(f32 a, f32 b);
}
