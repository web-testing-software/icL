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
};

}  // namespace icL::editor

#endif  // icL_editor_Word
