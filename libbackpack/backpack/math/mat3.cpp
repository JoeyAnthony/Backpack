#include "Mat3.h"
#include "vector3.h"

namespace math {
	Mat3 operator+(const Mat3& a, const Mat3& b)
	{
		return Mat3{ a.m00 + b.m00,	a.m01 + b.m01,	a.m02 + b.m02,
					 a.m10 + b.m10,	a.m11 + b.m11,	a.m12 + b.m12,
					 a.m20 + b.m20,	a.m21 + b.m21,	a.m22 + b.m22 };
	}
	Mat3 operator-(const Mat3& a, const Mat3& b)
	{
		return Mat3{ a.m00 - b.m00,	a.m01 - b.m01,	a.m02 - b.m02,
					 a.m10 - b.m10,	a.m11 - b.m11,	a.m12 - b.m12,
					 a.m20 - b.m20,	a.m21 - b.m21,	a.m22 - b.m22 };
	}
	Mat3 operator*(const Mat3& a, const Mat3& b)
	{
		return Mat3{ a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20,		//[x] [x] [x]
					 a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21,		//[] [] []
					 a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22,		//[] [] []

					 a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20,		//[] [] []
					 a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21,		//[x] [x] [x]
					 a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22,		//[] [] []

					 a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20,		//[] [] []
					 a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21,		//[] [] []
					 a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 };	//[x] [x] [x]
	}
	Mat3 operator*(const Mat3& a, const f32 b)
	{
		return Mat3{ a.m00 * b,	a.m01 * b,	a.m02 * b,
					 a.m10 * b,	a.m11 * b,	a.m12 * b,
					 a.m20 * b,	a.m21 * b,	a.m22 * b };
	}
	Mat3& operator+=(Mat3& a, const Mat3& b)
	{
		a.m00 += b.m00;
		a.m01 += b.m01;
		a.m02 += b.m02;
		a.m10 += b.m10;
		a.m11 += b.m11;
		a.m12 += b.m12;
		a.m20 += b.m20;
		a.m21 += b.m21;
		a.m22 += b.m22;

		return a;
	}
	Mat3& operator-=(Mat3& a, const Mat3& b)
	{
		a.m00 -= b.m00;
		a.m01 -= b.m01;
		a.m02 -= b.m02;
		a.m10 -= b.m10;
		a.m11 -= b.m11;
		a.m12 -= b.m12;
		a.m20 -= b.m20;
		a.m21 -= b.m21;
		a.m22 -= b.m22;

		return a;
	}
	Mat3& operator*=(Mat3& a, const Mat3& b)
	{
		a = Mat3{ a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20,		//[x] [x] [x]
					 a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21,		//[] [] []
					 a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22,		//[] [] []

					 a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20,		//[] [] []
					 a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21,		//[x] [x] [x]
					 a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22,		//[] [] []

					 a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20,		//[] [] []
					 a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21,		//[] [] []
					 a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 };	//[x] [x] [x]

		return a;
	}
	Mat3& operator*=(Mat3& a, const f32 b)
	{
		a.m00 *= b;
		a.m01 *= b;
		a.m02 *= b;
		a.m10 *= b;
		a.m11 *= b;
		a.m12 *= b;
		a.m20 *= b;
		a.m21 *= b;
		a.m22 *= b;

		return a;
	}

	Mat3 inverse_of(const Mat3 a)
	{
		f32 m00 = a.m11 * a.m22 - a.m12 * a.m21;
		f32 m01 = -(a.m10 * a.m22 - a.m12 * a.m20);
		f32 m02 = a.m10 * a.m21 - a.m11 * a.m20;

		f32 m10 = -(a.m01 * a.m22 - a.m02 * a.m21);
		f32 m11 = a.m00 * a.m22 - a.m02 * a.m20;
		f32 m12 = -(a.m00 * a.m21 - a.m01 * a.m20);

		f32 m20 = a.m01 * a.m12 - a.m02 * a.m11;
		f32 m21 = -(a.m00 * a.m12 - a.m02 * a.m10);
		f32 m22 = a.m00 * a.m11 - a.m01 * a.m10;

		f32 det = m00 * a.m00 + m01 * a.m01 + m02 * a.m02
			+ m10 * a.m10 + m11 * a.m11 + m12 * a.m12
			+ m20 * a.m20 + m21 * a.m21 + m22 * a.m22;

		Mat3 adjugate{ m00, m10, m20,
						m01, m11, m21,
						m02, m12, m22 };

		return adjugate * (1 / det);
	}
	Mat3& invert(Mat3& a)
	{
		//matrix of cofactors
		f32 m00 = a.m11 * a.m22 - a.m12 * a.m21;
		f32 m01 = -(a.m10 * a.m22 - a.m12 * a.m20);
		f32 m02 = a.m10 * a.m21 - a.m11 * a.m20;

		f32 m10 = -(a.m01 * a.m22 - a.m02 * a.m21);
		f32 m11 = a.m00 * a.m22 - a.m02 * a.m20;
		f32 m12 = -(a.m00 * a.m21 - a.m01 * a.m20);

		f32 m20 = a.m01 * a.m12 - a.m02 * a.m11;
		f32 m21 = -(a.m00 * a.m12 - a.m02 * a.m10);
		f32 m22 = a.m00 * a.m11 - a.m01 * a.m10;

		//determinant is original multiplied by the cofactors
		f32 det = m00 * a.m00 + m01 * a.m01 + m02 * a.m02
			+ m10 * a.m10 + m11 * a.m11 + m12 * a.m12
			+ m20 * a.m20 + m21 * a.m21 + m22 * a.m22;

		Mat3 adjugate{ m00, m10, m20,
					   m01, m11, m21,
					   m02, m12, m22 }; //transposed matrix of cofactors

		a = adjugate * (1 / det); //multiply by 1/determinant

		return a;
	}
	Mat3 transpose_of(const Mat3 a)
	{
		return { a.m00, a.m10, a.m20,
				 a.m01, a.m11, a.m21,
				 a.m02, a.m12, a.m22 };
	}
	Mat3& transpose(Mat3& a)
	{
		a = Mat3{ a.m00, a.m10, a.m20,
				  a.m01, a.m11, a.m21,
				  a.m02, a.m12, a.m22 };

		return a;
	}
	f32 determinant(const Mat3& a)
	{
		return	a.m00 * (a.m11 * a.m22 - a.m12 * a.m21) -
			a.m01 * (a.m10 * a.m22 - a.m12 * a.m20) +
			a.m02 * (a.m10 * a.m21 - a.m11 * a.m20);
	}
	Mat3 identity_mat3()
	{
		return Mat3{ 1, 0, 0,
					 0, 1, 0,
					 0, 0, 1 };
	}
}