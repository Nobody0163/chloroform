#pragma once

#include "error_handler.hpp"

namespace Chloroform::Core {
	class Engine {
	public:
		ErrorHandler error_handler;

		static Engine& Instance();
	private:
		Engine() = default;
	};
}