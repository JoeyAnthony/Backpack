#pragma once
#include "types.h"

namespace inituari {
	namespace math {
		struct Mat4 {
			union {
				struct {
					f32	m00, m01, m02, m03,
						m10, m11, m12, m13,
						m20, m21, m22, m23,
						m30, m31, m32, m33;
				};
			};
			float data[16];

			inline Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, 
				float m20, float m21, float m22, float m23, float m30, float m31,  float m32, float m33)
				:m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13),
				m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33) {};
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
		Mat4& invert(Mat4& a);

		Mat4 transpose(const Mat4 a);
		Mat4& transpose(Mat4& a);

		f32 determinant(const Mat4& a);

		Mat4 identity_mat4();
	}
}