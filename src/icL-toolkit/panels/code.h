#ifndef icL_toolkit_panels_Code
#define icL_toolkit_panels_Code

#include <QObject>

namespace icL::toolkit::panels {

class Code : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(bool leftPanel READ leftPanel WRITE setLeftPanel NOTIFY leftPanelChanged)
	Q_PROPERTY(bool   browser READ browser   WRITE setBrowser   NOTIFY browserChanged)
	// clang-format on

public:
	explicit Code(QObject * parent = nullptr);

	/**
	 * @brief leftPanel is the visibility of left panel
	 * @return the visibility of left panel
	 */
	bool leftPanel() const;

	/**
	 * @brief browser is the visibility of web view
	 * @return the visibility of web view
	 */
	bool browser() const;

signals:
	void leftPanelChanged(bool leftPanel);
	void browserChanged(bool browser);

public slots:
	/**
	 * @brief setLeftPanel changes the visibility of left panel
	 * @param leftPanel is the new visibility for left panel
	 */
	void setLeftPanel(bool leftPanel);

	/**
	 * @brief setBrowser changes the visibility of web view
	 * @param browser it the new visibility of web view
	 */
	void setBrowser(bool browser);

private:
	bool m_leftPanel;
	bool m_browser;
};

}  // namespace icL::toolkit::panels

#endif  // icL_toolkit_panels_Code
