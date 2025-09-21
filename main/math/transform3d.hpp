#pragma once

#include "vector3.hpp"
#include "nlohmann/json.hpp"

namespace Chloroform::Math {
	class Transform3D {
	public:
		Vector3 offset;
		Vector3 basis_x;
		Vector3 basis_y;
		Vector3 basis_z;

		Transform3D(Vector3 offset = Vector3(0, 0, 0), Vector3 basis_x = Vector3(1, 0, 0), Vector3 basis_y = Vector3(0, 1, 0), Vector3 basis_z = Vector3(0, 0, 1));

		Vector3 operator*(const Vector3& other) const;
		Transform3D operator*(const Transform3D& other) const;
		Transform3D& operator*=(const Transform3D& other);
		nlohmann::json Serialize() const;
		static Transform3D Deserialize(const nlohmann::json& j);
	};
}