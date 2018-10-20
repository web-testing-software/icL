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
 * @brief The LineFormat struct defines the format for line numbers and bg color
 */
struct LineFormat {
	/// @brief the format for line number
	TextCharFormat lineNumber;

	/// @brief the background of line
	QBrush background;
};

/**
 * @brief The CLineFormat struct defines the format for all lines
 */
struct CLineFormat : public LineFormat {
	/// The color for changed line number
	QPen changed;

	/// The color for saved line number
	QPen saved;
};

/**
 * @brief The Chars class exports editor hightlight rules to C++
 */
class Chars : public QObject
{
	Q_OBJECT
public:
	explicit Chars(QObject * parent = nullptr);

	/// @brief text is the style for all text
	TextCharFormat text;

	/// @brief comment is the style for comments in code
	TextCharFormat comment;

	/// @brief function is the style for functions in code
	TextCharFormat function;

	/// @brief global is the style for global variables in code
	TextCharFormat global;

	/// @brief keyword is the style for keywords in code
	TextCharFormat keyword;

	/// @brief local is the style for local variables in code
	TextCharFormat local;

	/// @brief method is the style for methods in code
	TextCharFormat method;

	/// @brief number is the style for numbers in code
	TextCharFormat number;

	/// @brief property is the style for properties in code
	TextCharFormat property;

	/// @brief string is the style for string in code
	TextCharFormat string;

	/// @brief system is the style for system types in code
	TextCharFormat system;

	/// @brief type is the style for types names in code
	TextCharFormat type;

	/// @brief occurrence is the style for occurrence highlight
	HighlightChars occurence;

	/// @brief selection is the style for selection highlight
	HighlightChars selection;

	/// @brief error is the color of errors underline
	TextCharFormat error;

	/// @brief warning is the color of warning underline
	TextCharFormat warning;

	/// @brief cline is the format for any line number
	CLineFormat cline;

	/// @brief current is the format for current line
	LineFormat current;

	/// @brief debug is the format for current debugging line
	LineFormat debug;

	/// @brief breakpoint is the format for breakpointed line
	LineFormat breakpoint;

	/// @brief send signal to QML to rehighlight editor
	void update();

signals:
	/// request rehiglight of code
	void highlight();

public slots:

private:
	/**
	 * @brief instance is needed to send signals to QML to update current file
	 * systax highlighting
	 * @return a intance of chars
	 */
	static Chars * instance;
};

}  // namespace icL::look

#endif  // icL_look_Chars
