#ifndef icL_look_session_Tree
#define icL_look_session_Tree

#include "../base/link.h"

#include <QObject>

namespace icL::look::session {

/**
 * @brief The Tree class describes a look for a tree widget
 */
class Tree : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Link* parent READ parent WRITE setParent NOTIFY parentChanged)
	Q_PROPERTY(base::Link* child  READ child  WRITE setChild  NOTIFY childChanged)
	// clang-format on

	base::Link * m_parent = nullptr;
	base::Link * m_child  = nullptr;

public:
	/**
	 * @brief Tree is the default contructor
	 * @param parent is the default QObject arg
	 */
	explicit Tree(QObject * parent = nullptr);

	~Tree();

	/**
	 * @brief parent is the look for parent (root) item
	 * @return the look for parent item
	 */
	base::Link * parent() const;

	/**
	 * @brief child is the look for child item
	 * @return the look for child item
	 */
	base::Link * child() const;

signals:
	void parentChanged(base::Link * parent);
	void childChanged(base::Link * child);

public slots:
	/**
	 * @brief setParent changes the look of parent items
	 * @param parent the new look for parent items
	 */
	void setParent(base::Link * parent);

	/**
	 * @brief setChild changes the look for children items
	 * @param child the new look for children items
	 */
	void setChild(base::Link * child);
};

}  // namespace icL::look::session

#endif  // icL_look_session_Tree
