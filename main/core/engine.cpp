#include "engine.hpp"

namespace Chloroform::Core {
	Engine& Engine::Instance() {
		static Engine instance;
		return instance;
	}
}