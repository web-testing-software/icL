#ifndef icL_editor_Line
#define icL_editor_Line

#include <QObject>

namespace icL::editor {

class Line : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::Editor::Fragment* first READ first WRITE setFirst NOTIFY firstChanged)

	Q_PROPERTY(uint8_t     length READ length     WRITE setLength     NOTIFY lengthChanged)
	Q_PROPERTY(int32_t   beginPos READ beginPos   WRITE setBeginPos   NOTIFY beginPosChanged)
	Q_PROPERTY(int16_t lineNumber READ lineNumber WRITE setLineNumber NOTIFY lineNumberChanged)
	// clang-format off

public:
	explicit Line(QObject *parent = nullptr);

	/**
	 * @brief getText gets the text of line by concatenation all fragments
	 * @return the text of line
	 */
	const QString & getText();

signals:

public slots:
};

} // namespace

#endif // icL_editor_Line
