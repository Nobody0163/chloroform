#include "entity.hpp"

#include <bits/algorithmfwd.h>

namespace Chloroform::Core {
	Entity::Entity(std::vector<Entity*> children, std::vector<Component*> components) : parent(nullptr), children(children), components(components) {}

	void Entity::AddChild(Entity* child) {
		if (child->parent != nullptr) {
			child->parent->children.erase(std::remove(child->parent->children.begin(), child->parent->children.end(), child), child->parent->children.end());
		}
		child->parent = this;
		this->children.push_back(child);
	}

	void Entity::SetParent(Entity* parent) {
		if (this->parent != nullptr) {
			this->parent->children.erase(std::remove(this->parent->children.begin(), this->parent->children.end(), this), this->parent->children.end());
		}
		this->parent = parent;
		parent->children.push_back(this);
	}

	void Entity::Ready() {
		for (Component* component : this->components) {
			component->Ready(this);
		}
		for (Entity* child : children) {
			child->Ready();
		}
	}

	void Entity::Update() {
		for (Component* component : components) {
			component->Update();
		}
		for (Entity* child : children) {
			child->Update();
		}
	}

	void Entity::FixedUpdate() {
		for (Component* component : components) {
			component->FixedUpdate();
		}
		for (Entity* child : children) {
			child->FixedUpdate();
		}
	}

	void Entity::HandleEvent(Event& event) {
		for (Component* component : components) {
			component->HandleEvent(event);
		}
		for (Entity* child : children) {
			child->HandleEvent(event);
		}
	}
}