#ifndef icL_look_start_Side
#define icL_look_start_Side

#include "listitem.h"

#include <QObject>

namespace icL::look::start {

/**
 * @brief The Side class describes a look for a start page side
 */
class Side : public ListItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text* header READ header WRITE setHeader NOTIFY headerChanged)
	Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
	// clang-format on

	base::Text * m_header = nullptr;
	QColor       m_background;

public:
	/**
	 * @brief Side is the default contructor
	 * @param parent is the default QObject arg
	 */
	explicit Side(QObject * parent = nullptr);

	~Side();

	/**
	 * @brief header is a look for a side header
	 * @return the look for a side header
	 */
	base::Text * header() const;

	/**
	 * @brief background is the brackground color
	 * @return the color of background
	 */
	QColor background() const;

signals:
	void headerChanged(base::Text * header);
	void backgroundChanged(QColor background);

public slots:
	/**
	 * @brief headerChanged changes the look for a side header
	 * @param header is the new look for a side header
	 */
	void setHeader(base::Text * header);

	/**
	 * @brief setBackground changes the background color
	 * @param background is the new background color
	 */
	void setBackground(QColor background);
};

}  // namespace icL::look::start

#endif  // icL_look_start_Side
