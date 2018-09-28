#include "listitem.h"

namespace icL::look::start {

ListItem::ListItem(QObject *parent) : Link(parent)
{

}

base::Effect *ListItem::border() const
{
	return m_border;
}

void ListItem::setBorder(base::Effect *border)
{
	if (m_border == border)
		return;

	m_border = border;
	emit borderChanged(m_border);
}

} // namespace
