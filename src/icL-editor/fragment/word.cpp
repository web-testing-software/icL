#include "word.h"

#include "../private/cursor.h"

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

Fragment * Word::insertInSpaces(
  Cursor * begin, Cursor * end, int pos, const QString & text) {

    int spaces = countSpacesAtBegin(text);

    if (spaces == text.length()) {
        m_spaces += spaces;

        begin->setPosition(pos + spaces);
        begin->setFragment(this);
        return this;
    }

    ensurePrev();
    begin->setFragment(m_prev);
    begin->setPosition(m_prev->length());

    m_spaces -= pos;
    return m_prev->insert(
      begin, end, m_prev->length(), QString(m_spaces - pos, ' ') + text);
}

}  // namespace icL::editor
