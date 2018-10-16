#ifndef icL_editor_Fragment
#define icL_editor_Fragment

#include <QObject>



class QStaticText;

namespace icL::editor {

class Fragment : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::editor::Fragment* prev READ prev WRITE setPrev NOTIFY prevChanged)
	Q_PROPERTY(icL::editor::Fragment* next READ next WRITE setNext NOTIFY nextChanged)
	Q_PROPERTY(icL::Editor::Line*     line READ line WRITE setLine NOTIFY lineChanged)

	Q_PROPERTY(uint8_t length READ length WRITE setLength NOTIFY lengthChanged)
	Q_PROPERTY(int8_t  spaces READ spaces WRITE setSpaces NOTIFY spacesChanged)
	Q_PROPERTY(int8_t  glyphs READ glyphs WRITE setGlyphs NOTIFY glyphsChanged)
	// clang-format on

public:
	explicit Fragment(QObject * parent = nullptr);

	/**
	 * @brief displayText gets the text to display
	 * @return the text to display
	 */
	virtual const QString & displayText();

	/**
	 * @brief nextFragment gets the next fragment, from current or next line
	 * @return the next text fragment (is not always a sibling)
	 */
	Fragment * nextFragment();

	/**
	 * @brief prevFragment gets the prev fragment, from current or prev line
	 * @return the prev text fragment (is not always a sibling)
	 */
	Fragment * prevFragment();

	/**
	 * @brief isCached get the cache state (active or inactive)
	 * @return the cache active state
	 */
	bool isCached();

	/**
	 * @brief cacheNow caches the text geometry now
	 */
	void cacheNow();

	/**
	 * @brief freeCache free the cached geometry
	 */
	void freeCache();

	/**
	 * @brief getCache return a pointer to current cache
	 * @return nullptr is no cache is aviable
	 */
	const QStaticText * getCache();

	/**
	 * @brief drop deletes a fragment from text fragment
	 * @param begin the begin position
	 * @param end the end position
	 */
	void drop(int begin = 0, int end = -1);

	/**
	 * @brief insert inserts a text to needed position
	 * @param pos is the position to insert in
	 * @param text is the text to insert
	 */
	virtual void insert(int pos, const QString & text);

	/**
	 * @brief replace repalces a fragment of the be a new one
	 * @param p1 is the begin of interval
	 * @param p2 is the end of interval
	 * @param after is the new text
	 */
	virtual void replace(int p1, int p2, const QString & after);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // icL_editor_Fragment
