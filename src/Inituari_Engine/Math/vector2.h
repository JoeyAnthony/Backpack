#pragma once
#include "types.h"
namespace inituari {
	namespace math {
		struct Vector2
		{
			f32 x, y;
		};
		struct Vector2_simd
		{
			//f32 x, y;
		};

		Vector2 vector2(f32 x, f32 y);

		/*Adds a and b and returns a new vector*/
		Vector2 operator+(const Vector2& a, const Vector2& b);

		/*Subtracts a and b and returns a new vector*/
		Vector2 operator-(const Vector2& a, const Vector2& b);

		/*Multuplies a and b and returns a new vector*/
		Vector2 operator*(const Vector2& a, const Vector2& b);

		/*Divides a and b and returns a new vector*/
		//vector3 operator/(const vector3& a, const vector3& b);

		/*Multiplies vec and num and returns a new vector*/
		Vector2 operator*(const Vector2& vec, f32 num);

		/*Divides vec and num and returns a new vector*/
		Vector2 operator/(const Vector2& vec, f32 num);

		/*Multiplies a and b*/
		Vector2& operator*=(Vector2& a, const Vector2& b);

		/*Adds a and b*/
		Vector2& operator+=(Vector2& a, const Vector2& b);

		/*Multiplies a and b*/
		Vector2& operator*=(Vector2& a, const f32 num);

		/*Returns true if a and b are equal with an epsilon difference*/
		//bool& operator==(const vector3& a, const vector3& b);

		/*Returns the magnitude of a vector*/
		f32 magnitude(const Vector2& vec);

		/*Returns the Magnitude squared*/
		f32 magnitude_squared(const Vector2& vec);

		/*Returns the dot product*/
		f32 dot(const Vector2& a, const Vector2& b);

		/*Returs an unit vector of vec*/
		Vector2 unit(const Vector2& vec);

		//quaternion direction(const vector3& a);
	}
}
