#include "entity3d.hpp"

namespace Chloroform::Core {
	Entity3D::Entity3D(std::string name, std::vector<Entity*> children, std::vector<Component*> components, Math::Transform3D transform) : Entity(name, children, components), transform(transform) {}

	Math::Transform3D Entity3D::GetGlobalTransform() const {
		if (Entity3D* parent3d = dynamic_cast<Entity3D*>(this->parent)) {
			return parent3d->GetGlobalTransform() * this->transform;
		}

		return this->transform;
	}

	nlohmann::json Entity3D::Serialize() const {
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