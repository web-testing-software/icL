#ifndef icL_look_start_ListItem
#define icL_look_start_ListItem

#include "../base/effect.h"
#include "../base/link.h"

#include <QObject>

namespace icL::look::start {

/**
 * @brief The ListItem class describes a look for a list item
 */
class ListItem : public base::Link
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Effect *border READ border WRITE setBorder NOTIFY borderChanged)
	// clang-format on

	base::Effect * m_border = nullptr;

public:
	/**
	 * @brief ListItem is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit ListItem(QObject * parent = nullptr);

	~ListItem();

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

#endif  // icL_look_start_ListItem
