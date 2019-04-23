#include "pch.h"
#include "vector3.h"
#include "math.h"

namespace inituari{
	vector3 operator+(const vector3 & a, const vector3 & b)
	{
		return vector3{ a.x + b.x, a.y + b.y, a.z + b.z};
	}
	vector3 operator-(const vector3 & a, const vector3 & b)
	{
		return vector3{ a.x -b.x, a.y -b.y, a.z -b.z };
	}
	vector3 operator*(const vector3 & a, const vector3 & b)
	{
		return vector3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}
	vector3 operator*(const vector3 & vec, u32 num)
	{
		return vector3{ vec.x * num, vec.y * num, vec.z * num };
	}
	vector3 operator/(const vector3 & vec, u32 num)
	{
		return vector3{ vec.x / num, vec.y / num, vec.z / num };
	}
	vector3 & operator*=(vector3 & a, const vector3 & b)
	{
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		
		return a;
	}
	vector3 & operator+=(vector3 & a, const vector3 & b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;

		return a;
	}
	//bool & operator==(const vector3 & a, const vector3 & b)
	//{
	//	bool equal = true;
	//	if (!epsilon_compare(a.x, b.x)) equal = false;
	//	if (!epsilon_compare(a.y, b.y)) equal = false;
	//	if (!epsilon_compare(a.z, b.z)) equal = false;
	//	return equal;
	//}
	f32 magnitude(const vector3 & vec)
	{
		return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
	}
	f32 magnitude_squared(const vector3 & vec)
	{
		return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}
	f32 dot(const vector3& a, const vector3& b)
	{
		return a.x * b.x + a.y * b.y;
	}
	vector3 cross(const vector3& a, const vector3& b)
	{
		vector3 c;
		c.x = a.y * b.z - a.z * b.y;
		c.y = a.z * b.x - a.x * b.z;
		c.z = a.x * b.y - a.y * b.x;
		return c;
	}
	vector3 unit(const vector3 & vec)
	{
		return vec / sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
	}
}
