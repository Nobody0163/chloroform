#pragma once

#include <optional>

#include "entity.hpp"
#include "math/vector2.hpp"

namespace Chloroform::Core {
	class UIElement : public Entity {
	public:
		Math::Vector2 top_left_anchor;
		Math::Vector2 bottom_right_anchor;
		Math::Vector2 top_left_offset;
		Math::Vector2 bottom_right_offset;
		bool active;

		UIElement(std::string name = "", std::vector<Entity*> children = {}, std::vector<Component*> components = {}, Math::Vector2 top_left_anchor = Math::Vector2(), Math::Vector2 bottom_right_anchor = Math::Vector2(1, 1), Math::Vector2 top_left_offset = Math::Vector2(), Math::Vector2 bottom_right_offset = Math::Vector2(), bool active = true);
	
		Math::Vector2 GetPosition();
		Math::Vector2 GetSize();
		void InvalidateCaches();
		nlohmann::json Serialize() const;
	private:
		std::optional<Math::Vector2> cached_position;
		std::optional<Math::Vector2> cached_size;
	};

	class UIContainer : public UIElement {
	public:
		Math::Vector2 GetChildPosition(const UIElement* child) const;
		Math::Vector2 GetChildSize(const UIElement* child) const;
	};

	class UIContainerComponent : public Component {
	public:
		virtual std::optional<Math::Vector2> GetChildPosition(const UIElement* child) const = 0;
		virtual std::optional<Math::Vector2> GetChildSize(const UIElement* child) const = 0;
	};
}