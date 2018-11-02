#ifndef icL_toolkit_panels_Debug
#define icL_toolkit_panels_Debug

#include "basepanels.h"



namespace icL::toolkit::panels {

/**
 * @brief The Debug class describes the visibility of panels in debug mode
 */
class Debug : public BasePanels
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(bool   stack READ stack   WRITE setStack   NOTIFY stackChanged)
	Q_PROPERTY(bool   state READ state   WRITE setState   NOTIFY stateChanged)
	Q_PROPERTY(bool console READ console WRITE setConsole NOTIFY consoleChanged)
	Q_PROPERTY(bool browser READ browser WRITE setBrowser NOTIFY browserChanged)
	// clang-format on

public:
	explicit Debug(QObject * parent = nullptr);

	/**
	 * @brief stack is the visibility of stack panel
	 * @return the visibility for stack panel
	 */
	bool stack() const;

	/**
	 * @brief state is the visibility of state panel
	 * @return the visibility for stack panel
	 */
	bool state() const;

	/**
	 * @brief console is the visibility of console panel
	 * @return the visibility for console panel
	 */
	bool console() const;

	/**
	 * @brief browser is the visibility of web view
	 * @return the visibility for web view
	 */
	bool browser() const;

	// BasePanels interface
	void        setUp(const QJsonObject & obj) override;
	QJsonObject getUp() override;

signals:
	void stackChanged(bool stack);
	void stateChanged(bool state);
	void consoleChanged(bool console);
	void browserChanged(bool browser);

public slots:
	/**
	 * @brief setStack changes the visibility of stack panel
	 * @param stack is the new visibility for stack panel
	 */
	void setStack(bool stack);

	/**
	 * @brief setState changes the visibility of state panel
	 * @param state is the new visibility for state panel
	 */
	void setState(bool state);

	/**
	 * @brief setConsole changes the visibility of console panel
	 * @param console is the new visibility for console panel
	 */
	void setConsole(bool console);

	/**
	 * @brief setBrowser changes the visibility of console panel
	 * @param browser is the new visibility for console panel
	 */
	void setBrowser(bool browser);

private:
	bool m_stack   = true;
	bool m_state   = true;
	bool m_console = true;
	bool m_browser = true;
};

}  // namespace icL::toolkit::panels

#endif  // icL_toolkit_panels_Debug
