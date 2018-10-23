#include "word.h"

namespace icL::editor {

Word::Word(Line * parent)
	: Fragment(parent) {}

ProcessedGlyphs Word::processGlyphs(const QString & text) {
	ProcessedGlyphs pg;
	int             i = 0;

	while (i < text.length() &&
		   (text[i].isLetter() || text[i].isDigit() || text[i] == '-')) {
		pg.toInsertHere.append(text[i]);
		i++;
	}

	if (i != text.length()) {
		pg.onNextLine     = text[i] == '\n';
		pg.toInsertInNext = text.mid(i);
	}

	return pg;
}

Fragment * Word::insertInSpaces(int pos, const QString & text) {
	m_spaces -= pos;

	return m_prev->insert(
	  m_prev->length(), QString(m_spaces - pos, ' ') + text);
}

}  // namespace icL::editor
