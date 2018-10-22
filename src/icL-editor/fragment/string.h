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
};

}  // namespace icL::editor

#endif  // icL_editor_String
