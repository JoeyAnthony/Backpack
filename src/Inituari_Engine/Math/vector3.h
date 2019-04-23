#pragma once
#include "types.h"
#define SIMD false;
namespace inituari {
#if SIMD
	float yooo;
#endif

	struct vector3
	{
		f32 x, y, z;
	};

	/*Adds a and b and returns a new vector*/
	vector3 operator+(const vector3& a, const vector3& b);

	/*Subtracts a and b and returns a new vector*/
	vector3 operator-(const vector3& a, const vector3& b);

	/*Multuplies a and b and returns a new vector*/
	vector3 operator*(const vector3& a, const vector3& b);

	/*Divides a and b and returns a new vector*/
	//vector3 operator/(const vector3& a, const vector3& b);

	/*Multiplies vec and num and returns a new vector*/
	vector3 operator*(const vector3& vec, u32 num);

	/*Divides vec and num and returns a new vector*/
	vector3 operator/(const vector3& vec, u32 num);

	/*Multiplies a and b*/
	vector3& operator*=(const vector3& a, const vector3& b);

	/*Adds a and b*/
	vector3& operator+=(const vector3& a, const vector3& b);

	/*Returns true if a and b are equal with an epsilon difference*/
	//bool& operator==(const vector3& a, const vector3& b);

	/*Returns the magnitude of a vector*/
	f32 magnitude(const vector3& vec);

	/*Returns the Magnitude squared*/
	f32 magnitude_squared(const vector3& vec);

	/*Returns the dot product*/
	f32 dot(const vector3& a, const vector3& b);

	/*Returns the cross product*/
	vector3 cross(const vector3& a, const vector3& b);

	/*Returs an unit vector of vec*/
	vector3 unit(const vector3& vec);

	//quaternion direction(const vector3& a);
}