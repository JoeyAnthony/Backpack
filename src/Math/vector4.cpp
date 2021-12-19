#include "pch.h"
#include "Vector4.h"
#include "vector3.h"
#include "Math/math.h"

namespace inituari {
	namespace math {
		Vector4 vector4(f32 x, f32 y, f32 z, f32 w)
		{
			return Vector4{ x, y, z, w };
		}
		Vector4 vector4(Vector3 xyz, f32 w)
		{
			return Vector4{ xyz.x, xyz.y, xyz.z, w };
		}
		Vector4 vector4(Vector3 xyz)
		{
			return Vector4{ xyz.x, xyz.y, xyz.z, 1.f };
		}
		Vector4 operator+(const Vector4 & a, const Vector4 & b)
		{
			return Vector4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
		}
		Vector4 operator-(const Vector4 & a, const Vector4 & b)
		{
			return Vector4{ a.x - b.x, a.y - b.y, a.z - b.z,  a.w - b.w };
		}
		Vector4 operator*(const Vector4 & a, const Vector4 & b)
		{
			return Vector4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
		}
		Vector4 operator+(const Vector4 & a, const Vector3 & b)
		{
			return Vector4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w };
		}
		Vector4 operator-(const Vector4 & a, const Vector3 & b)
		{
			return Vector4{ a.x - b.x, a.y - b.y, a.z - b.z,  a.w };
		}
		Vector4 operator*(const Vector4 & a, const Vector3 & b)
		{
			return Vector4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w };
		}
		Vector4 operator*(const Vector4 & vec, f32 num)
		{
			return Vector4{ vec.x * num, vec.y * num, vec.z * num, vec.w * num };
		}
		Vector4 operator/(const Vector4 & vec, f32 num)
		{
			return Vector4{ vec.x / num, vec.y / num, vec.z / num, vec.w / num };
		}
		Vector4 & operator*=(Vector4 & a, const Vector4 & b)
		{
			a.x *= b.x;
			a.y *= b.y;
			a.z *= b.z;
			a.w *= b.w;

			return a;
		}
		Vector4 & operator+=(Vector4 & a, const Vector4 & b)
		{
			a.x += b.x;
			a.y += b.y;
			a.z += b.z;
			a.w += b.w;

			return a;
		}
		Vector4 & operator*=(Vector4 & a, const Vector3 & b)
		{
			a.x *= b.x;
			a.y *= b.y;
			a.z *= b.z;

			return a;
		}
		Vector4 & operator+=(Vector4 & a, const Vector3 & b)
		{
			a.x += b.x;
			a.y += b.y;
			a.z += b.z;

			return a;
		}
		Vector4 & operator*=(Vector4 & a, const f32 num)
		{
			a.x *= num;
			a.y *= num;
			a.z *= num;
			a.w *= num;

			return a;
		}
		f32 magnitude(const Vector4 & vec)
		{
			return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w * vec.w);
		}
		f32 magnitude_squared(const Vector4 & vec)
		{
			return (vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w * vec.w);
		}
		f32 dot(const Vector4 & a, const Vector4 & b)
		{
			return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
		}
		Vector4 unit(const Vector4 & vec)
		{
			return vec / sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w * vec.w);
		}
	}
}