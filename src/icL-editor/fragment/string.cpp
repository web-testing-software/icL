#include "string.h"

#include "../private/cursor.h"
#include "../self/editorinternal.h"

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
  Cursor * begin, Cursor * end, int pos, const QString & text) {
	int spaces = countSpacesAtBegin(text);

	if (spaces == text.length()) {
		m_spaces += spaces;

		end->setPosition(pos + spaces);
		end->setFragment(this);
		return this;
	}

	ensurePrev();
	begin->setFragment(m_prev);
	begin->setPosition(m_prev->length());

	m_spaces -= pos;
	return m_prev->insert(
	  begin, end, m_prev->length(), QString(pos, ' ') + text);
}

Fragment * String::insertAfterSpaces(
  Cursor * begin, Cursor * end, const QString & text) {

	ensurePrev();
	begin->setFragment(m_prev);
	begin->setPosition(m_prev->length());

	auto * ret = m_prev->insert(
	  begin, end, m_prev->length(), QString(m_spaces, ' ') + text);

	m_spaces = 0;
	end->setPosition(0);
	return ret;
}

Fragment * String::insertAfterGlyphs(
  Cursor * begin, Cursor * end, const QString & text) {
	if (m_glyphs == 0) {
		auto pg     = processGlyphs(text);
		int  spaces = countSpacesAtBegin(pg.toInsertHere);

		content  = pg.toInsertHere.mid(spaces);
		m_glyphs = content.length();
		m_spaces = spaces;

		if (!pg.toInsertInNext.isEmpty()) {
			return makeNewFragment(
			  begin, end, pg.toInsertInNext, pg.onNextLine);
		}

		end->setPosition(m_spaces + m_glyphs);
		end->setFragment(this);
		return this;
	}

	return makeNewFragment(begin, end, text, false);
}

Fragment * String::dropHead(Cursor * cursor, int p1, int p2) {

	content.remove(0, p2 - m_spaces);
	m_glyphs = content.length();

	if (p1 < m_spaces) {
		m_spaces = p1;
	}

	cursor->setPosition(p1);
	cursor->setFragment(this);

	return this;
}

}  // namespace icL::editor
