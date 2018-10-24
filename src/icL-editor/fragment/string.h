#ifndef icL_editor_String
#define icL_editor_String

#include "fragment.h"

namespace icL::editor {

class String : public Fragment
{
	Q_OBJECT
public:
	explicit String(Line * parent = nullptr);

signals:

public slots:

	// Fragment interface
public:
	const look::TextCharFormat & format() override;

protected:
	ProcessedGlyphs processGlyphs(const QString & text) override;

	Fragment * insertInSpaces(int pos, const QString & text) override;
	Fragment * insertAfterSpaces(const QString & text) override;
	Fragment * insertAfterGlyphs(const QString & text) override;
	Fragment * dropHead(int p1, int p2) override;
	Fragment * dropTail(int p1, int p2) override;
};

}  // namespace icL::editor

#endif  // icL_editor_String
