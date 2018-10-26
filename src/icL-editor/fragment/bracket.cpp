#include "bracket.h"

namespace icL::editor {

Bracket::Bracket(Line * parent)
    : Fragment(parent) {}

bool Bracket::isBracket() {
	return true;
}

bool Bracket::isOpenBracket() {
	return content == QStringLiteral("{") || content == QStringLiteral("[") ||
	       content == QStringLiteral("(");
}

Fragment * Bracket::insertInSpaces(
  Cursor * cursor, int pos, const QString & text) {
	m_spaces -= pos;

	return m_prev->insert(cursor, m_prev->length(), QString(pos, ' ') + text);
}

Fragment * Bracket::insertAfterSpaces(Cursor * cursor, const QString & text) {
	auto * ret =
	  m_prev->insert(cursor, m_prev->length(), QString(m_spaces, ' ') + text);

	m_spaces = 0;
	return ret;
}

Fragment * Bracket::insertInGlyphs(Cursor * cursor, int, const QString &) {
	// This function must be not called ever
	Q_ASSERT(false);
}

Fragment * Bracket::insertAfterGlyphs(Cursor * cursor, const QString & text) {
	if (m_glyphs == 0) {
		m_glyphs = 1;

		if (text.length() == 1) {
			content = text;
			return this;
		}

		content = text.left(1);
		return makeNewFragment(cursor, text.mid(1), false);
	}

	return makeNewFragment(cursor, text, false);
}

Fragment * Bracket::dropHead(Cursor * cursor, int, int) {
	// This function must be not called ever
	Q_ASSERT(false);
}

Fragment * Bracket::dropContent(Cursor * cursor, int, int) {
	// This function must be not called ever
	Q_ASSERT(false);
}

Fragment * Bracket::dropTail(Cursor * cursor, int, int) {
	// This function must be not called ever
	Q_ASSERT(false);
}

}  // namespace icL::editor
