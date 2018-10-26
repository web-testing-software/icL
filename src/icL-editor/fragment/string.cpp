#include "string.h"

#include "../private/cursor.h"
#include "../self/advanced.h"

#include <icL-look/export/chars.h>

namespace icL::editor {

String::String(Line * parent)
    : Fragment(parent) {}

const look::TextCharFormat & String::format() {
	return getEditor()->chars()->string;
}

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
		else if (ch == '\\') {
			if (content.isEmpty()) {
				pg.toInsertHere.append('\\');
			}
			else {
				pg.toInsertHere.append("\\\\");
			}
		}
		else if (ch == '"') {
			if (content.isEmpty()) {
				pg.toInsertHere.append("\"");

				if (pg.toInsertHere.length() > 1) {
					i++;
					break;
				}
			}
			else {
				pg.toInsertHere.append("\\\"");
			}
		}
		else {
			pg.toInsertHere.append(ch);
		}

		i++;
	}

	if (i != text.length()) {
		pg.onNextLine     = false;
		pg.toInsertInNext = text.mid(i);
	}

	return pg;
}

Fragment * String::insertInSpaces(
  Cursor * cursor, int pos, const QString & text) {
	int spaces = countSpacesAtBegin(text);

	if (spaces == text.length()) {
		m_spaces += spaces;

		cursor->setPosition(pos + spaces);
		cursor->setFragment(this);
		return this;
	}

	m_spaces -= pos;
	return m_prev->insert(cursor, m_prev->length(), QString(pos, ' ') + text);
}

Fragment * String::insertAfterSpaces(Cursor * cursor, const QString & text) {
	auto * ret =
	  m_prev->insert(cursor, m_prev->length(), QString(m_spaces, ' ') + text);

	m_spaces = 0;
	return ret;
}

Fragment * String::insertAfterGlyphs(Cursor * cursor, const QString & text) {
	if (m_glyphs == 0) {
		auto pg     = processGlyphs(text);
		int  spaces = countSpacesAtBegin(pg.toInsertHere);

		content  = pg.toInsertHere.mid(spaces);
		m_glyphs = content.length();
		m_spaces = spaces;

		if (!pg.toInsertInNext.isEmpty()) {
			return makeNewFragment(cursor, pg.toInsertInNext, pg.onNextLine);
		}

		cursor->setPosition(m_spaces + m_glyphs);
		cursor->setFragment(this);
		return this;
	}

	return makeNewFragment(cursor, text, false);
}

Fragment * String::dropHead(Cursor * cursor, int p1, int p2) {
	QString text = content.mid(p2 - m_spaces);

	if (m_next != nullptr) {
		m_next->setPrev(m_prev);
	}

	if (m_prev != nullptr) {
		m_prev->setNext(m_next);
	}

	auto * ret =
	  m_prev->insert(cursor, m_prev->length(), QString(p1, ' ') + text);

	delete this;
	return ret;
}

}  // namespace icL::editor
