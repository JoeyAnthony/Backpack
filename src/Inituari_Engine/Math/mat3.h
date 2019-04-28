#pragma once
#include "types.h"


namespace inituari {
		struct Vector3;
	namespace math {
		struct Mat3 {
			union {
				f32	m00, m01, m02,
					m10, m11, m12,
					m20, m21, m22;
			};
			float data[9];
		};


		Mat3 operator+(const Mat3& a, const Mat3& b);
		Mat3 operator-(const Mat3& a, const Mat3& b);
		Mat3 operator*(const Mat3& a, const Mat3& b);
		Mat3 operator*(const Mat3& a, f32 b);

		Mat3& operator+=(Mat3& a, const Mat3& b);
		Mat3& operator-=(Mat3& a, const Mat3& b);
		Mat3& operator*=(Mat3& a, const Mat3& b);
		Mat3& operator*=(Mat3& a, f32 b);

		Mat3 operator*(const Mat3 a, Vector3 b);

		Mat3 inverse(const Mat3 a);
		Mat3& inverse(Mat3& a);

		Mat3 transpose(const Mat3 a);
		Mat3& transpose(Mat3& a);

		f32 determinant(const Mat3& a);

		Mat3 identity_mat3();
	}
}

