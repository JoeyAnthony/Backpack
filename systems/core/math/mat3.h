#pragma once
#include "types.h"

struct Vector3;
namespace math {
	struct Mat3 {
		union {
			struct {
				f32	m00, m01, m02,
					m10, m11, m12,
					m20, m21, m22;
			};
		};
		f32 data[9];

		inline Mat3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
			:m00(m00), m01(m01), m02(m02), m10(m10), m11(m11), m12(m12), m20(m20), m21(m21), m22(m22) {};
	};


	Mat3 operator+(const Mat3& a, const Mat3& b);
	Mat3 operator-(const Mat3& a, const Mat3& b);
	Mat3 operator*(const Mat3& a, const Mat3& b);
	Mat3 operator*(const Mat3& a, const f32 b);

	Mat3& operator+=(Mat3& a, const Mat3& b);
	Mat3& operator-=(Mat3& a, const Mat3& b);
	Mat3& operator*=(Mat3& a, const Mat3& b);
	Mat3& operator*=(Mat3& a, const f32 b);

	/*Returns the inverted matrix*/
	Mat3 inverse_of(const Mat3 a);

	/*Inverts the matrix*/
	Mat3& invert(Mat3& a);

	/*returns the transpose of the matrix*/
	Mat3 transpose_of(const Mat3 a);
	/*transposes the matrix*/
	Mat3& transpose(Mat3& a);

	f32 determinant(const Mat3& a);

	Mat3 identity_mat3();
}
