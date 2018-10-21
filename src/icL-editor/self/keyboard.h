#ifndef icL_editor_Keyboard
#define icL_editor_Keyboard

#include "history.h"

namespace icL::editor {

/**
 * @brief The Keyboard class releases the interaction beetwen editor and
 * keyboard
 */
class Keyboard : public History
{
	Q_OBJECT
public:
	explicit Keyboard(QQuickItem * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // icL_editor_Keyboard
