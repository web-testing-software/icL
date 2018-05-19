#include "List.h"

#include "icl-memory/state/datastate.h"

namespace icL::logic::rich {

ListBlock::ListBlock(memory::InterLevel * il, OperationType otype)
	: Rich(il, otype) {
	casted = true;
}

ListBlock::ListBlock(memory::InterLevel * il, Rich * block)
	: Rich(il, block) {}


/**
 * @brief StringListBlock::calcResult - compare values
 * @return the result of comparation
 */
bool ListBlock::calcResult() {
	bool        result = false;
	QStringList var1   = value1.toStringList();


	if (value2.type() == QVariant::StringList) {
		QStringList var2 = value2.toStringList();

		switch (operationType) {
		case OperationType::Equal:
			result = operatorEqual(var1, var2);
			break;

		case OperationType::NotEqual:
			result = !operatorEqual(var1, var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[List-List]");
		}
	}
	else if (value2.type() == QVariant::String) {
		QString var2 = value2.toString();

		switch (operationType) {
		case OperationType::Contains:
			result = var1.contains(var2);
			break;

		case OperationType::ContainsFragment:
			result = containsFragment(var1, var2);
			break;

		default:
			resultValue = ResultValue::FAILED_CALCULATE;
			sendSignalWrongOperator("[List-String]");
		}
	}
	else {
		sendSignalWrongPair();
	}

	return result;
}

/**
 * @brief StringListBlock::operatorEqual - test if both lists contains some
 * items
 * @param list1 - first string List
 * @param list2 - second string List
 * @return both lists contains the same items
 */
bool ListBlock::operatorEqual(
  const QStringList & list1, const QStringList & list2) {

	for (const QString & str : list1) {
		if (!list2.contains(str)) {
			return false;
		}
	}

	for (const QString & str : list2) {
		if (!list1.contains(str)) {
			return false;
		}
	}

	return true;
}

bool ListBlock::containsFragment(
  const QStringList & strList, const QString & str) {
	bool ret = false;

	for (const QString & strFromList : strList) {
		if (strFromList.indexOf(str) >= 0) {
			ret = true;
		}
	}

	return ret;
}

}  // namespace icL::logic::rich
