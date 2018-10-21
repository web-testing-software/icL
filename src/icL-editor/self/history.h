#ifndef icL_editor_History
#define icL_editor_History

#include "drawing.h"


namespace icL::editor {

/**
 * @brief The History class contains the history of document
 */
class History : public Drawing
{
	Q_OBJECT

public:
	explicit History(QQuickItem * parent = nullptr);
};

}  // namespace icL::editor

#endif  // icL_editor_History
