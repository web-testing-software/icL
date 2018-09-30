#ifndef icL_look_session_Floating
#define icL_look_session_Floating

#include "../start/input.h"
#include "tree.h"



namespace icL::look::session {

/**
 * @brief The Floating class describes the look for the floating panel
 */
class Floating : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text*  header READ header  WRITE setHeader  NOTIFY headerChanged)
	Q_PROPERTY(Tree*         stack READ stack   WRITE setStack   NOTIFY stackChanged)
	Q_PROPERTY(Tree*         state READ state   WRITE setState   NOTIFY stateChanged)
	Q_PROPERTY(QColor        error READ error   WRITE setError   NOTIFY errorChanged)
	Q_PROPERTY(QColor         warn READ warn    WRITE setWarn    NOTIFY warnChanged)
	Q_PROPERTY(QColor      console READ console WRITE setConsole NOTIFY consoleChanged)
	Q_PROPERTY(start::Input* input READ input   WRITE setInput   NOTIFY inputChanged)
	Q_PROPERTY(QColor           bg READ bg      WRITE setBg      NOTIFY bgChanged)
	// clang-format on

	base::Text *   m_header = nullptr;
	Tree *         m_stack  = nullptr;
	Tree *         m_state  = nullptr;
	start::Input * m_input  = nullptr;
	QColor         m_error;
	QColor         m_warn;
	QColor         m_console;
	QColor         m_bg;

public:
	/**
	 * @brief Floating is the default constructor
	 * @param parent is the default QObject arg
	 */
	Floating(QObject * parent = nullptr);

	~Floating();

	/**
	 * @brief header is the look of headers
	 * @return the look for headers
	 */
	base::Text * header() const;

	/**
	 * @brief stack is the look of stack view
	 * @return the look for stack view
	 */
	Tree * stack() const;

	/**
	 * @brief state is the look of states view
	 * @return the look for states view
	 */
	Tree * state() const;

	/**
	 * @brief error is the color of error messages in console
	 * @return the color for error messages in console
	 */
	QColor error() const;

	/**
	 * @brief warn is the color of warnings in console
	 * @return the color for warninngs in console
	 */
	QColor warn() const;

	/**
	 * @brief console is the color of text in console
	 * @return the color for text in console
	 */
	QColor console() const;

	/**
	 * @brief input is the look of command input of console
	 * @return the look for command input of console
	 */
	start::Input * input() const;

	/**
	 * @brief bg is the color of background
	 * @return the color for background
	 */
	QColor bg() const;

	void setUp(const QJsonObject & obj) override;

signals:
	void headerChanged(base::Text * header);
	void stackChanged(Tree * stack);
	void stateChanged(Tree * state);
	void errorChanged(QColor error);
	void warnChanged(QColor warn);
	void consoleChanged(QColor console);
	void inputChanged(start::Input * input);
	void bgChanged(QColor bg);

public slots:
	/**
	 * @brief setHeader changes the look of headers
	 * @param header is the new look for headers
	 */
	void setHeader(base::Text * header);

	/**
	 * @brief setStack changes the look of stack view
	 * @param stack is the new look for stack view
	 */
	void setStack(Tree * stack);

	/**
	 * @brief setState changes the look of states view
	 * @param state is the new look for sttates view
	 */
	void setState(Tree * state);

	/**
	 * @brief setError changes the color of errors in console
	 * @param error is the new color for errors in console
	 */
	void setError(QColor error);

	/**
	 * @brief setWarn changes the color of warnings in console
	 * @param warn is the new color for warnings in console
	 */
	void setWarn(QColor warn);

	/**
	 * @brief setConsole changes the color of text in console
	 * @param console is the new color for text in console
	 */
	void setConsole(QColor console);

	/**
	 * @brief setInput changes the look of command input
	 * @param input is the new look for command input
	 */
	void setInput(start::Input * input);

	/**
	 * @brief setBg changes the color of background
	 * @param bg is the new color for background
	 */
	void setBg(QColor bg);
};

}  // namespace icL::look::session

#endif  // icL_look_session_Floating
