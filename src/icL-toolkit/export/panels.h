#ifndef icL_toolkit_panels_Panels
#define icL_toolkit_panels_Panels

#include <QObject>



namespace icL::toolkit::panels {

class Browser;
class Code;
class Debug;

class Panels : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Browser* browser READ browser NOTIFY browserChanged)
	Q_PROPERTY(Code*       code READ code    NOTIFY codeChanged)
	Q_PROPERTY(Debug*     debug READ debug   NOTIFY debugChanged)
	Q_PROPERTY(bool projectsOrFiles READ projectsOrFiles WRITE setProjectsOrFiles NOTIFY projectsOrFilesChanged)
	// clang-format on

public:
	explicit Panels(QObject * parent = nullptr);

	~Panels();

	/**
	 * @brief browser is the visibility of panels in browser mode
	 * @return the visibility for panels in browser mode
	 */
	Browser * browser() const;

	/**
	 * @brief code is the visibility of panels in code mode
	 * @return the visibility for panels in code mode
	 */
	Code * code() const;

	/**
	 * @brief debug is the visibility od panels in debug mode
	 * @return the visibility for panels in debug mode
	 */
	Debug * debug() const;

	/**
	 * @brief projectsOrFiles is the switcher for left panel
	 * @return the switcher state (true - projects, false - files)
	 */
	bool projectsOrFiles() const;

signals:
	void browserChanged(Browser * browser);
	void codeChanged(Code * code);
	void debugChanged(Debug * debug);
	void projectsOrFilesChanged(bool projectsOrFiles);

public slots:

	/**
	 * @brief setProjectsOrFiles switches beetween files and projects
	 * @param projectsOrFiles is the new choose (true - projects, false - files)
	 */
	void setProjectsOrFiles(bool projectsOrFiles);

private:
	Browser * m_browser = nullptr;
	Code *    m_code    = nullptr;
	Debug *   m_debug   = nullptr;

	bool m_projectsOrFiles = true;
};

}  // namespace icL::toolkit::panels

#endif  // icL_toolkit_panels_Panels
