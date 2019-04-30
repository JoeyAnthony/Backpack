#pragma once
#include "types.h"

namespace inituari {
	namespace math {
		struct Mat4 {
			union {
				f32	m00, m01, m02, m03,
					m10, m11, m12, m13,
					m20, m21, m22, m23,
					m30, m31, m32, m33;
			};
			float data[16];
		};
		struct Vector4;


		Mat4 operator+(const Mat4& a, const Mat4& b);
		Mat4 operator-(const Mat4& a, const Mat4& b);
		Mat4 operator*(const Mat4& a, const Mat4& b);
		Mat4 operator*(const Mat4& a, f32 b);

		Mat4& operator+=(Mat4& a, const Mat4& b);
		Mat4& operator-=(Mat4& a, const Mat4& b);
		Mat4& operator*=(Mat4& a, const Mat4& b);
		Mat4& operator*=(Mat4& a, f32 b);

		Mat4 operator*(const Mat4 a, Vector4 b);

		Mat4 inverse(const Mat4 a);
		Mat4& inverse(Mat4& a);

		Mat4 transpose(const Mat4 a);
		Mat4& transpose(Mat4& a);

		f32 determinant(const Mat4& a);

		Mat4 identity_mat4();
	}
}