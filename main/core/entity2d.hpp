#pragma once

#include "entity.hpp"
#include "math/transform2d.hpp"

namespace Chloroform::Core {
	class Entity2D : public Entity {
	public:
		Math::Transform2D transform;

		Entity2D(std::string name = "", std::vector<Entity*> children = {}, std::vector<Component*> components = {}, Math::Transform2D transform = Math::Transform2D());

		Math::Transform2D GetGlobalTransform() const;
		nlohmann::json Serialize() const;
	};
}