#ifndef icL_editor_Mouse
#define icL_editor_Mouse

#include "keyboard.h"

namespace icL::editor {

/**
 * @brief The Mouse class releases the interaction beetwen mouse and editor
 */
class Mouse : public Keyboard
{
	Q_OBJECT
public:
	explicit Mouse(QQuickItem * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // icL_editor_Mouse
