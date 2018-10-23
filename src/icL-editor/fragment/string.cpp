#include "string.h"

namespace icL::editor {

String::String(Line * parent)
	: Fragment(parent) {}

ProcessedGlyphs String::processGlyphs(const QString & text) {
	ProcessedGlyphs pg;
	int             i = 0;

	while (i < text.length()) {
		QChar ch = text[i];

		if (ch == '\n') {
			pg.toInsertHere.append("\\n");
		}
		else if (ch == '\t') {
			pg.toInsertHere.append("\\t");
		}
		else if (ch == '"') {
			pg.toInsertHere.append("\\\"");
		}
		else {
			pg.toInsertHere.append(ch);
		}

		i++;
	}

	if (i != text.length()) {
		pg.onNextLine     = true;
		pg.toInsertInNext = text.mid(i);
	}

	return pg;
}

Fragment * String::insertInSpaces(int pos, const QString & text) {
	m_spaces -= pos;

	return m_prev->insert(m_prev->length(), QString(pos, ' ') + text);
}

Fragment * String::insertAfterSpaces(const QString & text) {
	auto * ret =
	  m_prev->insert(m_prev->length(), QString(m_spaces, ' ') + text);

	m_spaces = 0;
	return ret;
}

Fragment * String::insertAfterGlyphs(const QString & text) {
	return makeNewFragment(text, false);
}

Fragment * String::dropHead(int p1, int p2) {
	QString text = content.mid(p2 - m_spaces);

	if (m_next != nullptr) {
		m_next->setPrev(m_prev);
	}

	if (m_prev != nullptr) {
		m_prev->setNext(m_next);
	}

	auto * ret = m_prev->insert(m_prev->length(), QString(p1, ' ') + text);

	delete this;
	return ret;
}

Fragment * String::dropTail(int p1, int p2) {
	auto *  it   = m_next;
	QString text;

	while (it != nullptr) {
		text += QString(it->spaces(), ' ') + it->displayText();

		auto * nextIt = it->next();
		delete it;
		it = nextIt;
	}

	m_next = nullptr;
	replace(p1, p2, text);

	return this;
}

}  // namespace icL::editor
