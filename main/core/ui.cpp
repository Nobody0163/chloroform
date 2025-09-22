#include "ui.hpp"

#include "engine.hpp"

namespace Chloroform::Core {
	UIElement::UIElement(std::string name, std::vector<Entity*> children, std::vector<Component*> components, Math::Vector2 top_left_anchor, Math::Vector2 bottom_right_anchor, Math::Vector2 top_left_offset, Math::Vector2 bottom_right_offset, bool active) : Entity(name, children, components), top_left_anchor(top_left_anchor), bottom_right_anchor(bottom_right_anchor), top_left_offset(top_left_offset), bottom_right_offset(bottom_right_offset), active(active) {}

	Math::Vector2 UIElement::GetPosition() {
		if (this->cached_position.has_value()) {
			return this->cached_position.value();
		}

		Math::Vector2 position;
		if (UIContainer* parentContainer = dynamic_cast<UIContainer*>(this->parent)) {
			position = parentContainer->GetChildPosition(this);
		} else if (UIElement* parentElement = dynamic_cast<UIElement*>(this->parent)) {
			position = parentElement->GetPosition() + this->top_left_offset + parentElement->GetSize() * this->top_left_anchor;
		} else {
			position = this->top_left_offset;
		}

		this->cached_position = position;
		return position;
	}

	Math::Vector2 UIElement::GetSize() {
		if (this->cached_size.has_value()) {
			return this->cached_size.value();
		}

		Math::Vector2 size;
		if (UIContainer* parentContainer = dynamic_cast<UIContainer*>(this->parent)) {
			size = parentContainer->GetChildSize(this);
		} else if (UIElement* parentElement = dynamic_cast<UIElement*>(this->parent)) {
			size = parentElement->GetSize() * (this->bottom_right_anchor - this->top_left_anchor) + this->bottom_right_offset - this->top_left_offset;
		} else {
			size = this->bottom_right_offset - this->top_left_offset;
		}

		this->cached_size = size;
		return size;
	}

	void UIElement::InvalidateCaches() {
		this->cached_position.reset();
		this->cached_size.reset();
		for (Entity* child : this->children) {
			if (UIElement* casted_child = dynamic_cast<UIElement*>(child)) {
				casted_child->InvalidateCaches();
			}
		}
	}

	Math::Vector2 UIContainer::GetChildPosition(const UIElement* child) const {
		for (Component* component : this->components) {
			if (UIContainerComponent* containerComponent = dynamic_cast<UIContainerComponent*>(component)) {
				if (std::optional<Math::Vector2> position = containerComponent->GetChildPosition(child)) {
					return position.value();
				}
			}
		}

		Engine::Instance().error_handler.ReportError(Error::WARN_UI_NO_CONTAINER_COMPONENT_HANDLED, "UIContainer \"" + this->name + "\" has no UIContainerComponent that handles child \"" + child->name + "\". Defaulting to zero position.");
		return Math::Vector2();
	}

	Math::Vector2 UIContainer::GetChildSize(const UIElement* child) const {
		for (Component* component : this->components) {
			if (UIContainerComponent* containerComponent = dynamic_cast<UIContainerComponent*>(component)) {
				if (std::optional<Math::Vector2> size = containerComponent->GetChildSize(child)) {
					return size.value();
				}
			}
		}

		Engine::Instance().error_handler.ReportError(Error::WARN_UI_NO_CONTAINER_COMPONENT_HANDLED, "UIContainer \"" + this->name + "\" has no UIContainerComponent that handles child \"" + child->name + "\". Defaulting to zero size.");
		return Math::Vector2();
	}

	nlohmann::json UIElement::Serialize() const {
		nlohmann::json j = Entity::Serialize();
		j["name"] = this->name;
		j["components"] = nlohmann::json::array();
		for (const Component* component : this->components) {
			j["components"].push_back(component->Serialize());
		}
		j["children"] = nlohmann::json::array();
		for (const Entity* child : this->children) {
			j["children"].push_back(child->Serialize());
		}
		j["top_left_anchor"] = { this->top_left_anchor.x, this->top_left_anchor.y };
		j["bottom_right_anchor"] = { this->bottom_right_anchor.x, this->bottom_right_anchor.y };
		j["top_left_offset"] = { this->top_left_offset.x, this->top_left_offset.y };
		j["bottom_right_offset"] = { this->bottom_right_offset.x, this->bottom_right_offset.y };
		j["active"] = this->active;
		return j;
	}
}