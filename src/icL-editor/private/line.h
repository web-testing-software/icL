#ifndef icL_editor_Line
#define icL_editor_Line

#include <QObject>

namespace icL::editor {

class Fragment;

class Line : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* first READ first WRITE setFirst NOTIFY firstChanged)

	Q_PROPERTY(uint8_t     length READ length     NOTIFY lengthChanged)
	Q_PROPERTY(int32_t   beginPos READ beginPos   WRITE setBeginPos   NOTIFY beginPosChanged)
	Q_PROPERTY(int16_t lineNumber READ lineNumber WRITE setLineNumber NOTIFY lineNumberChanged)
	Q_PROPERTY(bool       visible READ visible    WRITE setVisible    NOTIFY visibleChanged)
	// clang-format on

public:
	explicit Line(QObject * parent = nullptr);

	/**
	 * @brief first gets the first fragment in the line
	 * @return the first fragment in the line
	 */
	Fragment * first() const;

	/**
	 * @brief length gets the length of the line
	 * @return the lenght of the line
	 */
	uint8_t length() const;

	/**
	 * @brief beginPos is the begin position of the line
	 * @return the begin position of text fragment
	 */
	int32_t beginPos() const;

	/**
	 * @brief lineNumber return the line number
	 * @return the number of line
	 */
	int16_t lineNumber() const;

	/**
	 * @brief visible gets the visible state of line
	 * @return true if line is visible, otherwise false
	 */
	bool visible() const;

	/**
	 * @brief getText gets the text of line by concatenation all fragments
	 * @return the text of line
	 */
	const QString & getText();

signals:
	void firstChanged(Fragment * first);
	void lengthChanged(uint8_t length);
	void beginPosChanged(int32_t beginPos);
	void lineNumberChanged(int16_t lineNumber);
	void visibleChanged(bool visible);

public slots:
	/**
	 * @brief setFirst sets the first fragment of line
	 * @param first is the new first fragment
	 */
	void setFirst(Fragment * first);

	/**
	 * @brief setBeginPos changes the begin pos of line
	 * @param beginPos is the new begin position
	 */
	void setBeginPos(int32_t beginPos);

	/**
	 * @brief setLineNumber changes the number of line
	 * @param lineNumber is the new line number
	 */
	void setLineNumber(int16_t lineNumber);

	/**
	 * @brief setVisible hides/shows the line
	 * @param visible is true on show and false on hide
	 */
	void setVisible(bool visible);

private:
	Fragment * m_first = nullptr;

	uint8_t m_length;
	int32_t m_beginPos;
	int16_t m_lineNumber;
	bool    m_visible;
};

}  // namespace icL::editor

#endif  // icL_editor_Line
