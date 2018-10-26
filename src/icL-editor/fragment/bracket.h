#ifndef icL_editor_Bracket
#define icL_editor_Bracket

#include "fragment.h"

namespace icL::editor {

class Bracket : public Fragment
{
	Q_OBJECT
public:
	explicit Bracket(Line * parent = nullptr);

signals:

public slots:

	// Fragment interface
public:
	bool isBracket() override;
	bool isOpenBracket() override;

protected:
	Fragment * insertInSpaces(
	  Cursor * cursor, int pos, const QString & text) override;
	Fragment * insertAfterSpaces(
	  Cursor * cursor, const QString & text) override;
	Fragment * insertInGlyphs(
	  Cursor * cursor, int pos, const QString & text) override;
	Fragment * insertAfterGlyphs(
	  Cursor * cursor, const QString & text) override;
	Fragment * dropHead(Cursor * cursor, int p1, int p2) override;
	Fragment * dropContent(Cursor * cursor, int p1, int p2) override;
	Fragment * dropTail(Cursor * cursor, int p1, int p2) override;
};

}  // namespace icL::editor

#endif  // icL_editor_Bracket
