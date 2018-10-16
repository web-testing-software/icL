#ifndef icL_look_Chars
#define icL_look_Chars

#include <QFont>
#include <QObject>
#include <QPen>

namespace icL::look {

/**
 * @brief The HighlightChars struct describes a simple highlight format
 */
struct HighlightChars
{
	/// @brief background is the background color
	QBrush background;

	/// @brief border is the border color
	QPen border;
};

/**
 * @brief The TextCharFormat struct defines format for chars in editor
 */
struct TextCharFormat
{
	/// @brief the font of text (italic, bold)
	QFont font;

	/// @brief defines the color for the text
	QPen text;

	/// @brief defines the color of background
	QBrush background;

	/// @brief defines the color and style of underline
	QPen underline;
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
	static TextCharFormat comment;

	/// @brief function is the style for functions in code
	static TextCharFormat function;

	/// @brief global is the style for global variables in code
	static TextCharFormat global;

	/// @brief keyword is the style for keywords in code
	static TextCharFormat keyword;

	/// @brief local is the style for local variables in code
	static TextCharFormat local;

	/// @brief method is the style for methods in code
	static TextCharFormat method;

	/// @brief number is the style for numbers in code
	static TextCharFormat number;

	/// @brief property is the style for properties in code
	static TextCharFormat property;

	/// @brief string is the style for string in code
	static TextCharFormat string;

	/// @brief system is the style for system types in code
	static TextCharFormat system;

	/// @brief type is the style for types names in code
	static TextCharFormat type;

	/// @brief occurrence is the style for occurrence highlight
	static HighlightChars occurence;

	/// @brief error is the color of errors underline
	static TextCharFormat error;

	/// @brief warning is the color of warning underline
	static TextCharFormat warning;

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

}  // namespace icL::look

#endif  // icL_look_Chars
