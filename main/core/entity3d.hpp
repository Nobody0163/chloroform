#pragma once

#include "entity.hpp"
#include "math/transform3d.hpp"

namespace Chloroform::Core {
	class Entity3D : public Entity {
	public:
		Math::Transform3D transform;

		Entity3D(std::vector<Entity*> children = {}, std::vector<Component*> components = {}, Math::Transform3D transform = Math::Transform3D());

		Math::Transform3D GetGlobalTransform() const;
	};
}