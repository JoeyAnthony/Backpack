#include "pch.h"
#include "Vector3.h"
#include "vector2.h"
#include "vector4.h"
#include "math.h"

namespace inituari{
	namespace math {
		Vector3 vector3(f32 x, f32 y, f32 z)
		{
			return Vector3{ x, y, z };
		}
		Vector3 vector3(Vector2 & xy, f32 z)
		{
			return Vector3{ xy.x, xy.y, z };
		}
		Vector3 vector3(Vector4 & xyz)
		{
			return Vector3{ xyz.x, xyz.y, xyz.z };
		}
		Vector3 operator+(const Vector3 & a, const Vector3 & b)
		{
			return Vector3{ a.x + b.x, a.y + b.y, a.z + b.z };
		}
		Vector3 operator-(const Vector3 & a, const Vector3 & b)
		{
			return Vector3{ a.x - b.x, a.y - b.y, a.z - b.z };
		}
		Vector3 operator*(const Vector3 & a, const Vector3 & b)
		{
			return Vector3{ a.x * b.x, a.y * b.y, a.z * b.z };
		}
		Vector3 operator*(const Vector3 & vec, f32 num)
		{
			return Vector3{ vec.x * num, vec.y * num, vec.z * num };
		}
		Vector3 operator/(const Vector3 & vec, f32 num)
		{
			return Vector3{ vec.x / num, vec.y / num, vec.z / num };
		}
		Vector3 & operator*=(Vector3 & a, const Vector3 & b)
		{
			a.x *= b.x;
			a.y *= b.y;
			a.z *= b.z;

			return a;
		}
		Vector3 & operator+=(Vector3 & a, const Vector3 & b)
		{
			a.x += b.x;
			a.y += b.y;
			a.z += b.z;

			return a;
		}
		//bool & operator==(const Vector3 & a, const Vector3 & b)
		//{
		//	bool equal = true;
		//	if (!epsilon_compare(a.x, b.x)) equal = false;
		//	if (!epsilon_compare(a.y, b.y)) equal = false;
		//	if (!epsilon_compare(a.z, b.z)) equal = false;
		//	return equal;
		//}
		f32 magnitude(const Vector3 & vec)
		{
			return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
		}
		f32 magnitude_squared(const Vector3 & vec)
		{
			return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		}
		f32 dot(const Vector3& a, const Vector3& b)
		{
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}
		Vector3 cross(const Vector3& a, const Vector3& b)
		{
			Vector3 c;
			c.x = a.y * b.z - a.z * b.y;
			c.y = a.z * b.x - a.x * b.z;
			c.z = a.x * b.y - a.y * b.x;
			return c;
		}
		Vector3 unit(const Vector3 & vec)
		{
			return vec / sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
		}
	}
}
