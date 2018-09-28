#ifndef LISTITEM_H
#define LISTITEM_H

#include "../base/effect.h"
#include "../base/link.h"

#include <QObject>

namespace icL::look::start {

class ListItem : public base::Link
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Effect *border READ border WRITE setBorder NOTIFY borderChanged)
	// clang-format on

	base::Effect * m_border;

public:
	/**
	 * @brief ListItem is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit ListItem(QObject * parent = nullptr);

	/**
	 * @brief border is the color of border for list items
	 * @return the color of list item border
	 */
	base::Effect * border() const;

signals:
	void borderChanged(base::Effect * border);

public slots:
	/**
	 * @brief setBorder changes the border color for list items
	 * @param border is the new border color for list items
	 */
	void setBorder(base::Effect * border);
};

}  // namespace icL::look::start

#endif  // LISTITEM_H
