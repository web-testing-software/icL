#ifndef icL_look_ScrollBar
#define icL_look_ScrollBar

#include "../base/baselook.h"

#include <QColor>



namespace icL::look {

/**
 * @brief The ScrollBar class describes a look for a scroll bar
 */
class ScrollBar : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
	Q_PROPERTY(QColor        bar READ bar        WRITE setBar        NOTIFY barChanged)
	Q_PROPERTY(QColor   barHover READ barHover   WRITE setBarHover   NOTIFY barHoverChanged)
	// clang-format on

public:
	explicit ScrollBar(QObject * parent);

	/**
	 * @brief background gets the background color
	 * @return the background color
	 */
	QColor background() const;

	/**
	 * @brief bar gets the bar color
	 * @return the bar color
	 */
	QColor bar() const;

	/**
	 * @brief barHover gets the color of hovered bar
	 * @return the bar color
	 */
	QColor barHover() const;

signals:
	void backgroundChanged(QColor background);
	void barChanged(QColor bar);
	void barHoverChanged(QColor barHover);

public slots:
	/**
	 * @brief setBackground sets the background color
	 * @param background is the new background color
	 */
	void setBackground(const QColor & background);

	/**
	 * @brief setBar sets the bar color
	 * @param bar is the new color for bar
	 */
	void setBar(const QColor & bar);

	/**
	 * @brief setBarHover sets the bar of hovered bar
	 * @param barHover is the new color for hovered bar
	 */
	void setBarHover(const QColor & barHover);

	// BaseLook interface
public:
	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

private:
	/// @brief the background color
	QColor m_background;

	/// @brief the bar color
	QColor m_bar;

	/// @brief the color of hovered bar
	QColor m_barHover;
};

}  // namespace icL::look

#endif  // icL_look_ScrollBar
