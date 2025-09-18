#pragma once

#include "vector2.hpp"

namespace Chloroform::Math {
	class Transform2D {
	public:
		Vector2 offset;
		Vector2 basis_x;
		Vector2 basis_y;

		Transform2D(Vector2 offset = Vector2(0, 0), Vector2 basis_x = Vector2(1, 0), Vector2 basis_y = Vector2(0, 1));

		Vector2 operator*(const Vector2& other) const;
		Transform2D operator*(const Transform2D& other) const;
		Transform2D& operator*=(const Transform2D& other);
	};
}