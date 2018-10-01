#ifndef icL_look_session_LeftSide
#define icL_look_session_LeftSide

#include "../start/listitem.h"
#include "tree.h"



namespace icL::look::session {

/**
 * @brief The LeftSide class describes a look for the left panel
 */
class LeftSide : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Link*   switcher READ switcher)
	Q_PROPERTY(Tree*         projects READ projects)
	Q_PROPERTY(start::ListItem* files READ files)
	// clang-format on

	base::Link *      m_switcher = nullptr;
	Tree *            m_projects = nullptr;
	start::ListItem * m_files    = nullptr;

public:
	/**
	 * @brief LeftSide is the default constructor
	 * @param parent is the default QObject arg
	 */
	LeftSide(QObject * parent = nullptr);

	~LeftSide();

	/**
	 * @brief switcher is the look of the projects/files switcher
	 * @return the look of pro/files switcher
	 */
	base::Link * switcher() const;

	/**
	 * @brief projects is the look of projects tree
	 * @return the look of projects tree
	 */
	Tree * projects() const;

	/**
	 * @brief files is the look of open files list
	 * @return the look of projects tree
	 */
	start::ListItem * files() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;
};

}  // namespace icL::look::session

#endif  // icL_look_session_LeftSide
