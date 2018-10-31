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
class EditorInternal : public Mouse
{
	Q_OBJECT
public:
	explicit EditorInternal(QQuickItem * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // icL_editor_Advanced
