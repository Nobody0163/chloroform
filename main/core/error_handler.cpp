#include "error_handler.hpp"

namespace Chloroform::Core {
	ErrorHandler::ErrorHandler(std::vector<void(*)(Error, std::string)> callbacks) : callbacks(callbacks) {}

	void ErrorHandler::ReportError(Error error, std::string message) {
		this->errors.push({error, message});
		for (void(*callback)(Error, std::string) : this->callbacks) {
			callback(error, message);
		}
	}
}