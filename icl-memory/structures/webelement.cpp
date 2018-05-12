#include "webelement.h"

//#include <QClipboard>
//#include <QKeyEvent>
//#include <QMouseEvent>
//#include <QTimer>


// WebElement & WebElement::operator = (const WebElement &el) {
//	selector	= el.selector;
//	variable	= el.variable;
//	single		= el.single;
//	valid		= el.valid;
//	skip_errors = el.skip_errors;

//	return *this;
//}

// WebElement WebElement::operator [] (int index) {
//	WebElement	ret;

//	int			len		= length (skip_errors);
//	QString		suffix	= "[" + QString::number (index) + "]";

//	if (is_multi (skip_errors)) {

//		ret.selector	= selector + suffix;
//		ret.variable	= variable + suffix;
//		ret.single		= true;

//		if (index >= 0 && index < len) {
//			QString		code	= "!!" + ret.variable;
////			QVariant	v		= server->executeJS (code);

////			ret.valid = v.toBool ();
//		}
//		else {
//			ret.valid = false;
//		}
//	}
//	else {
//		ret.single	= false;
//		ret.valid	= false;
//	}

////	server->check_success (ret.valid || skip_errors,
////						   "WebElement WebElement::operator " + suffix);

//	return ret;
//}

//// Get string attribute of element
//// Other types aren't supprted now
// QString WebElement::getAttribute (const QString &name, bool se) const {
//	bool	success;
//	QString ret;

//	if (is_single (se)) {
//		QString		code	= variable + "." + name;
////		QVariant	v		= server->executeJS (code);
////		ret		= v.toString ();
////		success = v.isValid () && v.canConvert (QMetaType::QString);
//	}
//	else {
//		ret		= "";
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "QString WebElement::getAttribute ('"
////						   + name + "') const");
//	return ret;
//}

//// Get attribute of all elements like a list
// QStringList WebElement::getAttributeFromAll (const QString &name, bool se)
// const { 	bool		success; 	QStringList ret;

//	if (is_multi (se)) {
//		QString code = QString ("(function(){\n"
//								"var list = [];\n"
//								"for (var i = 0; i < %1.length; i++)\n"
//								"	list.push(%1[i].%2);\n"
//								"return list;"
//								"})()").arg (variable, name);
////		QVariant v = server->executeJS (code);

////		ret		= v.toStringList ();
////		success = v.isValid () && v.canConvert (QMetaType::QStringList);
//	}
//	else {
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "QStringList WebElement::getAttributeFromAll ('"
////						   + name + "') const");
//	return ret;
//}

//// Get the number of elements which contain this element
// int WebElement::length (bool se) const {
//	bool	success;
//	int		ret;

//	// If the element type is single, it can contain just a element
//	if (single) {
//		ret		= valid ? 1 : 0;
//		success = true;
//	}
//	// calc the length using javascript
//	else {
//		QString		code = QString ("%1.length").arg (variable);
////		qDebug ("%s", qUtf8Printable (code));
////		QVariant	v = server->executeJS (code);
////		ret		= v.toInt ();
////		success = v.isValid () &&  v.canConvert (QMetaType::Int);
//	}

////	server->check_success (success || se || skip_errors,
////						   "int WebElement::length () const");
//	return ret;
//}

//// Filter elements by text content
// WebElement WebElement::filterByContent (const QString &name, const QString
// &filter, bool se) const { 	bool		success; 	WebElement	ret;

//	ret.variable	= name;
//	ret.selector	= selector + " filtered by " + filter;
//	QString code;

//	if (!valid) {
//		ret.valid	= false;
//		success		= false;
//	}
//	else {

//		if (single) {
//			ret.single = true;
//			// If the element is single, the result can be the same or null
//			code = QString ("(function(){\n"
//							"if(%1.innerText.contains(%2)) {\n"
//							"	%3 = %1;\n"
//							"	return true;\n"
//							"} else {\n"
//							"	%3 = null;\n"
//							"	return false;\n"
//							"}\n"
//							"})()").arg (variable, filter, name);
//		}
//		else {
//			ret.single = false;
//			// If the elements is not single, the result is a array
//			code = QString ("(function(){\n"
//							"%3 = [];\n"
//							"for (var i = 0; i < %i.length; i++)\n"
//							"	if (%i[i].innerText.contains(%2))"
//							"		%3.push(%i);\n"
//							"return %3.length > 0;"
//							"})()").arg (variable, filter, name);
//		}

