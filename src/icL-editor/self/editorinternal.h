#ifndef icL_editor_Internal
#define icL_editor_Internal

#include "mouse.h"



namespace icL::editor {

/**
 * @brief The Advanced class contains the advanced functional
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

#endif  // icL_editor_Internal
