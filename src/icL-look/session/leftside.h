#ifndef icL_look_session_LeftSide
#define icL_look_session_LeftSide

#include "../base/baselook.h"


class Link;
class ListItem;
class Tree;

/**
 * @brief The LeftSide class describes a look for the left panel
 */
class LeftSide : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Link*    switcher READ switcher NOTIFY switcherChanged)
	Q_PROPERTY(Tree* projects READ projects NOTIFY projectsChanged)
	Q_PROPERTY(ListItem*  files READ files    NOTIFY filesChanged)
	// clang-format on

	Link *      m_switcher = nullptr;
	Tree *            m_projects = nullptr;
	ListItem * m_files    = nullptr;

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
	Link * switcher() const;

	/**
	 * @brief projects is the look of projects tree
	 * @return the look of projects tree
	 */
	Tree * projects() const;

	/**
	 * @brief files is the look of open files list
	 * @return the look of projects tree
	 */
	ListItem * files() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void switcherChanged(Link * switcher);
	void projectsChanged(Tree * projects);
	void filesChanged(ListItem * files);
};

#endif  // icL_look_session_LeftSide
