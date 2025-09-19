#pragma once

#include "event.hpp"

namespace Chloroform::Core {
	class Entity;

	class Component {
	public:
		virtual ~Component() = default;

		virtual void Ready(Entity* entity) = 0;
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void HandleEvent(Event& event) = 0;
	};
}