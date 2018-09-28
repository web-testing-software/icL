#ifndef icL_look_base_Text
#define icL_look_base_Text

#include <QObject>
#include <QColor>

/**
 * Defines base color container for look component
 */
namespace icL::look::base {

/**
 * @brief The Text class describes a look for a text fragment
 */
class Text : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY
																	 backgroundChanged)
	Q_PROPERTY(QColor foreground READ foreground WRITE setForeground NOTIFY
																	 foregroundChanged)

	QColor m_background;
	QColor m_foreground;

public:
	Text(const QString & fg, const QString & bg, QObject * parent = nullptr);

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
};

}  // namespace icL::look::base

#endif  // icL_look_base_Text
