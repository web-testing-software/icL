#include "flayer.h"

namespace vm::inter {

Flayer::Flayer () {

}

Flayer::~Flayer () {

}

int Flayer::begin () const {
	return m_begin;
}

int Flayer::end () const {
	return m_end;
}

void Flayer::setBegin (int begin) {
	if (m_begin == begin) {
		return;
	}

	m_begin = begin;
	emit beginChanged (m_begin);
}

void Flayer::setEnd (int end) {
	if (m_end == end) {
		return;
	}

	m_end = end;
	emit endChanged (m_end);
}

} // namespace
