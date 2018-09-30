#ifndef icL_look_session_Tree
#define icL_look_session_Tree

#include "../base/link.h"



namespace icL::look::session {

/**
 * @brief The Tree class describes a look for a tree widget
 */
class Tree : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Link* parent READ parent)
	Q_PROPERTY(base::Link*  child READ child)
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

	void setUp(const QJsonObject & obj) override;
};

}  // namespace icL::look::session

#endif  // icL_look_session_Tree
