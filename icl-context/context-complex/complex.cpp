#include "complex.h"

namespace icL::context::complex {

Complex::Complex(memory::InterLevel * il)
	: Context(il) {}

bool Complex::isComplex() const {
	return true;
}

}  // namespace icL::context::complex
