#ifndef icL_memory_WebElement
#define icL_memory_WebElement

#include <QString>
#include <QVariant>


/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '-> memory
 */
namespace icL::memory {

/**
 * @brief The WebElement class - DOM Manipulation class
 */
// struct WebElement {

// public:

// Operators

/**
 * @brief operator = - copy a web element
 * @param el - web element to copy
 * @return the copy
 */
//	WebElement& operator = (const WebElement &el);
/**
 * @brief operator [] - get the n'th element of elements
 * @param index
 * @return a new web element
 */
//	WebElement operator [] (int index);

// Attribute manipulation

/**
 * @brief getAttribute - get attribute value
 * @param name - the name of attribute
 * @param se - skip errors
 * @return attribute value, "" on error
 */
//	QString getAttribute (const QString &name, bool se = false) const;
/**
 * @brief getAttributeFromAll - get attribute from all elements of arrray
 * @param name - the name of attribute
 * @param se - skip errors
 * @return attribute values, [] on error
 */
//	QStringList getAttributeFromAll (const QString &name, bool se = false)
// const;
/**
 * @brief length - get the number of elements, contained by object
 * @param se - skip errors
 * @return the number of elements
 */
//	int length (bool se = false) const;

// Filter functions

/**
 * @brief filterByContent - filter elements by text content
 * @param name - the name of js variable to save the filtering result
 * @param filter - the text to find
 * @param se - skip errors
 * @return a new web element
 */
//	WebElement filterByContent (const QString &name, const QString &filter, bool
// se = false) const;
/**
 * @brief find - run querySelector to find element in the current element
 * @param selector - css selector
 * @param name - the name of js variable to save the filtering result
 * @param se - skip errors
 * @return a new web element
 */
//	WebElement find (const QString &selector, const QString &name, bool se =
// false) const;
/**
 * @brief findAll - run querySelectorAll to find elements in the current element
 * @param selector - css selector
 * @param name - the name of js variable to save the filtering result
 * @param se - skip errors
 * @return a new web element
 */
//	WebElement findAll (const QString &selector, const QString &name, bool se =
// true) const;

// Screen functions

/**
 * @brief x - get the coord of element center
 * @param se - skip errors
 * @return the x coord of element center
 */
//	int getX (bool se = false) const;
/**
 * @brief y - get the cood of element center
 * @param se - skip errors
 * @return the y coord of element center
 */
//	int getY (bool se = false) const;
/**
 * @brief visible 0 get if the element is visible on screen
 * @param se - skip errors
 * @return true if elements is visible, otherwise false
 */
//	bool getVisible (bool se = false) const;

// Input data functions

/**
 * @brief click - simulate click on element
 * @param se - skip errors
 */
//	void click (bool se = false) const;
/**
 * @brief focus - focus the input by click
 * @param se - skip errors
 */
//	void focus (bool se = false) const;
/**
 * @brief paste - append a string to element value
 * @param str - string to append
 * @param se - skip errors
 */
//	void paste (const QString &str, bool se = false) const;
/**
 * @brief sendKey - simulate key press
 * @param key - key to simulate
 * @param modifier - emulate shortcuts
 * @param text - text to print on screen
 */
//	void sendKey (Qt::Key key, Qt::KeyboardModifier modifier, const QString
//&text) const;
/**
 * @brief enter - simulate "enter press"
 */
//	void enter () const;
/**
 * @brief CtrlV - copy string to clipboard and paste it with Ctrl+V shortcut
 * @param str - the string to paste
 */
//	void CtrlV (const QString &str);

// Configuration functions

/**
 * @brief skipErrors - skip all future errors for this element
 */
//	void skipErrors ();
/**
 * @brief catchErrors - catch all future errors for this element
 */
//	void catchErrors ();
/**
 * @brief isSkipingErrors - check if the errors are skiped
 * @return if the errors are skiped
 */
//	bool isSkipingErrors ();

// Some external contructors for this class

//	friend WebElement queryOne (const QString&, const QString&, bool);
//	friend WebElement queryAll (const QString&, const QString&, bool);

// private:
//	QString selector = "";
//	// The name of variable in which we will stock data in javascript
//	QString variable	= "";
//	bool valid			= false;
//	bool single			= false;
//	bool skip_errors	= false;

// Don't touch these functions

//	bool is_single (bool se) const;
//	bool is_multi (bool se) const;
//	void report () const;
//};

struct WebElement
{
	QString selector = "";
	// The name of variable in which we will stock data in javascript
	QString variable = "";
	int     count    = 0;
};

/**
 * @brief queryOne - build a new WebElement with a single DOM element
 * @param selector - CSS selector
 * @param name - the name of variable to save the data in JS world
 * @param se - skip errors
 * @return the new web element
 */
// WebElement queryOne (const QString &selector, const QString &name = "", bool
// se = false);
/**
 * @brief queryAll - build a new WebElement with several DOM elements
 * @param selector - CSS selector
 * @param name - the name of variable to save the data in JS world
 * @param se - skip errors
 * @return the new web element
 */
// WebElement queryAll (const QString &selector, const QString &name = "", bool
// se = true);

}  // namespace icL::memory

Q_DECLARE_METATYPE(icL::memory::WebElement);

#endif  // icL_memory_WebElement
