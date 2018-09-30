#ifndef icL_look_start_Editor
#define icL_look_start_Editor

#include "charformat.h"
#include "highlight.h"
#include "line.h"

#include <QObject>

namespace icL::look::editor {

class Editor : public QObject
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
	explicit Editor(QObject * parent = nullptr);

	~Editor();

	CharFormat * text() const;

	CharFormat * selection() const;

	CharFormat * number() const;

	CharFormat * string() const;

	CharFormat * type() const;

	CharFormat * local() const;

	CharFormat * global() const;

	CharFormat * property() const;

	CharFormat * method() const;

	CharFormat * function() const;

	CharFormat * keyword() const;

	CharFormat * comment() const;

	CharFormat * system() const;

	CharFormat * error() const;

	CharFormat * warning() const;

	Highlight * occurrence() const;

	Line * current() const;

	Line * debug() const;

	Line * breakpoint() const;

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
	void setText(CharFormat * text);
	void setSelection(CharFormat * selection);
	void setNumber(CharFormat * number);
	void setString(CharFormat * string);
	void setType(CharFormat * type);
	void setLocal(CharFormat * local);
	void setGlobal(CharFormat * global);
	void setProperty(CharFormat * property);
	void setMethod(CharFormat * method);
	void setFunction(CharFormat * function);
	void setKeyword(CharFormat * keyword);
	void setComment(CharFormat * comment);
	void setSystem(CharFormat * system);
	void setError(CharFormat * error);
	void setWarning(CharFormat * warning);
	void setOccurrence(Highlight * occurrence);
	void setCurrent(Line * current);
	void setDebug(Line * debug);
	void setBreakpoint(Line * breakpoint);
};

}  // namespace icL::look::editor

#endif  // icL_look_start_Editor
