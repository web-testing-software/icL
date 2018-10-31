#ifndef icL_editor_OpacityMask
#define EDITOROPACITYMASK_H

#include <QQuickPaintedItem>



namespace icL::editor {

class EditorInternal;

/**
 * @brief The OpacityMask class draws a mask for blurred background
 */
class OpacityMask : public QQuickPaintedItem
{
	Q_OBJECT

public:
	explicit OpacityMask(QQuickItem * parent = nullptr);

	// QQuickPaintedItem interface
public:
	void paint(QPainter * painter) override;

signals:

public slots:
	/**
	 * @brief setEditor sets the editor pointer
	 * @param editor will be used to extract drawing data
	 */
	void setEditor(EditorInternal * editor);

private:
	/// @brief is the pointer to text editor
	EditorInternal * m_editor;
};

}  // namespace icL::editor

#endif  // icL_editor_OpacityMask
