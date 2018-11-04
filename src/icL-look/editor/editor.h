#ifndef icL_look_Editor
#define icL_look_Editor

#include "../base/baselook.h"
#include "scrollbar.h"


class QTextCharFormat;

namespace icL::look {

class CharFormat;
class Highlight;
class Line;
class CLine;
class Change;
class EditorStyle;
class Chars;
struct TextCharFormat;
struct LineFormat;

/**
 * @brief The Editor class defines a color scheme for an editor
 */
class Editor : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::EditorStyle*    style READ style      NOTIFY styleChanged)
	Q_PROPERTY(icL::look::Chars*          chars READ chars      NOTIFY charsChanged)
	Q_PROPERTY(icL::look::CharFormat*      text READ text       NOTIFY textChanged)
	Q_PROPERTY(icL::look::CharFormat*    number READ number     NOTIFY numberChanged)
	Q_PROPERTY(icL::look::CharFormat*    string READ string     NOTIFY stringChanged)
	Q_PROPERTY(icL::look::CharFormat*      type READ type       NOTIFY typeChanged)
	Q_PROPERTY(icL::look::CharFormat*     local READ local      NOTIFY localChanged)
	Q_PROPERTY(icL::look::CharFormat*    global READ global     NOTIFY globalChanged)
	Q_PROPERTY(icL::look::CharFormat*  property READ property   NOTIFY propertyChanged)
	Q_PROPERTY(icL::look::CharFormat*    method READ method     NOTIFY methodChanged)
	Q_PROPERTY(icL::look::CharFormat*  function READ function   NOTIFY functionChanged)
	Q_PROPERTY(icL::look::CharFormat*   keyword READ keyword    NOTIFY keywordChanged)
	Q_PROPERTY(icL::look::CharFormat*   comment READ comment    NOTIFY commentChanged)
	Q_PROPERTY(icL::look::CharFormat*    system READ system     NOTIFY systemChanged)
	Q_PROPERTY(icL::look::CharFormat*     error READ error      NOTIFY errorChanged)
	Q_PROPERTY(icL::look::CharFormat*   warning READ warning    NOTIFY warningChanged)
	Q_PROPERTY(icL::look::Highlight* occurrence READ occurrence NOTIFY occurrenceChanged)
	Q_PROPERTY(icL::look::Highlight*  selection READ occurrence NOTIFY occurrenceChanged)
	Q_PROPERTY(icL::look::Line*         current READ current    NOTIFY currentChanged)
	Q_PROPERTY(icL::look::Line*           debug READ debug      NOTIFY debugChanged)
	Q_PROPERTY(icL::look::Line*      breakpoint READ breakpoint NOTIFY breakpointChanged)
	Q_PROPERTY(icL::look::Line*         phantom READ phantom    NOTIFY phantomChanged)
	Q_PROPERTY(icL::look::CLine*          cline READ cline      NOTIFY clineChanged)
	Q_PROPERTY(icL::look::ScrollBar*  scrollBar READ scrollBar  NOTIFY scrollBarChanged)
	Q_PROPERTY(icL::look::Change*       changes READ changes    NOTIFY changesChanged)
	// clang-format on

public:
	/**
	 * @brief Editor is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Editor(QObject * parent = nullptr);

	~Editor();

	/**
	 * @brief style is the base style of all editors
	 * @return the base style for all editors
	 */
	EditorStyle * style();

	/**
	 * @brief chars is the style of chars shared to editor
	 * @return style of chars shared to editor
	 */
	Chars * chars() const;

	/**
	 * @brief occurrence is the look of eccurrences
	 * @return the look for occurrences
	 */
	Highlight * occurrence() const;

	/**
	 * @brief selection is the look of text selection
	 * @return the selection text look
	 */
	Highlight * selection() const;

	/**
	 * @brief text is the defalt text look
	 * @return the default text look
	 */
	CharFormat * text() const;

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
	 * @brief phantom is the look for phantom lines
	 * @return the look for phantom lines
	 */
	Line * phantom() const;

	/**
	 * @brief cline is the look of line numbers
	 * @return the look for all lines numbers
	 */
	CLine * cline() const;

	/**
	 * @brief scrollBar is the look of scrollbars
	 * @return the look for scrollbars
	 */
	ScrollBar * scrollBar() const;

	/**
	 * @brief changes is the look of changes indicators
	 * @return the look for changes indicators
	 */
	Change * changes() const;

	// BaseLook Interface
	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void styleChanged(EditorStyle * style);
	void charsChanged(Chars * chars);
	void occurrenceChanged(Highlight * occurrence);
	void selectionChanged(Highlight * selection);
	void textChanged(CharFormat * text);
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
	void currentChanged(Line * current);
	void debugChanged(Line * debug);
	void breakpointChanged(Line * breakpoint);
	void phantomChanged(icL::look::Line * phantom);
	void clineChanged(CLine * cline);
	void scrollBarChanged(icL::look::ScrollBar * scrollBar);
	void changesChanged(icL::look::Change * changes);

public slots:
	void updateOccurrence();
	void updateSelection();
	void updateText();
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
	void updateCurrent();
	void updateDebug();
	void updateBreakpoint();
	void updateCLine();
	void updateChanges();

private:
	void updateStyle(TextCharFormat & chars, const CharFormat * format);

	void updateStyle(LineFormat & format, const Line * line);

	void bindChars();
	void bindHighlights();
	void bindMessages();
	void bindLines();
	void bindChanges();

private:
	Highlight *   m_occurrence = nullptr;
	Highlight *   m_selection  = nullptr;
	EditorStyle * m_style      = nullptr;
	CharFormat *  m_text       = nullptr;
	CharFormat *  m_number     = nullptr;
	CharFormat *  m_string     = nullptr;
	CharFormat *  m_type       = nullptr;
	CharFormat *  m_local      = nullptr;
	CharFormat *  m_global     = nullptr;
	CharFormat *  m_property   = nullptr;
	CharFormat *  m_method     = nullptr;
	CharFormat *  m_function   = nullptr;
	CharFormat *  m_keyword    = nullptr;
	CharFormat *  m_comment    = nullptr;
	CharFormat *  m_system     = nullptr;
	CharFormat *  m_error      = nullptr;
	CharFormat *  m_warning    = nullptr;
	ScrollBar *   m_scrollBar  = nullptr;
	Change *      m_changes    = nullptr;

	Line *  m_current    = nullptr;
	Line *  m_debug      = nullptr;
	Line *  m_breakpoint = nullptr;
	Line *  m_phantom    = nullptr;
	CLine * m_cline      = nullptr;
	Chars * m_chars      = nullptr;
};

}  // namespace icL::look

#endif  // icL_look_Editor
