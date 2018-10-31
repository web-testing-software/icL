#ifndef icL_editor_Bracket
#define icL_editor_Bracket

#include "fragment.h"



namespace icL::editor {

/**
 * @brief The Bracket class describes a bracket in text editor
 */
class Bracket : public Fragment
{
public:
	explicit Bracket(Line * parent = nullptr);

	// Fragment interface
public:
	bool isBracket() override;
	bool isOpenBracket() override;

protected:
	Fragment * insertInSpaces(
	  Cursor * begin, Cursor * end, int pos, const QString & text) override;
	Fragment * insertAfterSpaces(
	  Cursor * begin, Cursor * end, const QString & text) override;
	Fragment * insertInGlyphs(
	  Cursor * begin, Cursor * end, int pos, const QString & text) override;
	Fragment * insertAfterGlyphs(
	  Cursor * begin, Cursor * end, const QString & text) override;
	Fragment * dropHead(Cursor * cursor, int p1, int p2) override;
	Fragment * dropContent(Cursor * cursor, int p1, int p2) override;
	Fragment * dropTail(Cursor * cursor, int p1, int p2) override;
};

}  // namespace icL::editor

#endif  // icL_editor_Bracket
