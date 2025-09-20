#include "entity2d.hpp"

namespace Chloroform::Core {
	Entity2D::Entity2D(std::vector<Entity*> children, std::vector<Component*> components, Math::Transform2D transform) : Entity(children, components), transform(transform) {}

	Math::Transform2D Entity2D::GetGlobalTransform() const {
		if (Entity2D* parent2d = dynamic_cast<Entity2D*>(this->parent)) {
			return parent2d->GetGlobalTransform() * this->transform;
		}

		return this->transform;
	}
}