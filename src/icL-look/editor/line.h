#ifndef icL_look_editor_Line
#define icL_look_editor_Line

#include "charformatbase.h"

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
	Q_PROPERTY(QColor              lineBg READ lineBg     WRITE setLineBg     NOTIFY lineBgChanged)
	Q_PROPERTY(CharFormatBase* lineNumber READ lineNumber WRITE setLineNumber NOTIFY lineNumberChanged)
	// clang-format on

	QColor m_lineBg;
	CharFormatBase* m_lineNumber;

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
	 * @brief lineNumber is the look of line number
	 * @return the look for line number
	 */
	CharFormatBase* lineNumber() const;

signals:
	void lineBgChanged(QColor lineBg);
	void lineNumberChanged(CharFormatBase* lineNumber);

public slots:
	/**
	 * @brief setLineBg changes the background of the highlighted line
	 * @param lineBg is the new background color for highlighted line
	 */
void setLineBg(QColor lineBg);

/**
 * @brief setLineNumber changes the look of line numbers
 * @param lineNumber is the new look for line number
 */
void setLineNumber(CharFormatBase* lineNumber);
};

}  // namespace icL::look::editor

#endif  // icL_look_editor_Line
