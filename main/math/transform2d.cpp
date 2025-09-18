#include "transform2d.hpp"

namespace Chloroform::Math {
	Transform2D::Transform2D(Vector2 offset, Vector2 basis_x, Vector2 basis_y) : offset(offset), basis_x(basis_x), basis_y(basis_y) {}

	Vector2 Transform2D::operator*(const Vector2& other) const {
		return Vector2(
			this->basis_x.x * other.x + this->basis_y.x * other.y + this->offset.x,
			this->basis_x.y * other.x + this->basis_y.y * other.y + this->offset.y
		);
	}

	Transform2D Transform2D::operator*(const Transform2D& other) const {
		Vector2 new_offset = *this * other.offset;

		Vector2 new_basis_x = Vector2(
			this->basis_x.x * other.basis_x.x + this->basis_y.x * other.basis_x.y,
			this->basis_x.y * other.basis_x.x + this->basis_y.y * other.basis_x.y
		);

		Vector2 new_basis_y = Vector2(
			this->basis_x.x * other.basis_y.x + this->basis_y.x * other.basis_y.y,
			this->basis_x.y * other.basis_y.x + this->basis_y.y * other.basis_y.y
		);

		return Transform2D(new_offset, new_basis_x, new_basis_y);
	}

	Transform2D& Transform2D::operator*=(const Transform2D& other) {
		*this = *this * other;
		return *this;
	}
}