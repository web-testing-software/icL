#include "cursor.h"

#include "../fragment/fragment.h"
#include "../self/advanced.h"
#include "line.h"

#include <algorithm>

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

int Cursor::getPosInLine() {
	int    pos = 0;
	auto * it  = m_fragment->line()->first();

	while (it != nullptr && it != m_fragment) {
		pos += it->length();
		it = it->next();
	}

	pos += m_position;

	return pos;
}

int Cursor::getPosInFile() {
	//	m_fragment->line()->
	// TODO: Write it later
}

bool Cursor::stepForward(int number, Cursor * block) {
	if (m_position + number <= m_fragment->length()) {
		bool realtivePos = m_position >= block->m_position;

		m_position += number;

		if (
		  m_fragment == block->m_fragment &&
		  (m_position >= block->m_position) != realtivePos) {
			m_position = block->m_position;
		}
	}
	else {
		auto * nextFrag    = m_fragment->nextFragment();
		auto * oldFrag     = m_fragment;
		int    oldPosition = m_position;

		if (nextFrag == nullptr) {
			m_position = m_fragment->length();
			return false;
		}

		m_position = 0;
		m_fragment = nextFrag;

		stepForward(number - (oldFrag->length() - oldPosition), block);
	}

	return true;
}

bool Cursor::stepBack(int number, Cursor * block) {
	if (m_position > number) {
		bool realtivePos = m_position <= block->m_position;

		m_position -= number;

		if (
		  m_fragment == block->m_fragment &&
		  (m_position <= block->m_position) != realtivePos) {
			m_position = block->m_position;
		}
	}
	else {
		auto * prevFrag    = m_fragment->prevFragment();
		int    oldPosition = m_position;

		if (prevFrag == nullptr) {
			m_position = 0;
			return false;
		}

		m_position = prevFrag->length();
		m_fragment = prevFrag;

		stepBack(number - oldPosition, block);
	}

	return true;
}

bool Cursor::stepWordForward(Cursor * block) {
	if (m_position == m_fragment->length()) {
		auto * nextFrag = m_fragment->nextFragment();

		if (nextFrag == nullptr) {
			return false;
		}

		m_fragment = nextFrag;
		m_position = 0;
		return stepWordForward(block);
	}

	const QString & text = m_fragment->displayText();

	int i = std::min(
	  m_position - m_fragment->spaces() + 2,
	  static_cast<int>(m_fragment->length()));

	while (i < text.length()) {
		if (
		  (text[i - 1].isLetterOrNumber() && !text[i].isLetterOrNumber()) ||
		  (text[i - 1].isLower() && text[i].isUpper())) {
			break;
		}
	}

	m_position = i + m_fragment->spaces();
	return true;
}

bool Cursor::stepWordBack(Cursor * block) {
	if (m_position <= m_fragment->spaces()) {
		auto * prevFrag = m_fragment->prevFragment();

		if (prevFrag == nullptr) {
			return false;
		}

		m_fragment = prevFrag;
		m_position = prevFrag->length();
		return stepWordBack(block);
	}

	const QString & text = m_fragment->displayText();

	int i = std::max(m_position - m_fragment->spaces() - 2, 0);

	while (i > 0) {
		if (
		  (!text[i].isLetterOrNumber() && text[i + 1].isLetterOrNumber()) ||
		  (text[i].isLower() && text[i + 1].isUpper())) {
			break;
		}
	}

	m_position = i + m_fragment->spaces();
	return true;
}

void Cursor::syncWith(Cursor * cursor) {
	m_position = cursor->m_position;
	m_fragment = cursor->m_fragment;
}

Advanced * Cursor::getEditor() {
	return dynamic_cast<Advanced *>(m_fragment->line()->parent());
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
