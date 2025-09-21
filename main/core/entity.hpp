#pragma once

#include <vector>

#include "component.hpp"
#include "event.hpp"
#include "nlohmann/json.hpp"

namespace Chloroform::Core {
	class Entity {
	public:
		std::string name;
		Entity* parent;
		std::vector<Entity*> children;
		std::vector<Component*> components;

		Entity(std::string name = "",std::vector<Entity*> children = {}, std::vector<Component*> components = {});

		virtual ~Entity() = default;

		void AddChild(Entity* child);
		void SetParent(Entity* parent);
		void Ready();
		void Update();
		void FixedUpdate();
		void HandleEvent(Event& event);
		virtual nlohmann::json Serialize() const;
	};
}