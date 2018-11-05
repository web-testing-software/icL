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

	// QQuickItem interface
protected:
	void wheelEvent(QWheelEvent * event) override;
	void mousePressEvent(QMouseEvent * event) override;
	void mouseMoveEvent(QMouseEvent * event) override;
	void mouseReleaseEvent(QMouseEvent * event) override;
	void hoverMoveEvent(QHoverEvent * event) override;

private:
	/**
	 * @brief getLineCh gets the line and character number for mouse position
	 * @param event is the event to extract mouse position
	 * @return the line number and character number
	 */
	std::pair<Line *, int> getLineCh(QMouseEvent * event);
};

}  // namespace icL::editor

#endif  // icL_editor_Mouse
