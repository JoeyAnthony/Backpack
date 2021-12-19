#pragma once
#include "pch.h"
#include "mat4.h"
#include "vector4.h"
#include "mat3.h"

namespace inituari {
	namespace math {
		Mat4 operator+(const Mat4 & a, const Mat4 & b)
		{
			return Mat4{ a.m00 + b.m00,	a.m01 + b.m01,	a.m02 + b.m02, a.m03 + b.m03,
						 a.m10 + b.m10,	a.m11 + b.m11,	a.m12 + b.m12, a.m13 + b.m13,
						 a.m20 + b.m20,	a.m21 + b.m21,	a.m22 + b.m22, a.m23 + b.m23,
						 a.m30 + b.m30, a.m31 + b.m31,	a.m32 + b.m32, a.m33 + b.m33 };
		}
		Mat4 operator-(const Mat4 & a, const Mat4 & b)
		{
			return Mat4{ a.m00 - b.m00,	a.m01 - b.m01,	a.m02 - b.m02, a.m03 - b.m03,
						 a.m10 - b.m10,	a.m11 - b.m11,	a.m12 - b.m12, a.m13 - b.m13,
						 a.m20 - b.m20,	a.m21 - b.m21,	a.m22 - b.m22, a.m23 - b.m23,
						 a.m30 - b.m30, a.m31 - b.m31,	a.m32 - b.m32, a.m33 - b.m33 };
		}
		Mat4 operator*(const Mat4 & a, const Mat4 & b)
		{
			return Mat4{ a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30,		//[x] [x] [x] [x]
						 a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31,		//[] [] [] []
						 a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32,		//[] [] [] []
						 a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33,		//[] [] [] []

						 a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30,		//[] [] [] []
						 a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31,		//[x] [x] [x] [x]
						 a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32,		//[] [] [] []
						 a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33,		//[] [] [] []

						 a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30,		//[] [] [] []
						 a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31,		//[] [] [] []
						 a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32,		//[x] [x] [x] [x]
						 a.m20 * b.m03 + a.m21 * b.m13 + a.m23 * b.m23 + a.m23 * b.m33,		//[] [] [] []

						 a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30,		//[] [] [] []
						 a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31,		//[] [] [] []
						 a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32,		//[] [] [] []
						 a.m30 * b.m03 + a.m31 * b.m13 + a.m33 * b.m23 + a.m33 * b.m33 };	//[x] [x] [x] [x]
		}
		Mat4 operator*(const Mat4 & a, f32 b)
		{
			return Mat4{ a.m00 * b,	a.m01 * b,	a.m02 * b, a.m03 * b,
						 a.m10 * b,	a.m11 * b,	a.m12 * b, a.m13 * b,
						 a.m20 * b,	a.m21 * b,	a.m22 * b, a.m23 * b,
						 a.m30 * b, a.m31 * b,	a.m32 * b, a.m33 * b };
		}
		Mat4 & operator+=(Mat4 & a, const Mat4 & b)
		{
			a.m00 += b.m00,
				a.m01 += b.m01;
			a.m02 += b.m02;
			a.m03 += b.m03;
			a.m10 += b.m10;
			a.m11 += b.m11;
			a.m12 += b.m12;
			a.m13 += b.m13;
			a.m20 += b.m20;
			a.m21 += b.m21;
			a.m22 += b.m22;
			a.m23 += b.m23;
			a.m30 += b.m30;
			a.m31 += b.m31;
			a.m32 += b.m32;
			a.m33 += b.m33;

			return a;
		}
		Mat4 & operator-=(Mat4 & a, const Mat4 & b)
		{
			a.m00 -= b.m00,
				a.m01 -= b.m01;
			a.m02 -= b.m02;
			a.m03 -= b.m03;
			a.m10 -= b.m10;
			a.m11 -= b.m11;
			a.m12 -= b.m12;
			a.m13 -= b.m13;
			a.m20 -= b.m20;
			a.m21 -= b.m21;
			a.m22 -= b.m22;
			a.m23 -= b.m23;
			a.m30 -= b.m30;
			a.m31 -= b.m31;
			a.m32 -= b.m32;
			a.m33 -= b.m33;

			return a;
		}
		Mat4 & operator*=(Mat4 & a, const Mat4 & b)
		{
			a.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20, a.m03 * b.m30;	//[x] [x] [x] [x]
			a.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21, a.m03 * b.m31;	//[] [] [] []
			a.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22, a.m03 * b.m32;	//[] [] [] []
			a.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23, a.m03 * b.m33;	//[] [] [] []

			a.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20, a.m13 * b.m30;	//[] [] [] []
			a.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21, a.m13 * b.m31;	//[x] [x] [x] [x]
			a.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22, a.m13 * b.m32;	//[] [] [] []
			a.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23, a.m13 * b.m33;	//[] [] [] []

			a.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;	//[] [] [] []
			a.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;	//[] [] [] []
			a.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;	//[x] [x] [x] [x]
			a.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m23 * b.m23 + a.m23 * b.m33;	//[] [] [] []

			a.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;	//[] [] [] []
			a.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;	//[] [] [] []
			a.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;	//[] [] [] []
			a.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m33 * b.m23 + a.m33 * b.m33;	//[x] [x] [x] [x]

			return a;
		}
		Mat4 & operator*=(Mat4 & a, f32 b)
		{
			a.m00 *= b,
			a.m01 *= b;
			a.m02 *= b;
			a.m03 *= b;
			a.m10 *= b;
			a.m11 *= b;
			a.m12 *= b;
			a.m13 *= b;
			a.m20 *= b;
			a.m21 *= b;
			a.m22 *= b;
			a.m23 *= b;
			a.m30 *= b;
			a.m31 *= b;
			a.m32 *= b;
			a.m33 *= b;

			return a;
		}
		Mat4 operator*(const Mat4 a, Vector4 b)
		{
			return Mat4{ a.m00 * b.x, a.m01 * b.y, a.m02 * b.z, a.m03 * b.w,
						 a.m10 * b.x, a.m11 * b.y, a.m12 * b.z, a.m13 * b.w,
						 a.m20 * b.x, a.m21 * b.y, a.m22 * b.z, a.m23 * b.w,
						 a.m30 * b.x, a.m31 * b.y, a.m32 * b.z, a.m33 * b.w };
		}
		Mat4 inverse(const Mat4 a)
		{
			//matrix of cofactors
			f32 m00 = a.m11*(a.m22 * a.m33 - a.m23 * a.m32) - a.m12*(a.m21 * a.m33 - a.m23 * a.m31) + a.m13*(a.m21 * a.m32 - a.m22 * a.m31);
			f32 m01 = -(a.m10*(a.m22 * a.m33 - a.m23 * a.m32) - a.m12*(a.m20 * a.m33 - a.m23 * a.m30) + a.m13*(a.m20 * a.m32 - a.m22 * a.m30));
			f32 m02 = a.m10*(a.m21 * a.m33 - a.m23 * a.m31) - a.m11*(a.m20 * a.m33 - a.m23 * a.m30) + a.m13*(a.m20 * a.m31 - a.m21 * a.m30);
			f32 m03 = -(a.m10*(a.m21 * a.m32 - a.m22 * a.m31) - a.m11*(a.m20 * a.m32 - a.m22 * a.m30) + a.m12*(a.m20 * a.m31 - a.m21 * a.m30));

			f32 m10 = a.m01*(a.m22 * a.m33 - a.m23 * a.m32) - a.m02*(a.m21 * a.m33 - a.m23 * a.m31) + a.m03*(a.m21 * a.m32 - a.m22 * a.m31);
			f32 m11 = -(a.m00*(a.m22 * a.m33 - a.m23 * a.m32) - a.m02*(a.m20 * a.m33 - a.m23 * a.m30) + a.m03*(a.m20 * a.m32 - a.m22 * a.m30));
			f32 m12 = a.m00*(a.m21 * a.m33 - a.m23 * a.m31) - a.m01*(a.m20 * a.m33 - a.m23 * a.m30) + a.m03*(a.m20 * a.m31 - a.m21 * a.m30);
			f32 m13 = -(a.m00*(a.m21 * a.m32 - a.m22 * a.m31) - a.m01*(a.m20 * a.m32 - a.m22 * a.m30) + a.m02*(a.m20 * a.m31 - a.m21 * a.m30));

			f32 m20 = a.m01*(a.m12 * a.m33 - a.m13 * a.m32) - a.m02*(a.m11 * a.m33 - a.m13 * a.m31) + a.m03*(a.m11 * a.m32 - a.m12 * a.m31);
			f32 m21 = -(a.m00*(a.m12 * a.m33 - a.m13 * a.m32) - a.m02*(a.m10 * a.m33 - a.m13 * a.m30) + a.m03*(a.m10 * a.m32 - a.m12 * a.m30));
			f32 m22 = a.m00*(a.m11 * a.m33 - a.m13 * a.m31) - a.m01*(a.m10 * a.m33 - a.m13 * a.m30) + a.m03*(a.m10 * a.m31 - a.m11 * a.m30);
			f32 m23 = -(a.m00*(a.m11 * a.m32 - a.m12 * a.m31) - a.m01*(a.m10 * a.m32 - a.m12 * a.m30) + a.m02*(a.m10 * a.m31 - a.m11 * a.m30));

			f32 m30 = a.m01*(a.m12 * a.m23 - a.m13 * a.m22) - a.m02*(a.m11 * a.m23 - a.m13 * a.m21) + a.m03*(a.m11 * a.m22 - a.m12 * a.m21);
			f32 m31 = -(a.m00*(a.m12 * a.m23 - a.m13 * a.m22) - a.m02*(a.m10 * a.m23 - a.m13 * a.m20) + a.m03*(a.m10 * a.m22 - a.m12 * a.m20));
			f32 m32 = a.m00*(a.m11 * a.m23 - a.m13 * a.m21) - a.m01*(a.m10 * a.m23 - a.m13 * a.m20) + a.m03*(a.m10 * a.m21 - a.m11 * a.m20);
			f32 m33 = -(a.m00*(a.m11 * a.m22 - a.m12 * a.m21) - a.m01*(a.m10 * a.m22 - a.m12 * a.m20) + a.m02*(a.m10 * a.m21 - a.m11 * a.m20));

			//determinant is original multiplied by the cofactors
			f32 det = m00 * a.m00 + m01 * a.m01 + m02 * a.m02 + m03 * a.m03
				+ m10 * a.m10 + m11 * a.m11 + m12 * a.m12 + m13 * a.m13
				+ m20 * a.m20 + m21 * a.m21 + m22 * a.m22 + m23 * a.m23
				+ m30 * a.m30 + m31 * a.m31 + m32 * a.m32 + m33 * a.m33;

			Mat4 adjugate{ m00, m10, m20, m30,
							m01, m11, m21, m31,
							m02, m12, m22, m32,
							m03, m13, m23, m33 }; //transposed matrix of cofactors

			return adjugate * (1 / det); //multiply by 1/determinant
		}
		Mat4 & invert(Mat4 & a)
		{
			//matrix of cofactors
			f32 m00 = a.m11*(a.m22 * a.m33 - a.m23 * a.m32) - a.m12*(a.m21 * a.m33 - a.m23 * a.m31) + a.m13*(a.m21 * a.m32 - a.m22 * a.m31);
			f32 m01 = -(a.m10*(a.m22 * a.m33 - a.m23 * a.m32) - a.m12*(a.m20 * a.m33 - a.m23 * a.m30) + a.m13*(a.m20 * a.m32 - a.m22 * a.m30));
			f32 m02 = a.m10*(a.m21 * a.m33 - a.m23 * a.m31) - a.m11*(a.m20 * a.m33 - a.m23 * a.m30) + a.m13*(a.m20 * a.m31 - a.m21 * a.m30);
			f32 m03 = -(a.m10*(a.m21 * a.m32 - a.m22 * a.m31) - a.m11*(a.m20 * a.m32 - a.m22 * a.m30) + a.m12*(a.m20 * a.m31 - a.m21 * a.m30));

			f32 m10 = a.m01*(a.m22 * a.m33 - a.m23 * a.m32) - a.m02*(a.m21 * a.m33 - a.m23 * a.m31) + a.m03*(a.m21 * a.m32 - a.m22 * a.m31);
			f32 m11 = -(a.m00*(a.m22 * a.m33 - a.m23 * a.m32) - a.m02*(a.m20 * a.m33 - a.m23 * a.m30) + a.m03*(a.m20 * a.m32 - a.m22 * a.m30));
			f32 m12 = a.m00*(a.m21 * a.m33 - a.m23 * a.m31) - a.m01*(a.m20 * a.m33 - a.m23 * a.m30) + a.m03*(a.m20 * a.m31 - a.m21 * a.m30);
			f32 m13 = -(a.m00*(a.m21 * a.m32 - a.m22 * a.m31) - a.m01*(a.m20 * a.m32 - a.m22 * a.m30) + a.m02*(a.m20 * a.m31 - a.m21 * a.m30));

			f32 m20 = a.m01*(a.m12 * a.m33 - a.m13 * a.m32) - a.m02*(a.m11 * a.m33 - a.m13 * a.m31) + a.m03*(a.m11 * a.m32 - a.m12 * a.m31);
			f32 m21 = -(a.m00*(a.m12 * a.m33 - a.m13 * a.m32) - a.m02*(a.m10 * a.m33 - a.m13 * a.m30) + a.m03*(a.m10 * a.m32 - a.m12 * a.m30));
			f32 m22 = a.m00*(a.m11 * a.m33 - a.m13 * a.m31) - a.m01*(a.m10 * a.m33 - a.m13 * a.m30) + a.m03*(a.m10 * a.m31 - a.m11 * a.m30);
			f32 m23 = -(a.m00*(a.m11 * a.m32 - a.m12 * a.m31) - a.m01*(a.m10 * a.m32 - a.m12 * a.m30) + a.m02*(a.m10 * a.m31 - a.m11 * a.m30));

			f32 m30 = a.m01*(a.m12 * a.m23 - a.m13 * a.m22) - a.m02*(a.m11 * a.m23 - a.m13 * a.m21) + a.m03*(a.m11 * a.m22 - a.m12 * a.m21);
			f32 m31 = -(a.m00*(a.m12 * a.m23 - a.m13 * a.m22) - a.m02*(a.m10 * a.m23 - a.m13 * a.m20) + a.m03*(a.m10 * a.m22 - a.m12 * a.m20));
			f32 m32 = a.m00*(a.m11 * a.m23 - a.m13 * a.m21) - a.m01*(a.m10 * a.m23 - a.m13 * a.m20) + a.m03*(a.m10 * a.m21 - a.m11 * a.m20);
			f32 m33 = -(a.m00*(a.m11 * a.m22 - a.m12 * a.m21) - a.m01*(a.m10 * a.m22 - a.m12 * a.m20) + a.m02*(a.m10 * a.m21 - a.m11 * a.m20));

			//determinant is original multiplied by the cofactors
			f32 det = m00 * a.m00 + m01 * a.m01 + m02 * a.m02 + m03 * a.m03
					+ m10 * a.m10 + m11 * a.m11 + m12 * a.m12 + m13 * a.m13
					+ m20 * a.m20 + m21 * a.m21 + m22 * a.m22 + m23 * a.m23
					+ m30 * a.m30 + m31 * a.m31 + m32 * a.m32 + m33 * a.m33;

			Mat4 adjugate{	m00, m10, m20, m30,
							m01, m11, m21, m31,
							m02, m12, m22, m32,
							m03, m13, m23, m33 }; //transposed matrix of cofactors

			a = adjugate * (1 / det); //multiply by 1/determinant
			return a;
		}
		Mat4 transpose(const Mat4 a)
		{
			return 	Mat4{	a.m00, a.m10, a.m20, a.m30,
							a.m01, a.m11, a.m21, a.m31,
							a.m02, a.m12, a.m22, a.m32,
							a.m03, a.m13, a.m23, a.m33 }; //transposed matrix of cofactors
		}
		Mat4 & transpose(Mat4 & a)
		{
			a =	Mat4{	a.m00, a.m10, a.m20, a.m30,
						a.m01, a.m11, a.m21, a.m31,
						a.m02, a.m12, a.m22, a.m32,
						a.m03, a.m13, a.m23, a.m33 }; //transposed matrix of cofactors]
			return a;
		}
		f32 determinant(const Mat4 & a)
		{
			Mat3 ma{ a.m11, a.m12, a.m13,
					a.m21, a.m22, a.m23,
					a.m31, a.m32, a.m33 };
			Mat3 mb{ a.m10, a.m12, a.m13,
					a.m20, a.m22, a.m23,
					a.m30, a.m32, a.m33 };
			Mat3 mc{ a.m10, a.m11, a.m13,
					a.m20, a.m21, a.m23,
					a.m30, a.m31, a.m33 };
			Mat3 md{ a.m10, a.m11, a.m12,
					a.m20, a.m21, a.m22,
					a.m30, a.m31, a.m32 };

			return a.m00 * determinant(ma) + a.m01 * determinant(mb) +
					a.m02 * determinant(mc) + a.m03 * determinant(md);
		}
	}
}
