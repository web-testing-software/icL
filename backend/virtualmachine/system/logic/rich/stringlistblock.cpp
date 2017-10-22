#include "stringlistblock.h"

#include <QRegularExpression>

vm::system::logic::rich::StringListBlock::StringListBlock (OperationType otype) :
	vm::system::logic::RichBlock (otype) {

}

QRegExp vm::system::logic::rich::StringListBlock::exp = QRegExp ("\\[(\\s*\".*\"(\\s*,\\s*\".*\")*)?\\s*\\]");
QRegularExpression vm::system::logic::rich::StringListBlock::strExp = QRegularExpression("\".*\"");

bool vm::system::logic::rich::StringListBlock::check (const QString &value) {
	return exp.exactMatch (value);
}


bool vm::system::logic::rich::StringListBlock::calcResult () {
	bool		result	= false;
	QStringList var1	= varNameToValue (this, var1name);
	QStringList var2	= varNameToValue (this, var2name);

	switch (operationType) {
	case OperationType::EQUAL :
		result = operatorEqual (var1, var2);
		break;

	case OperationType::NOT_EQUAL :
		result = !operatorEqual (var1, var2);
		break;

	default :
		resultValue = ResultValue::FAILED_CALCULATE;
		virtualMachine->setError (Error::COMMAND_EXECUTION_ERROR,
								  QObject::tr ("Wrong operator for operands <string>list:%1 and <string>list:%2.")
								  .arg (var1name)
								  .arg (var2name));
	}

	return result;
}

QStringList vm::system::logic::rich::StringListBlock::varNameToValue (LogicBlock *block, const QString &varname) {
	DataState::Type type = DataState::Type::STRING_LIST;
	QStringList		ret;

	if (check (varname)) {
		auto allStringsIt = strExp.globalMatch (varname);

		while (allStringsIt.hasNext ()) {
			auto	stringMatch = allStringsIt.next ();
			QString string		= stringMatch.captured ().mid (1, -2);

			ret.append (string);
		}
	}
	else if (!virtualMachine->checkType (varname, type)) {
		block->invalidate ();
		virtualMachine->setError (Error::DATA_CONVERSION_ERROR,
								  QObject::tr ("%1 is not a string list variable or constant.")
								  .arg (varname));
	}
	else {
		ret = virtualMachine->getVar (varname).toStringList ();
	}

	return ret;
}

bool vm::system::logic::rich::StringListBlock::operatorEqual (const QStringList &list1, const QStringList &list2) {

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
