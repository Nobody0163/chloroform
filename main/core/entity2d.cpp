#include "entity2d.hpp"

namespace Chloroform::Core {
	Entity2D::Entity2D(std::string name, std::vector<Entity*> children, std::vector<Component*> components, Math::Transform2D transform) : Entity(name, children, components), transform(transform) {}

	Math::Transform2D Entity2D::GetGlobalTransform() const {
		if (Entity2D* parent2d = dynamic_cast<Entity2D*>(this->parent)) {
			return parent2d->GetGlobalTransform() * this->transform;
		}

		return this->transform;
	}

	nlohmann::json Entity2D::Serialize() const {
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
		j["transform"] = this->transform.Serialize();
		return j;
	}
}