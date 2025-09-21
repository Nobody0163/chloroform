#include "transform3d.hpp"

#include <stdexcept>

namespace Chloroform::Math {
	Transform3D::Transform3D(Vector3 offset, Vector3 basis_x, Vector3 basis_y, Vector3 basis_z) : offset(offset), basis_x(basis_x), basis_y(basis_y), basis_z(basis_z) {}

	Vector3 Transform3D::operator*(const Vector3& other) const {
		return Vector3(
			this->offset.x + this->basis_x.x * other.x + this->basis_y.x * other.y + this->basis_z.x * other.z,
			this->offset.y + this->basis_x.y * other.x + this->basis_y.y * other.y + this->basis_z.y * other.z,
			this->offset.z + this->basis_x.z * other.x + this->basis_y.z * other.y + this->basis_z.z * other.z
		);
	}

	Transform3D Transform3D::operator*(const Transform3D& other) const {
		Vector3 new_offset = (*this) * other.offset;

		Vector3 new_basis_x = Vector3(
			this->basis_x.x * other.basis_x.x + this->basis_y.x * other.basis_x.y + this->basis_z.x * other.basis_x.z,
			this->basis_x.y * other.basis_x.x + this->basis_y.y * other.basis_x.y + this->basis_z.y * other.basis_x.z,
			this->basis_x.z * other.basis_x.x + this->basis_y.z * other.basis_x.y + this->basis_z.z * other.basis_x.z
		);

		Vector3 new_basis_y = Vector3(
			this->basis_x.x * other.basis_y.x + this->basis_y.x * other.basis_y.y + this->basis_z.x * other.basis_y.z,
			this->basis_x.y * other.basis_y.x + this->basis_y.y * other.basis_y.y + this->basis_z.y * other.basis_y.z,
			this->basis_x.z * other.basis_y.x + this->basis_y.z * other.basis_y.y + this->basis_z.z * other.basis_y.z
		);

		Vector3 new_basis_z = Vector3(
			this->basis_x.x * other.basis_z.x + this->basis_y.x * other.basis_z.y + this->basis_z.x * other.basis_z.z,
			this->basis_x.y * other.basis_z.x + this->basis_y.y * other.basis_z.y + this->basis_z.y * other.basis_z.z,
			this->basis_x.z * other.basis_z.x + this->basis_y.z * other.basis_z.y + this->basis_z.z * other.basis_z.z
		);

		return Transform3D(new_offset, new_basis_x, new_basis_y, new_basis_z);
	}

	Transform3D& Transform3D::operator*=(const Transform3D& other) {
		*this = (*this) * other;
		return *this;
	}

	nlohmann::json Transform3D::Serialize() const {
		nlohmann::json j;
		j["offset"] = { this->offset.x, this->offset.y, this->offset.z };
		j["basis_x"] = { this->basis_x.x, this->basis_x.y, this->basis_x.z };
		j["basis_y"] = { this->basis_y.x, this->basis_y.y, this->basis_y.z };
		j["basis_z"] = { this->basis_z.x, this->basis_z.y, this->basis_z.z };
		return j;
	}

	Transform3D Transform3D::Deserialize(const nlohmann::json& j) {
		return Transform3D(
			Vector3(j["offset"][0], j["offset"][1], j["offset"][2]),
			Vector3(j["basis_x"][0], j["basis_x"][1], j["basis_x"][2]),
			Vector3(j["basis_y"][0], j["basis_y"][1], j["basis_y"][2]),
			Vector3(j["basis_z"][0], j["basis_z"][1], j["basis_z"][2])
		);
	}
}