////		QVariant v = server->executeJS (code);
////		ret.valid = success = v.toBool ();
//	}

////	server->check_success (success || se || skip_errors,
////						   "WebElement WebElement::filterByContent ('"
////						   + name + "', '" + filter + "') const");
//	return ret;
//}

//// Find elements in this element
// WebElement WebElement::find (const QString &selector, const QString &name,
// bool se) const { 	WebElement el;

//	el.selector = this->selector + " " + selector;
//	el.single	= true;
//	el.variable = name;
//	if (is_single (se)) {
//		QString code = QString ("(%3 = %1.querySelector('%2')) == null")
//					   .arg (variable, selector, name);

////		QVariant v = server->executeJS (code);
////		el.valid = v.toBool ();
//	}
//	else {
//		el.valid = false;
//	}

////	server->check_success (el.valid || se || skip_errors,
////						   "WebElement WebElement::find ('"
////						   + selector + "', '" + name + "') const");
//	return el;
//}

// WebElement WebElement::findAll (const QString &selector, const QString &name,
// bool se) const { 	WebElement el;

//	el.single	= false;
//	el.variable = name;
//	if (is_single (se)) {
//		QString code = QString ("(%3 = %1.querySelectorAll('%2')); %3.length >
//0") 					   .arg (variable, selector, name);

////		QVariant v = server->executeJS (code);
////		el.valid = v.toBool ();
//	}
//	else {
//		el.valid = false;
//	}

////	server->check_success (el.valid || se || skip_errors,
////						   "WebElement WebElement::findAll ('"
////						   + selector + "', '" + name + "') const");
//	return el;
//}

//// Get the x pos on screen for click
//// It will return the horizontal middle
// int WebElement::getX (bool se) const {
//	bool	success;
//	int		ret;

//	if (is_single (se)) {
//		QString		code = QString ("%1.getBoundingClientRect().left +
//%1.offsetWidth / 2").arg (variable);
////		qDebug ("%s", qUtf8Printable (code));
////		QVariant	v = server->executeJS (code);
////		ret = v.toInt ();
//	}
//	else {
//		ret		= 0;
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "void WebElement::x () const");
//	return ret;
//}

//// Get the y pos on screen for click
//// It will return the vertical middle
// int WebElement::getY (bool se) const {
//	bool	success;
//	int		ret;

//	if (is_single (se)) {
//		QString		code = QString ("%1.getBoundingClientRect().top +
//%1.offsetHeight / 2").arg (variable);
////		qDebug ("%s", qUtf8Printable (code));
////		QVariant	v = server->executeJS (code);
////		ret = v.toInt ();
//	}
//	else {
//		ret		= 0;
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "int WebElement::y () const");
//	return ret;
//}

//// Test if element is visible on screen, to click on it
// bool WebElement::getVisible (bool se) const {
//	bool success, ret;

//	if (is_single (se)) {
//		QString code = QString ("doc.elementsFromPoint("
//								"%1.getBoundingClientRect().left + 1, "
//								"%1.getBoundingClientRect().top + 1).indexOf(%1) >
//-1") 					   .arg (variable);
////		QVariant v = server->executeJS (code);

////		ret		= v.toBool ();
//		success = true;
//	}
//	else {
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "bool WebElement::visible () const");
//	return ret;
//}

//// Emulate click on low level in C++
//// The javascript .click() dont get the waited result
// void WebElement::click (bool se) const {
//	bool success;

//	if (is_single (se)) {
//		const WebElement	element = *this;

//		auto				finish
//			= [ = ] () {
//				  // Get the x pos of object
//				  int	_x = element.getX ();
//				  // Get the y pos of object
//				  int	_y = element.getY ();

////				  webBrowser->simulate_click (_x, _y);
//			  };

