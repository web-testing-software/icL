#ifndef SIDE_H
#define SIDE_H

#include "listitem.h"

#include <QObject>

namespace icL::look::start {

class Side : public ListItem
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text* header READ header WRITE setHeader NOTIFY headerChanged)
	// clang-format on

	base::Text * m_header = nullptr;

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

signals:
	void headerChanged(base::Text * header);

public slots:
	/**
	 * @brief headerChanged changes the look for a side header
	 * @param header is the new look for a side header
	 */
	void setHeader(base::Text * header);
};

}  // namespace icL::look::start

#endif  // SIDE_H
