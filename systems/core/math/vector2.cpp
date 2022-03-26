#include "Vector2.h"
#include "math.h"

namespace math {
	Vector2 vector2(f32 x, f32 y)
	{
		return Vector2{ x, y };
	}
	Vector2 operator+(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x + b.x, a.y + b.y };
	}
	Vector2 operator-(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x - b.x, a.y - b.y };
	}
	Vector2 operator*(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x * b.x, a.y * b.y };
	}
	Vector2 operator*(const Vector2& vec, f32 num)
	{
		return Vector2{ vec.x * num, vec.y * num };
	}
	Vector2 operator/(const Vector2& vec, f32 num)
	{
		return Vector2{ vec.x / num, vec.y / num };
	}
	Vector2& operator*=(Vector2& a, const Vector2& b)
	{
		a.x *= b.x;
		a.y *= b.y;

		return a;
	}
	Vector2& operator+=(Vector2& a, const Vector2& b)
	{
		a.x += b.x;
		a.y += b.y;

		return a;
	}
	Vector2& operator*=(Vector2& a, f32 num)
	{
		a.x *= num, a.y *= num;
		return a;
	}
	f32 magnitude(const Vector2& vec)
	{
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}
	f32 magnitude_squared(const Vector2& vec)
	{
		return (vec.x * vec.x + vec.y * vec.y);
	}
	f32 dot(const Vector2& a, const Vector2& b)
	{
		return a.x * b.x + a.y * b.y;
	}
	Vector2 unit(const Vector2& vec)
	{
		return vec / sqrt(vec.x * vec.x + vec.y * vec.y);
	}
}
