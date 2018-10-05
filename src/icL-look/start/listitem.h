#ifndef icL_look_start_ListItem
#define icL_look_start_ListItem

#include "../base/link.h"



class Effect;

/**
 * @brief The ListItem class describes a look for a list item
 */
class ListItem : public Link
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Effect * border READ border NOTIFY borderChanged)
	// clang-format on

	Effect * m_border = nullptr;

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
	Effect * border() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void borderChanged(Effect * border);
};

#endif  // icL_look_start_ListItem
