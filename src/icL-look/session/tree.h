#ifndef icL_look_session_Tree
#define icL_look_session_Tree

#include "../base/baselook.h"



namespace icL::look {

class Link;

/**
 * @brief The Tree class describes a look for a tree widget
 */
class Tree : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::Link* parent READ parent NOTIFY parentChanged)
	Q_PROPERTY(icL::look::Link*  child READ child  NOTIFY childChanged)
	// clang-format on

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
	Link * parent() const;

	/**
	 * @brief child is the look for child item
	 * @return the look for child item
	 */
	Link * child() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void parentChanged(Link * parent);
	void childChanged(Link * child);

private:
	Link * m_parent = nullptr;
	Link * m_child  = nullptr;
};

}  // namespace icL::look

#endif  // icL_look_session_Tree
