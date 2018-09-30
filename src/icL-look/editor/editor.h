#ifndef icL_look_start_Editor
#define icL_look_start_Editor

#include "../base/base.h"
#include "charformat.h"
#include "highlight.h"
#include "line.h"

#include <QObject>



namespace icL::look::editor {

/**
 * @brief The Editor class defines a color scheme for an editor
 */
class Editor : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(CharFormat*      text READ text       WRITE setText       NOTIFY textChanged)
	Q_PROPERTY(CharFormat* selection READ selection  WRITE setSelection  NOTIFY selectionChanged)
	Q_PROPERTY(CharFormat*    number READ number     WRITE setNumber     NOTIFY numberChanged)
	Q_PROPERTY(CharFormat*    string READ string     WRITE setString     NOTIFY stringChanged)
	Q_PROPERTY(CharFormat*      type READ type       WRITE setType       NOTIFY typeChanged)
	Q_PROPERTY(CharFormat*     local READ local      WRITE setLocal      NOTIFY localChanged)
	Q_PROPERTY(CharFormat*    global READ global     WRITE setGlobal     NOTIFY globalChanged)
	Q_PROPERTY(CharFormat*  property READ property   WRITE setProperty   NOTIFY propertyChanged)
	Q_PROPERTY(CharFormat*    method READ method     WRITE setMethod     NOTIFY methodChanged)
	Q_PROPERTY(CharFormat*  function READ function   WRITE setFunction   NOTIFY functionChanged)
	Q_PROPERTY(CharFormat*   keyword READ keyword    WRITE setKeyword    NOTIFY keywordChanged)
	Q_PROPERTY(CharFormat*   comment READ comment    WRITE setComment    NOTIFY commentChanged)
	Q_PROPERTY(CharFormat*    system READ system     WRITE setSystem     NOTIFY systemChanged)
	Q_PROPERTY(CharFormat*     error READ error      WRITE setError      NOTIFY errorChanged)
	Q_PROPERTY(CharFormat*   warning READ warning    WRITE setWarning    NOTIFY warningChanged)
	Q_PROPERTY(Highlight* occurrence READ occurrence WRITE setOccurrence NOTIFY occurrenceChanged)
	Q_PROPERTY(Line*         current READ current    WRITE setCurrent    NOTIFY currentChanged)
	Q_PROPERTY(Line*           debug READ debug      WRITE setDebug      NOTIFY debugChanged)
	Q_PROPERTY(Line*      breakpoint READ breakpoint WRITE setBreakpoint NOTIFY breakpointChanged)
	// clang-format on

	CharFormat * m_text       = nullptr;
	CharFormat * m_selection  = nullptr;
	CharFormat * m_number     = nullptr;
	CharFormat * m_string     = nullptr;
	CharFormat * m_type       = nullptr;
	CharFormat * m_local      = nullptr;
	CharFormat * m_global     = nullptr;
	CharFormat * m_property   = nullptr;
	CharFormat * m_method     = nullptr;
	CharFormat * m_function   = nullptr;
	CharFormat * m_keyword    = nullptr;
	CharFormat * m_comment    = nullptr;
	CharFormat * m_system     = nullptr;
	CharFormat * m_error      = nullptr;
	CharFormat * m_warning    = nullptr;
	Highlight *  m_occurrence = nullptr;
	Line *       m_current    = nullptr;
	Line *       m_debug      = nullptr;
	Line *       m_breakpoint = nullptr;

public:
	/**
	 * @brief Editor is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Editor(QObject * parent = nullptr);

	~Editor();

	/**
	 * @brief text is the defalt text look
	 * @return the default text look
	 */
	CharFormat * text() const;

	/**
	 * @brief selection is the look of text selection
	 * @return the selection text look
	 */
	CharFormat * selection() const;

	/**
	 * @brief number is the look of numbers
	 * @return the look for numbers
	 */
	CharFormat * number() const;

	/**
	 * @brief string is the look of strings
	 * @return the look for string
	 */
	CharFormat * string() const;

	/**
	 * @brief type is the look of data types
	 * @return the look for data types
	 */
	CharFormat * type() const;

	/**
	 * @brief local is the look of local variables
	 * @return the look for local variables
	 */
	CharFormat * local() const;

	/**
	 * @brief global is the look of global variables
	 * @return the look for global variables
	 */
	CharFormat * global() const;

	/**
	 * @brief property is the look of properties
	 * @return the look for properties
	 */
	CharFormat * property() const;

	/**
	 * @brief method is the look of methods
	 * @return the look for methods
	 */
	CharFormat * method() const;

	/**
	 * @brief function is the look of functions
	 * @return the look for functions
	 */
	CharFormat * function() const;

