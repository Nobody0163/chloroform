#pragma once

#include <limits>

namespace Chloroform::Math {
	bool is_equal_approx(double a, double b, double epsilon = std::numeric_limits<double>::epsilon());
}