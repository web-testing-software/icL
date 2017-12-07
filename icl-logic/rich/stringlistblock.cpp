#include "stringlistblock.h"

#include "icl-memory/state/datastate.h"

#include <QRegularExpression>

namespace vm::main::logic::rich {

StringListBlock::StringListBlock (OperationType otype)
	: StringBlock (otype) {

}

QRegExp				StringListBlock::exp	= QRegExp ("\\[(\\s*\".*\"(\\s*,\\s*\".*\")*)?\\s*\\]");
QRegularExpression	StringListBlock::strExp = QRegularExpression ("\".*\"");

bool StringListBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool StringListBlock::calcResult () {
	bool		result	= false;
	QStringList var1	= varNameToStringList (var1name);
	QStringList var2	= varNameToStringList (var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = operatorEqual (var1, var2);
		break;

	case OperationType::NOT_EQUAL :
		result = !operatorEqual (var1, var2);
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		dataContainer->setError (Error::COMMAND_EXECUTION_ERROR,
								 QObject::tr ("Wrong operator for operands <string>list:%1 and <string>list:%2.")
								 .arg (var1name)
								 .arg (var2name));
	}

	return result;
}

QStringList StringListBlock::varNameToStringList (const QString &varname) {
	memory::DataState::Type type = memory::DataState::Type::STRING_LIST;
	QStringList				ret;

	if (check (varname)) {
		auto allStringsIt = strExp.globalMatch (varname);

		while (allStringsIt.hasNext ()) {
			auto	stringMatch = allStringsIt.next ();
			QString string		= stringMatch.captured ().mid (1, -2);

			ret.append (string);
		}
	}
	else if (!dataContainer->checkType (varname, type)) {
		invalidate ();
		dataContainer->setError (Error::DATA_CONVERSION_ERROR,
								 QObject::tr ("%1 is not a string list variable or constant.")
								 .arg (varname));
	}
	else {
		ret = dataContainer->getVar (varname).toStringList ();
	}

	return ret;
}

bool StringListBlock::operatorEqual (const QStringList &list1, const QStringList &list2) {

	for (const QString &str : list1) {
		if (!list2.contains (str)) {
			return false;
		}
	}

	for (const QString &str : list2) {
		if (!list1.contains (str)) {
			return false;
		}
	}

	return true;
}

}
