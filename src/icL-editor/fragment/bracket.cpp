#include "bracket.h"

#include "../private/cursor.h"

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

Fragment * Bracket::insertAfterSpaces(
  Cursor * begin, Cursor * end, const QString & text) {
    int spaces = countSpacesAtBegin(text);

    if (spaces == text.length()) {
        m_spaces += spaces;

        end->setPosition(m_spaces);
        end->setFragment(this);
        return this;
    }

    ensurePrev();
    begin->setFragment(m_prev);
    begin->setPosition(m_prev->length());

    auto * ret = m_prev->insert(
      begin, end, m_prev->length(), QString(m_spaces, ' ') + text);

    m_spaces = 0;
    return ret;
}

Fragment * Bracket::insertInGlyphs(
  Cursor * /*begin*/, Cursor * /*end*/, int, const QString &) {
    // This function must be not called ever
    Q_ASSERT(false);
    return nullptr;
}

Fragment * Bracket::insertAfterGlyphs(
  Cursor * begin, Cursor * end, const QString & text) {
    if (m_glyphs == 0) {
        m_glyphs = 1;

        if (text.length() == 1) {
            content = text;
            return this;
        }

        content = text.left(1);
        return makeNewFragment(begin, end, text.mid(1), false);
    }

    return makeNewFragment(begin, end, text, false);
}

Fragment * Bracket::dropHead(Cursor *, int, int) {
    // This function must be not called ever
    Q_ASSERT(false);
    return nullptr;
}

Fragment * Bracket::dropContent(Cursor *, int, int) {
    // This function must be not called ever
    Q_ASSERT(false);
    return nullptr;
}

Fragment * Bracket::dropTail(Cursor *, int, int) {
    // This function must be not called ever
    Q_ASSERT(false);
    return nullptr;
}

}  // namespace icL::editor
