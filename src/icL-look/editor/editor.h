#ifndef icL_look_start_Editor
#define icL_look_start_Editor

#include "../base/base.h"


namespace icL::look::editor {

class CharFormat;
class Highlight;
class Line;

/**
 * @brief The Editor class defines a color scheme for an editor
 */
class Editor : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(CharFormat*      text READ text)
	Q_PROPERTY(CharFormat* selection READ selection)
	Q_PROPERTY(CharFormat*    number READ number)
	Q_PROPERTY(CharFormat*    string READ string)
	Q_PROPERTY(CharFormat*      type READ type)
	Q_PROPERTY(CharFormat*     local READ local)
	Q_PROPERTY(CharFormat*    global READ global)
	Q_PROPERTY(CharFormat*  property READ property)
	Q_PROPERTY(CharFormat*    method READ method)
	Q_PROPERTY(CharFormat*  function READ function)
	Q_PROPERTY(CharFormat*   keyword READ keyword)
	Q_PROPERTY(CharFormat*   comment READ comment)
	Q_PROPERTY(CharFormat*    system READ system)
	Q_PROPERTY(CharFormat*     error READ error)
	Q_PROPERTY(CharFormat*   warning READ warning)
	Q_PROPERTY(Highlight* occurrence READ occurrence)
	Q_PROPERTY(Line*         current READ current)
	Q_PROPERTY(Line*           debug READ debug)
	Q_PROPERTY(Line*      breakpoint READ breakpoint)
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

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;
};

}  // namespace icL::look::editor

#endif  // icL_look_start_Editor
