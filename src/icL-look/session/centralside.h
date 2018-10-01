#ifndef icL_look_session_CentralSide
#define icL_look_session_CentralSide

#include "../start/input.h"
#include "issue.h"



namespace icL::look::session {

/**
 * @brief The CentralSide class decribes a look for the central widget
 */
class CentralSide : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text*        header READ header)
	Q_PROPERTY(Issue*               warn READ warn)
	Q_PROPERTY(Issue*              error READ error)
	Q_PROPERTY(base::LinkAdv*  undertext READ undertext)
	Q_PROPERTY(base::LinkAdv* underdigit READ underdigit)
	Q_PROPERTY(QColor            command READ command     WRITE setCommand     NOTIFY commandChanged)
	Q_PROPERTY(QColor        errorResult READ errorResult WRITE setErrorResult NOTIFY errorResultChanged)
	Q_PROPERTY(QColor           okResult READ okResult    WRITE setOkResult    NOTIFY okResultChanged)
	Q_PROPERTY(start::Input*       input READ input)
	// clang-format on

	base::Text *    m_header     = nullptr;
	Issue *         m_warn       = nullptr;
	Issue *         m_error      = nullptr;
	base::LinkAdv * m_undertext  = nullptr;
	base::LinkAdv * m_underdigit = nullptr;
	start::Input *  m_input      = nullptr;
	QColor          m_command;
	QColor          m_errorResult;
	QColor          m_okResult;

public:
	/**
	 * @brief CentralSide is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit CentralSide(QObject * parent = nullptr);

	~CentralSide();

	/**
	 * @brief header is the look of editor header
	 * @return the look for editor header
	 */
	base::Text * header() const;

	/**
	 * @brief warn is the look of a warning
	 * @return the look for a warning
	 */
	Issue * warn() const;

	/**
	 * @brief error is a look of an error
	 * @return the look for an error
	 */
	Issue * error() const;

	/**
	 * @brief undertext is the look for the text in state bar
	 * @return the look for the text in the state bar
	 */
	base::LinkAdv * undertext() const;

	/**
	 * @brief underdigit is the look for digits in the state bar
	 * @return the look for digits in the state bar
	 */
	base::LinkAdv * underdigit() const;

	/**
	 * @brief command is the color of commands in console
	 * @return the color for commands in console
	 */
	QColor command() const;

	/**
	 * @brief errorResult is the color for errors in console
	 * @return the color for results in console
	 */
	QColor errorResult() const;

	/**
	 * @brief okResult is the color of the result in console
	 * @return the color for result in console
	 */
	QColor okResult() const;

	/**
	 * @brief input is the look for command input
	 * @return the look for commad input
	 */
	start::Input * input() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void commandChanged(QColor command);
	void errorResultChanged(QColor errorResult);
	void okResultChanged(QColor okResult);

public slots:
	/**
	 * @brief setCommand shanges the color of commands in console
	 * @param command is the new color for comands in console
	 */
	void setCommand(QColor command);

	/**
	 * @brief setErrorResult changes the color of errors in console
	 * @param errorResult is the new color for errors in console
	 */
	void setErrorResult(QColor errorResult);

	/**
	 * @brief setOkResult changes the color of results in console
	 * @param okResult is the nre color for results in console
	 */
	void setOkResult(QColor okResult);
};

}  // namespace icL::look::session

#endif  // icL_look_session_CentralSide
