#include "cursor.h"

namespace icL::editor {

Cursor::Cursor(QObject * parent)
	: QObject(parent) {}

Fragment * Cursor::fragment() const {
	return m_fragment;
}

int8_t Cursor::position() const {
	return m_position;
}

uint8_t Cursor::preffered() const {
	return m_preffered;
}

void Cursor::setFragment(Fragment * fragment) {
	if (m_fragment == fragment)
		return;

	m_fragment = fragment;
	emit fragmentChanged(m_fragment);
}

void Cursor::setPosition(int8_t position) {
	if (m_position == position)
		return;

	m_position = position;
	emit positionChanged(m_position);
}

void Cursor::setPreffered(uint8_t preffered) {
	if (m_preffered == preffered)
		return;

	m_preffered = preffered;
	emit prefferedChanged(m_preffered);
}

}  // namespace icL::editor
