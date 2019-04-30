#pragma once
#include "types.h"

namespace inituari {
	namespace math {
		struct Vector4
		{
			f32 x, y, z, w;
		};
		struct Vector4_simd
		{
			//f32 x, y, z, w;
		};
		struct Vector3;

		Vector4 vector4(f32 x, f32 y, f32 z, f32 w);
		Vector4 vector4(Vector3 xyz, f32 w);
		/*w component will be 1*/
		Vector4 vector4(Vector3 xyz);

		/*Adds a and b and returns a new vector*/
		Vector4 operator+(const Vector4& a, const Vector4& b);

		/*Subtracts a and b and returns a new vector*/
		Vector4 operator-(const Vector4& a, const Vector4& b);

		/*Multuplies a and b and returns a new vector*/
		Vector4 operator*(const Vector4& a, const Vector4& b);

		/*Adds a and b and returns a new vector*/
		Vector4 operator+(const Vector4& a, const Vector3& b);

		/*Subtracts a and b and returns a new vector*/
		Vector4 operator-(const Vector4& a, const Vector3& b);

		/*Multuplies a and b and returns a new vector*/
		Vector4 operator*(const Vector4& a, const Vector3& b);

		/*Divides a and b and returns a new vector*/
		//Vector3 operator/(const Vector3& a, const Vector3& b);

		/*Multiplies vec and num and returns a new vector*/
		Vector4 operator*(const Vector4& vec, f32 num);

		/*Divides vec and num and returns a new vector*/
		Vector4 operator/(const Vector4& vec, f32 num);

		/*Multiplies a and b*/
		Vector4& operator*=(Vector4& a, const Vector4& b);

		/*Adds a and b*/
		Vector4& operator+=(Vector4& a, const Vector4& b);

		/*Multiplies a and b*/
		Vector4& operator*=(Vector4& a, const Vector3& b);

		/*Adds a and b*/
		Vector4& operator+=(Vector4& a, const Vector3& b);

		/*Multiplies a and b*/
		Vector4& operator*=(Vector4& a, const f32 num);

		/*Returns true if a and b are equal with an epsilon difference*/
		//bool& operator==(const Vector3& a, const Vector3& b);

		/*Returns the magnitude of a vector*/
		f32 magnitude(const Vector4& vec);

		/*Returns the Magnitude squared*/
		f32 magnitude_squared(const Vector4& vec);


		/*Returs an unit vector of vec*/
		Vector4 unit(const Vector4& vec);

		//quaternion direction(const Vector3& a);
	}
}

