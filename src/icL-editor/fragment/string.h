#ifndef icL_editor_String
#define icL_editor_String

#include "fragment.h"



namespace icL::editor {

/**
 * @brief The String class describes a fragment of text which contains a string
 */
class String : public Fragment
{
public:
    explicit String(Line * parent = nullptr);

    // Fragment interface
public:
    const look::TextCharFormat & format() override;

protected:
    ProcessedGlyphs processGlyphs(const QString & text) override;

    Fragment * insertInSpaces(
      Cursor * begin, Cursor * end, int pos, const QString & text) override;
    Fragment * insertAfterSpaces(
      Cursor * begin, Cursor * end, const QString & text) override;
    Fragment * insertAfterGlyphs(
      Cursor * begin, Cursor * end, const QString & text) override;
    Fragment * dropHead(Cursor * cursor, int p1, int p2) override;
    //	Fragment * dropTail(Cursor * cursor, int p1, int p2) override;

private:
    // padding
    long : 56;
};

}  // namespace icL::editor

#endif  // icL_editor_String
