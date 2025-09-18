#include "vector2.hpp"

#include <cmath>

namespace Chloroform::Math {
	Vector2::Vector2(double x, double y) : x(x), y(y) {}

	Vector2 Vector2::operator+(const Vector2& other) const {
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 Vector2::operator-(const Vector2& other) const {
		return Vector2(this->x - other.x, this->y - other.y);
	}

	Vector2 Vector2::operator*(double other) const {
		return Vector2(this->x * other, this->y * other);
	}

	Vector2 Vector2::operator*(const Vector2& other) const {
		return Vector2(this->x * other.x, this->y * other.y);
	}

	Vector2 Vector2::operator/(double other) const {
		return Vector2(this->x / other, this->y / other);
	}

	Vector2 Vector2::operator/(const Vector2& other) const {
		return Vector2(this->x / other.x, this->y / other.y);
	}

	bool Vector2::operator==(const Vector2& other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool Vector2::operator!=(const Vector2& other) const {
		return !(*this == other);
	}

	Vector2& Vector2::operator+=(const Vector2& other) {
		*this = *this + other;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& other) {
		*this = *this - other;
		return *this;
	}

	Vector2& Vector2::operator*=(double other) {
		*this = *this * other;
		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& other) {
		*this = *this * other;
		return *this;
	}

	Vector2& Vector2::operator/=(double other) {
		*this = *this / other;
		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& other) {
		*this = *this / other;
		return *this;
	}

	double Vector2::Dot(const Vector2& other) const {
		return this->x * other.x + this->y * other.y;
	}

	double Vector2::Length() const {
		return std::sqrt(this->x * this->x + this->y * this->y);
	}

	double Vector2::LengthSquared() const {
		return this->x * this->x + this->y * this->y;
	}

	void Vector2::Normalize() {
		double length = this->Length();
		this->x /= length;
		this->y /= length;
	}

	Vector2 Vector2::Normalized() const {
		double length = this->Length();
		if (length == 0) return *this;
		return Vector2(this->x / length, this->y / length);
	}

	void Vector2::Rotate(double angle) {
		double cosAngle = std::cos(angle);
		double sinAngle = std::sin(angle);
		this->x = this->x * cosAngle - this->y * sinAngle;
		this->y = this->x * sinAngle + this->y * cosAngle;
	}

	Vector2 Vector2::Rotated(double angle) const {
		double cosAngle = std::cos(angle);
		double sinAngle = std::sin(angle);
		return Vector2(this->x * cosAngle - this->y * sinAngle, this->x * sinAngle + this->y * cosAngle);
	}
}