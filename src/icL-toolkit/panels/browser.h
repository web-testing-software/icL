#ifndef icL_toolkit_panels_Browser
#define icL_toolkit_panels_Browser

#include <QObject>

namespace icL::toolkit::panels {

class Browser : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY (bool leftPanel READ leftPanel WRITE setLeftPanel NOTIFY leftPanelChanged)
	Q_PROPERTY (bool  devTools READ devTools  WRITE setDevTools  NOTIFY devToolsChanged)
	// clang-format on

public:
	explicit Browser(QObject * parent = nullptr);

	/**
	 * @brief leftPanel is the visibility of left panel
	 * @return the visibility of left panel
	 */
	bool leftPanel() const;

	/**
	 * @brief devTools is the visibility of dev tools
	 * @return the visibility of dev tools
	 */
	bool devTools() const;

signals:
	void leftPanelChanged(bool leftPanel);
	void devToolsChanged(bool devTools);

public slots:
	/**
	 * @brief setLeftPanel changes the visibility of left panel
	 * @param leftPanel is the new visibility for left panel
	 */
	void setLeftPanel(bool leftPanel);

	/**
	 * @brief setDevTools changes the visibility of devTools
	 * @param devTools is the new visibility for devTools
	 */
	void setDevTools(bool devTools);

private:
	bool m_leftPanel;
	bool m_devTools;
};

}  // namespace icL::toolkit::panels

#endif  // icL_toolkit_panels_Browser
