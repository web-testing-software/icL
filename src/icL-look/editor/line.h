#ifndef icL_look_editor_Line
#define icL_look_editor_Line

#include <QColor>
#include <QObject>

namespace icL::look::editor {

/**
 * @brief The Line class describes a look for a line
 */
class Line : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor       lineBg READ lineBg       WRITE setLineBg       NOTIFY lineBgChanged)
	Q_PROPERTY(QColor lineNumberBg READ lineNumberBg WRITE setLineNumberBg NOTIFY lineNumberBgChanged)
	Q_PROPERTY(QColor   lineNumber READ lineNumber   WRITE setLineNumber   NOTIFY lineNumberChanged)
	// clang-format on

	QColor m_lineBg;
	QColor m_lineNumberBg;
	QColor m_lineNumber;

public:
	/**
	 * @brief Line is the default contructor
	 * @param parent is the default QObject arg
	 */
	explicit Line(QObject * parent = nullptr);

	/**
	 * @brief lineBg is the backgound color of highlighted line
	 * @return the color for hightlighted line
	 */
	QColor lineBg() const;

	/**
	 * @brief lineNumberBg is the backgound color of line number of highlighted
	 * line
	 * @return the background color for line number of highlighted line
	 */
	QColor lineNumberBg() const;

	/**
	 * @brief lineNumber is the color of line number
	 * @return the color for line number
	 */
	QColor lineNumber() const;

signals:
	void lineBgChanged(QColor lineBg);
	void lineNumberBgChanged(QColor lineNumberBg);
	void lineNumberChanged(QColor lineNumber);

public slots:
	/**
	 * @brief setLineBg changes the background of the highlighted line
	 * @param lineBg is the new background color for highlighted line
	 */
	void setLineBg(QColor lineBg);

	/**
	 * @brief setLineNumberBg changes the background color of line number
	 * @param lineNumberBg is the new backgound color for line number
	 */
	void setLineNumberBg(QColor lineNumberBg);

	/**
	 * @brief setLineNumber changes the color of line number
	 * @param lineNumber is the new color for line number
	 */
	void setLineNumber(QColor lineNumber);
};

}  // namespace icL::look::editor

#endif  // icL_look_editor_Line
