#ifndef icL_editor_Advanced
#define icL_editor_Advanced

#include "mouse.h"

namespace icL::editor {

/**
 * @brief The Advanced class contians the advanced functional
 *
 * This class contains the functional which cannot be attached to any of parent
 * classes
 */
class Advanced : public Mouse
{
	Q_OBJECT
public:
	explicit Advanced(QQuickItem * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // icL_editor_Advanced
