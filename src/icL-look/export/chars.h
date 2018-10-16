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
 * @brief The CharFormat struct defines format for chars in editor
 */
struct CharFormat
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
	static CharFormat comment;

	/// @brief function is the style for functions in code
	static CharFormat function;

	/// @brief global is the style for global variables in code
	static CharFormat global;

	/// @brief keyword is the style for keywords in code
	static CharFormat keyword;

	/// @brief local is the style for local variables in code
	static CharFormat local;

	/// @brief method is the style for methods in code
	static CharFormat method;

	/// @brief number is the style for numbers in code
	static CharFormat number;

	/// @brief property is the style for properties in code
	static CharFormat property;

	/// @brief string is the style for string in code
	static CharFormat string;

	/// @brief system is the style for system types in code
	static CharFormat system;

	/// @brief type is the style for types names in code
	static CharFormat type;

	/// @brief occurrence is the style for occurrence highlight
	static HighlightChars occurence;

	/// @brief error is the color of errors underline
	static CharFormat error;

	/// @brief warning is the color of warning underline
	static CharFormat warning;

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
