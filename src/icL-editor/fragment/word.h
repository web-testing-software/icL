#ifndef icL_editor_Word
#define icL_editor_Word

#include "fragment.h"

namespace icL::editor {

class Word : public Fragment
{
	Q_OBJECT
public:
	explicit Word(Line * parent = nullptr);

signals:

public slots:

	// Fragment interface
protected:
	ProcessedGlyphs processGlyphs(const QString & text) override;
	Fragment *      insertInSpaces(int pos, const QString & text) override;
};

}  // namespace icL::editor

#endif  // icL_editor_Word