//		const QString	&variable	=  this->variable;
//		bool			is_visible	= getVisible ();
//		if (is_visible) {
//			finish ();
//			success = true;
//		}
//		else {
//			QString code = QString ("scrollTo(%1)").arg (variable);

////			server->executeJS (code);
//			is_visible = element.getVisible ();
//			if (!is_visible) {
//				finish ();
//				success = true;
//			}
//			else {
////				server->addToErrorsStack (":: :: Element not visible ::
///::");
//				success = false;
//			}
//		}
//	}
//	else {
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "void WebElement::click () const");
//}

// void WebElement::focus (bool se) const {
//	click (se);
//}

//// Append text to input value
// void WebElement::paste (const QString &str, bool se) const {
//	bool success;

//	if (is_single (se)) {
//		QString code = QString ("%1.value += '%2'").arg (variable, str);
////		server->executeJS (code);
//		success = true;
//	}
//	else {
//		success = false;
//	}

////	server->check_success (success || se || skip_errors,
////						   "void WebElement::paste ('" + str + "') const");
//}

//// Emulate key press on low level
//// Click is for focus needed element
// void WebElement::sendKey (Qt::Key key, Qt::KeyboardModifier modifier, const
// QString &text) const {

//	click (true);
////	webBrowser->simulate_key (key, modifier, text);
//}

// void WebElement::enter () const {
//	sendKey (Qt::Key_Return, Qt::NoModifier, QStringLiteral("\n"));
//}

// void WebElement::CtrlV (const QString &str) {
////	QClipboard *clipboard = QApplication::clipboard ();

////	clipboard->setText (str);
//	sendKey (Qt::Key_V, Qt::ControlModifier, QStringLiteral("v"));
//}

// void WebElement::skipErrors () {
//	skip_errors = true;
//}

// void WebElement::catchErrors () {
//	skip_errors = false;
//}

// bool WebElement::isSkipingErrors () {
//	return skip_errors;
//}

// bool WebElement::is_single (bool se) const {
//	if (valid && single) {
//		return true;
//	}
//	else {
//		if (!se) {
//			report ();
//		}
//		return false;
//	}
//}

// bool WebElement::is_multi (bool se) const {
//	if (valid && !single) {
//		return true;
//	}
//	else {
//		if (!se) {
//			report ();
//		}
//		return false;
//	}
//}

// void WebElement::report () const {
////	server->addToErrorsStack (( single ? "Web element " : "Web elements " ) +
///selector /							  + " | valid " + ( valid ? "yes" : "no"
///) + " | variable " + variable);
//}

//// Select element by css selector
// WebElement queryOne (const QString &selector, const QString &name, bool se) {
//	WebElement el;

//	el.single		= true;
//	el.skip_errors	= se;
//	if (name.isEmpty ()) {
//		el.variable = QString ("doc.querySelector('%1')").arg (selector);

//		QString		code	= el.variable + " != null";
////		QVariant	v		= server->executeJS (code);

////		el.valid = v.toBool ();
//	}
//	else {
//		QString		code	= QString ("(%1 = doc.querySelector('%2')) != null").arg
//(name).arg (selector);
////		QVariant	v		= server->executeJS (code);

////		el.variable = name;
////		el.valid	= v.toBool ();
//	}
////	server->check_success (el.valid || se,
////						   "WebElement css ('" + selector + "', '" + name +
///"')");
//	return el;
//}

//// Select all matched elements by css selector
// WebElement queryAll (const QString &selector, const QString &name, bool se) {
//	WebElement el;

//	el.single		= true;
//	el.skip_errors	= false;
//	if (name.isEmpty ()) {
//		el.variable = QString ("doc.querySelectorAll('%1')").arg (selector);
//		el.valid	= true;
//	}
//	else {
//		QString		code	= QString ("(%1 = doc.querySelectorAll('%2')) !=
//null").arg (name).arg (selector);
////		QVariant	v		= server->executeJS (code);

////		el.variable = name;
////		el.valid	= v.toBool ();
//	}
////	server->check_success (el.valid || se,
////						   "WebElement all ('" + selector + "', '" + name +
///"')");
//	return el;
//}
