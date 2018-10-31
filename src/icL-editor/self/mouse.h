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

private:
	/**
	 * @brief moveUp move first visible line up by n lines
	 * @param by is the number of lines
	 */
	void moveUp(int by);

	/**
	 * @brief moveDown move first visible down by n lines
	 * @param by is the number of lines
	 */
	void moveDown(int by);
};

}  // namespace icL::editor

#endif  // icL_editor_Mouse