	/**
	 * @brief keyword is the look of keywords
	 * @return the look for keywords
	 */
	CharFormat * keyword() const;

	/**
	 * @brief comment is the look of comments
	 * @return the look for comments
	 */
	CharFormat * comment() const;

	/**
	 * @brief system is the look of system types
	 * @return the look for sytem types
	 */
	CharFormat * system() const;

	/**
	 * @brief error is the look of inline errors
	 * @return the look for inline errors
	 */
	CharFormat * error() const;

	/**
	 * @brief warning is the look of inline warning
	 * @return the look for inline warnings
	 */
	CharFormat * warning() const;

	/**
	 * @brief occurrence is the look of eccurrences
	 * @return the look for occurrences
	 */
	Highlight * occurrence() const;

	/**
	 * @brief current is the look of current line
	 * @return the look for current line
	 */
	Line * current() const;

	/**
	 * @brief debug is the look of running line
	 * @return the look for running line
	 */
	Line * debug() const;

	/**
	 * @brief breakpoint is the look of break line
	 * @return the look for break line
	 */
	Line * breakpoint() const;

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:
	void textChanged(CharFormat * text);
	void selectionChanged(CharFormat * selection);
	void numberChanged(CharFormat * number);
	void stringChanged(CharFormat * string);
	void typeChanged(CharFormat * type);
	void localChanged(CharFormat * local);
	void globalChanged(CharFormat * global);
	void propertyChanged(CharFormat * property);
	void methodChanged(CharFormat * method);
	void functionChanged(CharFormat * function);
	void keywordChanged(CharFormat * keyword);
	void commentChanged(CharFormat * comment);
	void systemChanged(CharFormat * system);
	void errorChanged(CharFormat * error);
	void warningChanged(CharFormat * warning);
	void occurrenceChanged(Highlight * occurrence);
	void currentChanged(Line * current);
	void debugChanged(Line * debug);
	void breakpointChanged(Line * breakpoint);

public slots:
	/**
	 * @brief setText changes the default look
	 * @param text is the new default look
	 */
	void setText(CharFormat * text);

	/**
	 * @brief setSelection changes the look of selection
	 * @param selection is the new look for selection
	 */
	void setSelection(CharFormat * selection);

	/**
	 * @brief setNumber changes the look of number
	 * @param number is the new look for numbers
	 */
	void setNumber(CharFormat * number);

	/**
	 * @brief setString changes the look of string
	 * @param string is the new look for string
	 */
	void setString(CharFormat * string);

	/**
	 * @brief setType changes the look of types
	 * @param type is the new look for types
	 */
	void setType(CharFormat * type);

	/**
	 * @brief setLocal changes the look of local variables
	 * @param local is the new look for local variables
	 */
	void setLocal(CharFormat * local);

	/**
	 * @brief setGlobal changes the look of global variables
	 * @param global is the new look for global variables
	 */
	void setGlobal(CharFormat * global);

	/**
	 * @brief setProperty changes the look of properties
	 * @param property is the new look for properties
	 */
	void setProperty(CharFormat * property);

	/**
	 * @brief setMethod changes the look of methods
	 * @param method is the new look for methods
	 */
	void setMethod(CharFormat * method);

	/**
	 * @brief setFunction changes the look of functions
	 * @param function is the new look for functions
	 */
	void setFunction(CharFormat * function);

	/**
	 * @brief setKeyword changes the look of keywords
	 * @param keyword is the new look for keywords
	 */
	void setKeyword(CharFormat * keyword);

	/**
	 * @brief setComment changes the look of comments
	 * @param comment is the new look for comments
	 */
	void setComment(CharFormat * comment);

	/**
	 * @brief setSystem changes the look of system types
	 * @param system is the new look for system types
	 */
	void setSystem(CharFormat * system);

	/**
	 * @brief setError changes the look of inline errors
	 * @param error is the new look for inline errors
	 */
	void setError(CharFormat * error);

	/**
	 * @brief setWarning changes the look of inline warnings
	 * @param warning is the new look for inline warnings
	 */
	void setWarning(CharFormat * warning);

	/**
	 * @brief setOccurrence changes the look of occurrences
	 * @param occurrence is the new look for occurrences
	 */
	void setOccurrence(Highlight * occurrence);

	/**
	 * @brief setCurrent changes the look of current line
	 * @param current is the new look for current line
	 */
	void setCurrent(Line * current);

	/**
	 * @brief setDebug changes the look of running line
	 * @param debug is the new look for running line
	 */
	void setDebug(Line * debug);

	/**
	 * @brief setBreakpoint changes the look of break lines
	 * @param breakpoint is the new look for break lines
	 */
	void setBreakpoint(Line * breakpoint);
};

}  // namespace icL::look::editor

#endif  // icL_look_start_Editor
