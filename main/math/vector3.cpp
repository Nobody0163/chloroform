#include "vector3.hpp"

#include <cmath>

namespace Chloroform::Math {
	Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

	Vector3 Vector3::operator+(const Vector3& other) const {
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Vector3 Vector3::operator-(const Vector3& other) const {
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	Vector3 Vector3::operator*(double other) const {
		return Vector3(this->x * other, this->y * other, this->z * other);
	}

	Vector3 Vector3::operator*(const Vector3& other) const {
		return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
	}

	Vector3 Vector3::operator/(double other) const {
		return Vector3(this->x / other, this->y / other, this->z / other);
	}

	Vector3 Vector3::operator/(const Vector3& other) const {
		return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
	}

	bool Vector3::operator==(const Vector3& other) const {
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}

	bool Vector3::operator!=(const Vector3& other) const {
		return !(*this == other);
	}

	Vector3& Vector3::operator+=(const Vector3& other) {
		*this = *this + other;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& other) {
		*this = *this - other;
		return *this;
	}

	Vector3& Vector3::operator*=(double other) {
		*this = *this * other;
		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3& other) {
		*this = *this * other;
		return *this;
	}

	Vector3& Vector3::operator/=(double other) {
		*this = *this / other;
		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3& other) {
		*this = *this / other;
		return *this;
	}

	Vector3 Vector3::Cross(const Vector3& other) const {
		return Vector3(
			this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x
		);
	}

	double Vector3::Dot(const Vector3& other) const {
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}

	double Vector3::Length() const {
		return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	double Vector3::LengthSquared() const {
		return this->x * this->x + this->y * this->y + this->z * this->z;
	}

	void Vector3::Normalize() {
		double length = this->Length();
		this->x /= length;
		this->y /= length;
		this->z /= length;
	}

	Vector3 Vector3::Normalized() const {
		double length = this->Length();
		return Vector3(this->x / length, this->y / length, this->z / length);
	}
}