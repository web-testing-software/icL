#ifndef icL_look_start_Editor
#define icL_look_start_Editor

#include "../base/baselook.h"


class QTextCharFormat;

namespace icL::look {

class CharFormat;
class Highlight;
class Line;

/**
 * @brief The Editor class defines a color scheme for an editor
 */
class Editor : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(CharFormat*      text READ text       NOTIFY textChanged)
	Q_PROPERTY(CharFormat* selection READ selection  NOTIFY selectionChanged)
	Q_PROPERTY(CharFormat*    number READ number     NOTIFY numberChanged)
	Q_PROPERTY(CharFormat*    string READ string     NOTIFY stringChanged)
	Q_PROPERTY(CharFormat*      type READ type       NOTIFY typeChanged)
	Q_PROPERTY(CharFormat*     local READ local      NOTIFY localChanged)
	Q_PROPERTY(CharFormat*    global READ global     NOTIFY globalChanged)
	Q_PROPERTY(CharFormat*  property READ property   NOTIFY propertyChanged)
	Q_PROPERTY(CharFormat*    method READ method     NOTIFY methodChanged)
	Q_PROPERTY(CharFormat*  function READ function   NOTIFY functionChanged)
	Q_PROPERTY(CharFormat*   keyword READ keyword    NOTIFY keywordChanged)
	Q_PROPERTY(CharFormat*   comment READ comment    NOTIFY commentChanged)
	Q_PROPERTY(CharFormat*    system READ system     NOTIFY systemChanged)
	Q_PROPERTY(CharFormat*     error READ error      NOTIFY errorChanged)
	Q_PROPERTY(CharFormat*   warning READ warning    NOTIFY warningChanged)
	Q_PROPERTY(Highlight* occurrence READ occurrence NOTIFY occurrenceChanged)
	Q_PROPERTY(Line*         current READ current    NOTIFY currentChanged)
	Q_PROPERTY(Line*           debug READ debug      NOTIFY debugChanged)
	Q_PROPERTY(Line*      breakpoint READ breakpoint NOTIFY breakpointChanged)
	// clang-format on

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

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

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
	void updateOccurrence();
	void updateNumber();
	void updateString();
	void updateType();
	void updateLocal();
	void updateGlobal();
	void updateProperty();
	void updateMethod();
	void updateFunction();
	void updateKeyword();
	void updateComment();
	void updateSystem();
	void updateError();
	void updateWarning();

private:
	void updateStyle(QTextCharFormat & chars, const CharFormat * format);

	void bindChars();
	void bindHighlights();
	void bindMessages();

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
};

}  // namespace icL::look

#endif  // icL_look_start_Editor
