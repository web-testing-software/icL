#ifndef icL_look_base_Text
#define icL_look_base_Text

#include "baselook.h"

#include <QColor>



namespace icL::look {

/**
 * @brief The Text class describes a look for a text fragment
 */
class TextLook : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
	Q_PROPERTY(QColor foreground READ foreground WRITE setForeground NOTIFY foregroundChanged)
	// clang-format on

public:
	TextLook(QObject * parent = nullptr);

	/**
	 * @brief background is the background color
	 * @return the background color
	 */
	QColor background() const;

	/**
	 * @brief foreground is the foreground color
	 * @return the forground color
	 */
	QColor foreground() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void backgroundChanged(QColor background);
	void foregroundChanged(QColor foreground);

public slots:
	/**
	 * @brief setBackground changes the background color
	 * @param background is the new backgtound color
	 */
	void setBackground(QColor background);

	/**
	 * @brief setForeground changes the foreground color
	 * @param foreground is the new foreground color
	 */
	void setForeground(QColor foreground);

private:
	QColor m_background;
	QColor m_foreground;
};

}  // namespace icL::look

#endif  // icL_look_base_Text
