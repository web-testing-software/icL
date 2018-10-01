#ifndef icL_look_editor_Line
#define icL_look_editor_Line

#include "../base/base.h"

#include <QColor>



namespace icL::look::editor {

class CharFormatBase;

/**
 * @brief The Line class describes a look for a line
 */
class Line : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor              lineBg READ lineBg WRITE setLineBg NOTIFY lineBgChanged)
	Q_PROPERTY(CharFormatBase* lineNumber READ lineNumber)
	// clang-format on

	QColor           m_lineBg;
	CharFormatBase * m_lineNumber;

public:
	/**
	 * @brief Line is the default contructor
	 * @param parent is the default QObject arg
	 */
	explicit Line(QObject * parent = nullptr);

	~Line();

	/**
	 * @brief lineBg is the backgound color of highlighted line
	 * @return the color for hightlighted line
	 */
	QColor lineBg() const;

	/**
	 * @brief lineNumber is the look of line number
	 * @return the look for line number
	 */
	CharFormatBase * lineNumber() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void lineBgChanged(QColor lineBg);

public slots:
	/**
	 * @brief setLineBg changes the background of the highlighted line
	 * @param lineBg is the new background color for highlighted line
	 */
	void setLineBg(QColor lineBg);
};

}  // namespace icL::look::editor

#endif  // icL_look_editor_Line
