#pragma once

#include <string>
#include <vector>
#include <queue>

#include "error.hpp"

namespace Chloroform::Core {
	class ErrorHandler {
	public:
		std::queue<std::pair<Error, std::string>> errors;
		std::vector<void(*)(Error, std::string)> callbacks;

		ErrorHandler(std::vector<void(*)(Error, std::string)> callbacks = {});

		void ReportError(Error error, std::string message);
	};
}