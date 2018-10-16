#ifndef icL_editor_Cursor
#define icL_editor_Cursor

#include <QObject>

namespace icL::editor {

class Cursor : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* fragment READ fragment WRITE setFragment NOTIFY fragmentChanged)

	Q_PROPERTY(int8_t   position READ position  WRITE setPosition  NOTIFY positionChanged)
	Q_PROPERTY(uint8_t preffered READ preffered WRITE setPreffered NOTIFY prefferedChanged)
	// clang-format on

public:
	explicit Cursor(QObject *parent = nullptr);

signals:

public slots:
};

} // namespace

#endif // icL_editor_Cursor
