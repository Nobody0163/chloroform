#pragma once

namespace Chloroform::Core {
	template <typename TV, typename TE>
	class Result {
	public:
		union {
			TV value;
			TE error;
		};
		bool isOk;
		
		Result(const TV &v) : value(v), isOk(true) {}
		Result(TV &&v) : value(std::move(v)), isOk(true) {}

		Result(const TE &e) : error(e), isOk(false) {}
		Result(TE &&e) : error(std::move(e)), isOk(false) {}

		~Result() {
			if (isOk) {
				value.~TV();
			} else {
				error.~TE();
			}
		}
	};
}