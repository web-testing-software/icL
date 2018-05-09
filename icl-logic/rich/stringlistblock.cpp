#include "stringlistblock.h"

#include "icl-memory/state/datastate.h"

#include <QRegularExpression>

namespace vm::logic::rich {

ListBlock::ListBlock (OperationType otype)
	: StringBlock (otype) {

}

/**
 * @brief StringListBlock::exp - a reg exp which describe the string list syntax
 */
// QRegExp				StringListBlock::exp	= QRegExp ("\\[(\\s*\".*[^\\\\]\"(\\s*,\\s*\".*[^\\\\]\")*)?\\s*\\]");
/**
 * @brief StringListBlock::strExp - s reg exp which describe a string in string list syntax
 */
// QRegularExpression	StringListBlock::strExp = QRegularExpression ("\".*[^\\\\]\"");

/**
 * @brief StringListBlock::check - if the string is a <string>list const
 * @param value - value to check
 * @return valid - true, invalid - false
 */
// bool StringListBlock::check (const QString &value) {
//	return exp.exactMatch (value);
// }

/**
 * @brief StringListBlock::calcResult - compare values
 * @return the result of comparation
 */
bool ListBlock::calcResult () {
	bool		result	= false;
	QStringList var1	= value1.toStringList ();


	if (value2.type () == QVariant::StringList) {
		QStringList var2 = value2.toStringList ();

		switch (operationType) {
		case OperationType::EQUAL :
			result = operatorEqual (var1, var2);
			break;

		case OperationType::NOT_EQUAL :
			result = !operatorEqual (var1, var2);
			break;

		default :
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator ("[List-List]");
		}
	}
	else if (value2.type () == QVariant::String) {
		QString var2 = value2.toString ();

		switch (operationType) {
		case OperationType::CONTAINS :
			result = var1.contains (var2);
			break;

		case OperationType::CONTAINS_FRAGMENT :
			result = containsFragment (var1, var2);
			break;

		default :
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator ("[List-String]");
		}
	}
	else {
		sendSignalWrongPair ();
	}

	return result;
}

/**
 * @brief StringListBlock::operatorEqual - test if both lists contains some items
 * @param list1 - first string list
 * @param list2 - second string list
 * @return both lists contains the same items
 */
bool ListBlock::operatorEqual (const QStringList &list1, const QStringList &list2) {

	for (const QString &str : list1) {
		if (!list2.contains (str) ) {
			return false;
		}
	}

	for (const QString &str : list2) {
		if (!list1.contains (str) ) {
			return false;
		}
	}

	return true;
}

bool ListBlock::containsFragment (const QStringList &strList, const QString &str) {
	bool ret = false;

	for (const QString &strFromList : strList) {
		if (strFromList.indexOf (str) >= 0) {
			ret = true;
		}
	}

	return ret;
}

}
