#include "complex.h"

namespace old::context::complex {

Complex::Complex(memory::InterLevel * il)
    : Context(il) {}

bool Complex::isComplex() const {
	return true;
}

}  // namespace old::context::complex
