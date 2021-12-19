#include "pch.h"
#include "math.h"
//#include <immintrin.h>
#include <intrin.h>
#include <cmath>


namespace inituari {
	namespace math {
		f32 abs(f32 num)
		{
			if (num < 0)
				return -num;
			return num;
		}

		s32 abs_intr(s32 num)
		{
			//load - https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2&expand=4799,4799,3340,4799,5593,4799,3340,3413,27,1873&text=cvtsi
			//store - https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2&expand=4799,4799,3340,4799,5593,4799,3340,3413,27,1873,1375,1868&text=cvtsi
			//abs - https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=4799,4799,3340,3340,4799,4850,27,57&text=abs 

			return _mm_cvtsi128_si32(_mm_abs_epi32(_mm_cvtsi32_si128(num)));
		}

		bool epsilon_compare(f32 a, f32 b, f32 epsilon)
		{
			return (abs(a - b) < epsilon);
		}

		f32 sqrt(f32 num)
		{
			f32 newNum;

			/*Uses SSE intrinsic to calculate the square root reciprocal really fast and fairly accurate*/
			/*https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2&expand=4799,4799,3340,3340,4799&text=rsqrt*/
			_mm_store_ss(&newNum, _mm_rsqrt_ss(_mm_load_ss(&num)));
			return newNum * num;
		}

		f32 sin(f32 num)
		{
			return sinf(num);
		}

		f32 cos(f32 num)
		{
			return cosf(num);
		}

		f32 tan(f32 num)
		{
			return tanf(num);
		}

		f32 asin(f32 num)
		{
			return asinf(num);
		}

		f32 acos(f32 num)
		{
			return acosf(num);
		}

		f32 atan(f32 num)
		{
			return atanf(num);
		}

		f32 atan2(f32 a, f32 b)
		{
			return atan2f(a, b);
		}
	}
}
