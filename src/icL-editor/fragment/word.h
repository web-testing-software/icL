#ifndef icL_editor_Word
#define icL_editor_Word

#include "fragment.h"

namespace icL::editor {

class Word : public Fragment
{
public:
	explicit Word(Line * parent = nullptr);

	// Fragment interface
protected:
	ProcessedGlyphs processGlyphs(const QString & text) override;
	Fragment *      insertInSpaces(
		   Cursor * begin, Cursor * end, int pos, const QString & text) override;
};

}  // namespace icL::editor

#endif  // icL_editor_Word
