#include "entity.hpp"

#include <algorithm>

namespace Chloroform::Core {
	Entity::Entity(std::string name, std::vector<Entity*> children, std::vector<Component*> components) : name(name), parent(nullptr), children(children), components(components) {
		for (Entity* child : this->children) {
			child->SetParent(this);
		}
	}

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
		for (Entity* child : this->children) {
			child->Ready();
		}
	}

	void Entity::Update() {
		for (Component* component : this->components) {
			component->Update();
		}
		for (Entity* child : this->children) {
			child->Update();
		}
	}

	void Entity::FixedUpdate() {
		for (Component* component : this->components) {
			component->FixedUpdate();
		}
		for (Entity* child : this->children) {
			child->FixedUpdate();
		}
	}

	void Entity::HandleEvent(Event& event) {
		for (Component* component : this->components) {
			component->HandleEvent(event);
		}
		for (Entity* child : this->children) {
			child->HandleEvent(event);
		}
	}

	nlohmann::json Entity::Serialize() const {
		nlohmann::json j;
		j["name"] = this->name;
		j["components"] = nlohmann::json::array();
		for (const Component* component : this->components) {
			j["components"].push_back(component->Serialize());
		}
		j["children"] = nlohmann::json::array();
		for (const Entity* child : this->children) {
			j["children"].push_back(child->Serialize());
		}
		return j;
	}
}