#include "pch.h"
#include "math.h"
#include <immintrin.h>

namespace inituari {
	f32 abs(f32 a)
	{
		if (a < 0)
			return -a;
		return a;
	}

	bool epsilon_compare(f32 a, f32 b, f32 epsilon)
	{
		return (abs(a - b) < epsilon);
	}

	f32 sqrt(f32 num)
	{
		float newNum;

		/*Uses SSE intrinsic to calculate the square root reciprocal really fast and fairly accurate*/
		/*https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2&expand=4799,4799,3340,3340,4799&text=rsqrt*/
		_mm_store_ss(&newNum, _mm_rsqrt_ss(_mm_load_ss(&num)));
		return newNum*num;
	}
}
