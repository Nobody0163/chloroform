#include "functions.hpp"

#include <cmath>

namespace Chloroform::Math {
	bool is_equal_approx(double a, double b, double epsilon) {
		return std::abs(a - b) <= epsilon;
	}
}