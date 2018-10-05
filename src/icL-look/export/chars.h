#ifndef icL_look_Chars
#define icL_look_Chars

#include <QObject>
#include <QTextCharFormat>

namespace icL::look {

struct HighlightChars
{
	QColor background;
	QColor border;
};

/**
 * @brief The Chars class exports editor hightlight rules to C++
 */
class Chars : public QObject
{
	Q_OBJECT
public:
	explicit Chars(QObject * parent = nullptr);

	/// @brief comment is the style for comments in code
	static QTextCharFormat comment;

	/// @brief function is the style for functions in code
	static QTextCharFormat function;

	/// @brief global is the style for global variables in code
	static QTextCharFormat global;

	/// @brief keyword is the style for keywords in code
	static QTextCharFormat keyword;

	/// @brief local is the style for local variables in code
	static QTextCharFormat local;

	/// @brief method is the style for methods in code
	static QTextCharFormat method;

	/// @brief number is the style for numbers in code
	static QTextCharFormat number;

	/// @brief property is the style for properties in code
	static QTextCharFormat property;

	/// @brief string is the style for string in code
	static QTextCharFormat string;

	/// @brief system is the style for system types in code
	static QTextCharFormat system;

	/// @brief type is the style for types names in code
	static QTextCharFormat type;

	/// @brief occurrence is the style for occurrence highlight
	static HighlightChars occurence;

	/// @brief error is the color of errors underline
	static QColor error;

	/// @brief warning is the color of warning underline
	static QColor warning;

	/// @brief send signal to QML to rehighlight editor
	static void update();

signals:
	/// request rehiglight of code
	void highlight();

public slots:

private:
	/**
	 * @brief instance is needed to send signals to QML to update current file
	 * systax highlighting
	 * @return a static intance of chars
	 */
	static Chars * instance;
};

}  // namespace icL::editor::look

#endif  // icL_look_Chars
