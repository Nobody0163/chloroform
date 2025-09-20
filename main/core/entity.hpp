#pragma once

#include <vector>

#include "component.hpp"
#include "event.hpp"

namespace Chloroform::Core {
	class Entity {
	public:
		Entity* parent;
		std::vector<Entity*> children;
		std::vector<Component*> components;

		Entity(std::vector<Entity*> children = {}, std::vector<Component*> components = {});

		virtual ~Entity() = default;

		void AddChild(Entity* child);
		void SetParent(Entity* parent);
		void Ready();
		void Update();
		void FixedUpdate();
		void HandleEvent(Event& event);
	};
}