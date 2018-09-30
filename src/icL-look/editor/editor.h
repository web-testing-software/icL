#ifndef icL_look_start_Editor
#define icL_look_start_Editor

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

public:
	explicit Editor(QObject *parent = nullptr);

signals:

public slots:
};

} // namespace

#endif // icL_look_start_Editor
