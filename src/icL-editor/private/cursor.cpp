#include "cursor.h"

#include "../fragment/fragment.h"
#include "../self/editorinternal.h"
#include "line.h"

#include <algorithm>

namespace icL::editor {

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
	return m_fragment->line()->beginPos() + getPosInLine();
}

bool Cursor::stepForward(int number, Cursor * block) {
	if (number <= 0) {
		return true;
	}

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

		if (m_fragment->next() == nullptr) {
			number--;
		}

		m_position = 0;
		m_fragment = nextFrag;

		stepForward(number - (oldFrag->length() - oldPosition), block);
	}

	return true;
}

bool Cursor::stepBackward(int number, Cursor * block) {
	if (number <= 0) {
		return true;
	}

	if (m_position >= number) {
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

		if (m_fragment->prev() == nullptr) {
			number--;
		}

		m_position = prevFrag->length();
		m_fragment = prevFrag;

		stepBackward(number - oldPosition, block);
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

	if (m_position < m_fragment->spaces()) {
		m_position = m_fragment->spaces();
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
		i++;
	}

	bool realtivePos = m_position >= block->m_position;

	m_position =
	  i > text.length() ? m_fragment->length() : i + m_fragment->spaces();

	if (
	  m_fragment == block->m_fragment &&
	  (m_position >= block->m_position) != realtivePos) {
		m_position = block->m_position;
	}

	return true;
}

bool Cursor::stepWordBackward(Cursor * block) {
	if (m_position <= m_fragment->spaces() || m_fragment->glyphs() == 0) {
		auto * prevFrag = m_fragment->prevFragment();

		if (prevFrag == nullptr) {
			return false;
		}

		m_fragment = prevFrag;
		m_position = prevFrag->length();
		return stepWordBackward(block);
	}

	if (m_position < m_fragment->spaces()) {
		m_position = m_fragment->spaces();
	}

	const QString & text = m_fragment->displayText();

	int i = std::max(m_position - m_fragment->spaces() - 2, 0);

	while (i > 0) {
		if (
		  (!text[i].isLetterOrNumber() && text[i + 1].isLetterOrNumber()) ||
		  (text[i].isLower() && text[i + 1].isUpper())) {
			break;
		}
		i--;
	}

	bool realtivePos = m_position <= block->m_position;

	m_position = i > 0 ? i + m_fragment->spaces() : 0;

	if (
	  m_fragment == block->m_fragment &&
	  (m_position <= block->m_position) != realtivePos) {
		m_position = block->m_position;
	}

	return true;
}

bool Cursor::stepWordsForward(int words, Cursor * block) {
	int i = 0;

	while (i < words && stepWordForward(block))
		i++;

	return i == words;
}

bool Cursor::stepWordsBackward(int words, Cursor * block) {
	int i = 0;

	while (i < words && stepWordBackward(block))
		i++;

	return i == words;
}

void Cursor::moveToLine(Line * line) {
	m_fragment = line->first();
	matchPreffered();
}

bool Cursor::stepLinesUp(int lines, Cursor * block) {
	int i = 0;

	auto * itLine      = m_fragment->line();
	auto * blockLine   = block->fragment()->line();
	bool   relativePos = itLine->lineNumber() <= blockLine->lineNumber();

	while (i < lines && itLine->prev() != nullptr) {
		itLine = itLine->prev();
		i++;
	}

	if (itLine->lineNumber() <= blockLine->lineNumber() != relativePos) {
		this->syncWith(block);
	}
	else {
		moveToLine(itLine);
	}

	return i == lines;
}

bool Cursor::stepLinesDown(int lines, Cursor * block) {
	int i = 0;

	auto * itLine      = m_fragment->line();
	auto * blockLine   = block->fragment()->line();
	bool   relativePos = itLine->lineNumber() >= blockLine->lineNumber();

	while (i < lines && itLine->next() != nullptr) {
		itLine = itLine->next();
		i++;
	}

	if (itLine->lineNumber() >= blockLine->lineNumber() != relativePos) {
		this->syncWith(block);
	}
	else {
		moveToLine(itLine);
	}

	return i == lines;
}

void Cursor::syncWith(Cursor * cursor) {
	m_position  = cursor->m_position;
	m_fragment  = cursor->m_fragment;
	m_preffered = cursor->m_preffered;
}

void Cursor::updatePreffered(int delta) {
	if (delta == 0) {
		m_preffered = getPosInLine();
	}
	else {
		m_preffered += delta;
	}
}

void Cursor::matchPreffered() {
	auto * itFrag    = m_fragment->line()->first();
	int    posInLine = 0;

	if (m_preffered == 0) {
		setFragment(itFrag);
		setPosition(0);
		return;
	}

	while (itFrag->next() != nullptr && posInLine < m_preffered) {
		posInLine += itFrag->length();
		itFrag = itFrag->next();
	}

	if (posInLine < m_preffered) {
		setFragment(itFrag);
		if (m_preffered - posInLine < itFrag->length()) {
			setPosition(m_preffered - posInLine);
		}
		else {
			setPosition(itFrag->length());
		}
	}
	else {
		setFragment(itFrag->prev());
		setPosition(itFrag->prev()->length() - (posInLine - m_preffered));
	}
}

EditorInternal * Cursor::getEditor() {
	return dynamic_cast<EditorInternal *>(m_fragment->line()->parent());
}

void Cursor::backUp() {
	m_lineNumber = m_fragment->line()->lineNumber();
}

void Cursor::restore() {
	m_fragment = getEditor()->getLineByNumber(m_lineNumber)->first();
	matchPreffered();
}

bool Cursor::operator==(const Cursor & other) const {
	return m_fragment == other.m_fragment && m_position == other.m_position;
}

bool Cursor::operator!=(const Cursor & other) const {
	return m_fragment != other.m_fragment || m_position != other.m_position;
}

void Cursor::setFragment(Fragment * fragment) {
	if (m_fragment == fragment)
		return;

	m_fragment = fragment;
}

void Cursor::setPosition(int8_t position) {
	if (m_position == position)
		return;

	m_position = position;
}

void Cursor::setPreffered(uint8_t preffered) {
	if (m_preffered == preffered)
		return;

	m_preffered = preffered;
}

void Cursor::setLineNumber(int16_t lineNumber) {
	if (m_lineNumber == lineNumber)
		return;

	m_lineNumber = lineNumber;
}

}  // namespace icL::editor
