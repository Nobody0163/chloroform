#pragma once

namespace Chloroform::Math {
	class Vector2 {
	public:
		double x;
		double y;

		Vector2(double x, double y);

		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(double other) const;
		Vector2 operator*(const Vector2& other) const;
		Vector2 operator/(double other) const;
		Vector2 operator/(const Vector2& other) const;
		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;
		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(double other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(double other);
		Vector2& operator/=(const Vector2& other);

		double Dot(const Vector2& other) const;
		double Length() const;
		double LengthSquared() const;
		void Normalize();
		Vector2 Normalized() const;
		void Rotate(double angle);
		Vector2 Rotated(double angle) const;
	};
}