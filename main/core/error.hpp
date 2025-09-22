#pragma once

namespace Chloroform::Core {
	enum class Error {
		UNKNOWN,
		WARN_UI_NO_CONTAINER_COMPONENT_HANDLED
	};

	extern const char* error_strings[];
}