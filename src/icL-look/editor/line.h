#ifndef icL_look_Line
#define icL_look_Line

#include "../base/baselook.h"

#include <QColor>



namespace icL::look {

class CharFormatBase;

/**
 * @brief The Line class describes a look for a line
 */
class Line : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor lineBg READ lineBg WRITE setLineBg NOTIFY lineBgChanged)
	Q_PROPERTY(icL::look::CharFormatBase* lineNumber READ lineNumber NOTIFY lineNumberChanged)
	// clang-format on

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
	void lineNumberChanged(CharFormatBase * lineNumber);

public slots:
	/**
	 * @brief setLineBg changes the background of the highlighted line
	 * @param lineBg is the new background color for highlighted line
	 */
	void setLineBg(const QColor & lineBg);

private:
	QColor           m_lineBg;
	CharFormatBase * m_lineNumber;
};

class CLine : public Line
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor edited READ edited WRITE setEdited NOTIFY editedChanged)
	Q_PROPERTY(QColor  saved READ saved  WRITE setSaved  NOTIFY savedChanged)
	// clang-format on

public:
	CLine(QObject * parent = nullptr);

	/**
	 * @brief edited is a color to highlight edited line
	 * @return the color for hightlight edited lines
	 */
	QColor edited() const;

	/**
	 * @brief saved is a color to highlight saved line
	 * @return the color for highlight saved line
	 */
	QColor saved() const;

signals:
	void editedChanged(QColor edited);
	void savedChanged(QColor saved);

public slots:
	/**
	 * @brief setEdited changes the color for edited lines
	 * @param edited is the new color to edited edited lines
	 */
	void setEdited(const QColor & edited);

	/**
	 * @brief setSaved changes the color for saved lines
	 * @param saved is the new color for saved lines
	 */
	void setSaved(const QColor & saved);

	// BaseLook interface
public:
	void        setUp(const QJsonObject & obj) override;
	QJsonObject getUp() override;

private:
	QColor m_saved;
	QColor m_edited;
};

}  // namespace icL::look

#endif  // icL_look_Line
