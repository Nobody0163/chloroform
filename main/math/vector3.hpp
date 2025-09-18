#pragma once

namespace Chloroform::Math {
	class Vector3 {
	public:
		double x;
		double y;
		double z;

		Vector3(double x, double y, double z);

		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		Vector3 operator*(double other) const;
		Vector3 operator*(const Vector3& other) const;
		Vector3 operator/(double other) const;
		Vector3 operator/(const Vector3& other) const;
		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;
		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(double other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator/=(double other);
		Vector3& operator/=(const Vector3& other);

		Vector3 Cross(const Vector3& other) const;
		double Dot(const Vector3& other) const;
		double Length() const;
		double LengthSquared() const;
		void Normalize();
		Vector3 Normalized() const;
	};
}