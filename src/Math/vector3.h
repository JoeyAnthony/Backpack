#pragma once
#include "types.h"
#include "mat3.h"
//#define SIMD false;

//#if SIMD
//		float test;
//#endif

namespace inituari {
	namespace math {

		struct Vector3
		{
			f32 x, y, z;
			Vector3(): x(0), y(0), z(0) {};
			Vector3(f32 x, f32 y, f32 z) : x(x), y(y), z(z){};
		};
		struct Vector3_simd
		{
			//f32 x, y, z;
		};
		struct Vector2;
		struct Vector4;

		Vector3 vector3(f32 x, f32 y, f32 z);
		Vector3 vector3(Vector2& xy, f32 z);
		Vector3 vector3(Vector4& xyz);

		/*Adds a and b and returns a new vector*/
		Vector3 operator+(const Vector3& a, const Vector3& b);

		/*Subtracts a and b and returns a new vector*/
		Vector3 operator-(const Vector3& a, const Vector3& b);

		/*Multuplies a and b and returns a new vector*/
		Vector3 operator*(const Vector3& a, const Vector3& b);

		/*Divides a and b and returns a new vector*/
		//Vector3 operator/(const Vector3& a, const Vector3& b);

		/*Multiplies vec and num and returns a new vector*/
		Vector3 operator*(const Vector3& vec, f32 num);

		/*Divides vec and num and returns a new vector*/
		Vector3 operator/(const Vector3& vec, f32 num);

		inline Vector3 operator*(const Mat3& a, const Vector3& b)
		{
			return Vector3{ a.m00 * b.x + a.m01 * b.y + a.m02 * b.z,
							a.m10 * b.x + a.m11 * b.y + a.m12 * b.z,
							a.m20 * b.x + a.m21 * b.y + a.m22 * b.z };

		}

		/*Multiplies a and b*/
		Vector3& operator*=(Vector3& a, const Vector3& b);

		/*Adds a and b*/
		Vector3& operator+=(Vector3& a, const Vector3& b);

		/*Multiplies a and b*/
		Vector3& operator*=(Vector3& a, const f32 b);

		/*Returns true if a and b are equal with an epsilon difference*/
		//bool& operator==(const Vector3& a, const Vector3& b);

		/*Returns the magnitude of a vector*/
		f32 magnitude(const Vector3& vec);

		/*Returns the Magnitude squared*/
		f32 magnitude_squared(const Vector3& vec);

		/*Returns the dot product*/
		f32 dot(const Vector3& a, const Vector3& b);

		/*Returns the cross product*/
		Vector3 cross(const Vector3& a, const Vector3& b);

		/*Returs an unit vector of vec*/
		Vector3 unit(const Vector3& vec);

		//quaternion direction(const Vector3& a);
	}
}