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
};

}  // namespace icL::editor

#endif  // icL_editor_Bracket
