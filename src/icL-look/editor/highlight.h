#ifndef icL_look_editor_Highlight
#define icL_look_editor_Highlight

#include "../base/base.h"

#include <QColor>



namespace icL::look::editor {

/**
 * @brief The Highlight class describes a look for highlighting fragment of text
 */
class Highlight : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
	Q_PROPERTY(QColor     border READ border     WRITE setBorder     NOTIFY borderChanged)
	// clang-format on

	QColor m_background;
	QColor m_border;

public:
	/**
	 * @brief Highlight is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Highlight(QObject * parent = nullptr);

	/**
	 * @brief background is the color of background
	 * @return the color for background
	 */
	QColor background() const;

	/**
	 * @brief border is the color of border
	 * @return the color for border
	 */
	QColor border() const;

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:
	void backgroundChanged(QColor background);
	void borderChanged(QColor border);

public slots:
	/**
	 * @brief setBackground changes the color of background
	 * @param background is the new color for background
	 */
	void setBackground(QColor background);
	/**
	 * @brief setBorder changes the color of border
	 * @param border is the new color for border
	 */
	void setBorder(QColor border);
};

}  // namespace icL::look::editor

#endif  // icL_look_editor_Highlight
