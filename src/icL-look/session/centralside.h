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
	Q_PROPERTY(base::Text*        header READ header      WRITE setHeader      NOTIFY headerChanged)
	Q_PROPERTY(Issue*               warn READ warn        WRITE setWarn        NOTIFY warnChanged)
	Q_PROPERTY(Issue*              error READ error       WRITE setError       NOTIFY errorChanged)
	Q_PROPERTY(base::LinkAdv*  undertext READ undertext   WRITE setUndertext   NOTIFY undertextChanged)
	Q_PROPERTY(base::LinkAdv* underdigit READ underdigit  WRITE setUnderdigit  NOTIFY underdigitChanged)
	Q_PROPERTY(QColor            command READ command     WRITE setCommand     NOTIFY commandChanged)
	Q_PROPERTY(QColor        errorResult READ errorResult WRITE setErrorResult NOTIFY errorResultChanged)
	Q_PROPERTY(QColor           okResult READ okResult    WRITE setOkResult    NOTIFY okResultChanged)
	Q_PROPERTY(start::Input*       input READ input       WRITE setInput       NOTIFY inputChanged)
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

signals:
	void headerChanged(base::Text * header);
	void warnChanged(Issue * warn);
	void errorChanged(Issue * error);
	void undertextChanged(base::LinkAdv * undertext);
	void underdigitChanged(base::LinkAdv * underdigit);
	void commandChanged(QColor command);
	void errorResultChanged(QColor errorResult);
	void okResultChanged(QColor okResult);
	void inputChanged(start::Input * input);

public slots:
	/**
	 * @brief setHeader changes the look of header
	 * @param header is the new look for header
	 */
	void setHeader(base::Text * header);

	/**
	 * @brief setWarn changes the look of warnings
	 * @param warn is the new look for warnings
	 */
	void setWarn(Issue * warn);

	/**
	 * @brief setError changes the look of errors
	 * @param error is the new look for errors
	 */
	void setError(Issue * error);

	/**
	 * @brief setUndertext changes the look of text in state bar
	 * @param undertext is the new look for text in state bar
	 */
	void setUndertext(base::LinkAdv * undertext);

	/**
	 * @brief setUnderdigit changes the look of digits in state bar
	 * @param underdigit is the new look for digits in state bar
	 */
	void setUnderdigit(base::LinkAdv * underdigit);

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

	/**
	 * @brief setInput changes the look of command input
	 * @param input is the new look for command input
	 */
	void setInput(start::Input * input);
};

}  // namespace icL::look::session

#endif  // icL_look_session_CentralSide
