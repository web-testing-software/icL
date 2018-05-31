#include "list.h"

#include "boolean.h"
#include "double.h"
#include "int.h"
#include "string.h"

namespace icL::context::object {



List::List(
  memory::InterLevel * il, memory::DataState * container,
  const QString & varName)
	: Object(il, container, varName) {}

List::List(memory::InterLevel * il, const QVariant & rvalue, bool readonly)
	: Object(il, rvalue, readonly) {}

List::List(
  memory::InterLevel * il, const QString & getter, const QString & setter)
	: Object(il, getter, setter) {}

List::List(memory::InterLevel * il, const Object * const object)
	: Object(il, object) {}



const QHash<QString, void (List::*)()> List::properties =
  List::initProperties();

const QHash<QString, void (List::*)(memory::ArgList &)> List::methods =
  List::initMethods();

const QHash<QString, void (List::*)()> List::initProperties() {
	return {{"Length", &List::runLength}};
}

const QHash<QString, void (List::*)(memory::ArgList &)> List::initMethods() {
	return {{{"Prepend", &List::runPrepend},
			 {"Append", &List::runAppend},
			 {"Insert", &List::runInsert},
			 {"Merge", &List::runMerge},
			 {"PopFront", &List::runPopFront},
			 {"PopBack", &List::runPopBack},
			 {"Remove", &List::runRemove},
			 {"RemoveOnce", &List::runRemoveOnce},
			 {"RemoveAll", &List::runRemoveAll},
			 {"Get", &List::runGet},
			 {"IndexOf", &List::runIndexOf},
			 {"LastIndexOf", &List::runLastIndexOf},
			 {"Join", &List::runJoin},
			 {"SumUp", &List::runSumUp},
			 {"Max", &List::runMax},
			 {"Min", &List::runMin},
			 {"LogicAnd", &List::runLogicAnd},
			 {"LogicOr", &List::runLogicOr}}};
}



int List::length() {
	return getValue().toStringList().length();
}


void List::runLength() {
	newValue   = length();
	newContext = new Int(il, newValue, true);
}


void List::prepend(const QString & value) {
	QStringList List = getValue().toStringList();

	List.prepend(value);
	setValue(List);
}

void List::append(const QString & value) {
	QStringList List = getValue().toStringList();

	List.append(value);
	setValue(List);
}

void List::insert(int index, const QString & value) {
	QStringList List = getValue().toStringList();

	List.insert(index, value);
	setValue(List);
}

void List::merge(const QStringList & List) {
	QStringList list1 = getValue().toStringList();

	list1.append(List);
	setValue(list1);
}

void List::popFront() {
	QStringList List = getValue().toStringList();

	if (List.isEmpty()) {
		il->vm->exception({-3, "Can not remove first item of empty List"});
	}
	else {
		List.removeFirst();
		setValue(List);
	}
}

void List::popBack() {
	QStringList List = getValue().toStringList();

	if (List.isEmpty()) {
		il->vm->exception({-3, "Can not remove first item of empty List"});
	}
	else {
		List.removeLast();
		setValue(List);
	}
}

void List::remove(int index) {
	QStringList List = getValue().toStringList();

	if (index < 0 || index >= List.length()) {
		il->vm->exception({-8, "Index out of bounds"});
	}
	else {
		List.removeAt(index);
		setValue(List);
	}
}

void List::removeOnce(const QString & value) {
	QStringList List = getValue().toStringList();

	List.removeOne(value);
	setValue(List);
}

void List::removeAll(const QString & value) {
	QStringList List = getValue().toStringList();

	List.removeAll(value);
	setValue(List);
}

QString List::get(int index) {
	QStringList List = getValue().toStringList();

	if (index < 0 || index >= List.length()) {
		il->vm->exception({-8, "Index out of bounds"});
	}
	else {
		return List.at(index);
	}

	return QString{};
}

int List::indexOf(const QString & value) {
	QStringList List = getValue().toStringList();

	return List.indexOf(value);
}

int List::lastIndexOf(const QString value) {
	QStringList List = getValue().toStringList();

	return List.lastIndexOf(value);
}

QString List::join(const QString & delimiter) {
	QStringList List = getValue().toStringList();

	return List.join(delimiter);
}

double List::sumUp() {
	QStringList List = getValue().toStringList();
	double      sum  = 0;

	for (auto & str : List) {
		bool ok;
		sum += str.toDouble(&ok);

		if (!ok) {
			il->vm->exception(
			  {-2, QString("Failed to parse `%1` to double").arg(str)});
			break;
		}
	}

	return sum;
}

double List::max() {
	QStringList List = getValue().toStringList();

	if (List.isEmpty()) {
		il->vm->exception({-3, "Cannot find max value in empty List"});
		return 0.0;
	}

	double max = List.at(0).toDouble();

	for (auto & str : List) {
		bool   ok;
		double number = str.toDouble(&ok);

		if (!ok) {
			il->vm->exception(
			  {-2, QString("Failed to parse `%1` to double").arg(str)});
			break;
		}
		else if (number > max) {
			max = number;
		}
	}

	return max;
}

double List::min() {
	QStringList List = getValue().toStringList();

	if (List.isEmpty()) {
		il->vm->exception({-3, "Cannot find min value in empty List"});
		return 0.0;
	}

	double min = List.at(0).toDouble();

	for (auto & str : List) {
		bool   ok;
		double number = str.toDouble(&ok);

		if (!ok) {
			il->vm->exception(
			  {-2, QString("Failed to parse `%1` to double").arg(str)});
			break;
		}
		else if (number < min) {
			min = number;
		}
	}

	return min;
}

bool List::logicAnd() {
	QStringList List = getValue().toStringList();
	bool        res  = true;

	for (auto & str : List) {

		if (str == QStringLiteral("false")) {
			res = false;
		}
		else if (str != QStringLiteral("true")) {
			il->vm->exception(
			  {-2, QString("Failed to parse `%1` to bool").arg(str)});
			break;
		}
	}

	return res;
}

bool List::logicOr() {
	QStringList List = getValue().toStringList();
	bool        res  = false;

	for (auto & str : List) {

		if (str == QStringLiteral("true")) {
			res = true;
		}
		else if (str != QStringLiteral("false")) {
			il->vm->exception(
			  {-2, QString("Failed to parse `%1` to bool").arg(str)});
			break;
		}
	}

	return res;
}

void List::runPrepend(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		prepend(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runAppend(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		append(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runInsert(memory::ArgList & args) {
	if (
	  args.length() == 1 && args[0].object->type() == memory::Type::Int &&
	  args[1].object->type() == memory::Type::String) {
		insert(
		  args[0].object->getValue().toInt(),
		  args[1].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int, String>"));
	}
}

void List::runMerge(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::List) {
		merge(args[0].object->getValue().toStringList());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<List>"));
	}
}

void List::runPopFront(memory::ArgList & args) {
	if (args.length() == 0) {
		popFront();
	}
	else {
		sendWrongArglist(args, "<>");
	}
}

void List::runPopBack(memory::ArgList & args) {
	if (args.length() == 0) {
		popBack();
	}
	else {
		sendWrongArglist(args, "<>");
	}
}

void List::runRemove(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		remove(args[0].object->getValue().toInt());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int>"));
	}
}

void List::runRemoveOnce(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		removeOnce(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runRemoveAll(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		removeAll(args[0].object->getValue().toString());
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runGet(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::Int) {
		newValue   = get(args[0].object->getValue().toInt());
		newContext = new String{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int>"));
	}
}

void List::runIndexOf(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue   = indexOf(args[0].object->getValue().toString());
		newContext = new Int{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runLastIndexOf(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue   = lastIndexOf(args[0].object->getValue().toString());
		newContext = new Int{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runJoin(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue = join(args[0].object->getValue().toString());
	}
	else if (args.length() == 0) {
		newValue = join();
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String> or <>"));
		return;
	}

	newContext = new String{il, newValue, true};
}


void List::runSumUp(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = sumUp();
		newContext = new Double{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runMax(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = max();
		newContext = new Double{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runMin(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = min();
		newContext = new Double{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runLogicAnd(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = logicAnd();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runLogicOr(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = logicOr();
		newContext = new Boolean{il, newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}



QString List::getFirst() {
	QStringList value = getValue().toStringList();
	QString     ret;

	if (value.isEmpty()) {
		il->vm->exception({-3, "Empty List cannot be casted to any types"});
	}
	else if (value.size() > 1) {
		il->vm->exception(
		  {-4, "List with multiple values cannot be casted to any types"});
	}
	else {
		ret = value[0];
	}

	return ret;
}

Context * List::runProperty(Prefix prefix, const QString & name) {
	if (prefix != Prefix::None) {
		il->vm->exception(
		  {-405, "List objects are not support for prefixed properties"});
	}
	else {
		auto it = properties.find(name);

		if (it != properties.end()) {
			(this->*it.value())();
		}
		else {
			Object::runProperty(prefix, name);
		}
	}

	return newContext;
}

Context * List::runMethod(const QString & name, memory::ArgList & args) {

	auto it = methods.find(name);

	if (it != methods.end()) {
		(this->*it.value())(args);
	}
	else {
		Object::runMethod(name, args);
	}

	return newContext;
}

memory::Type List::type() const {
	return memory::Type::List;
}



bool List::toBoolean() {
	QString value = getFirst();

	if (!value.isNull()) {
		bool ok = true;
		bool res;

		if (value == "true") {
			res = true;
		}
		else if (value == "false") {
			res = false;
		}
		else {
			ok = false;
		}

		if (ok) {
			newValue = res;
			return res;
		}
		else {
			sendCastFailed(value, QStringLiteral("Boolean"));
		}
	}

	return false;
}

int List::toInt() {
	QString value = getFirst();

	if (!value.isNull()) {
		bool ok;
		int  res = value.toInt(&ok);

		if (ok) {
			newValue = res;
			return res;
		}
		else {
			sendCastFailed(value, QStringLiteral("Int"));
		}
	}

	return 0;
}

double List::toDouble() {
	QString value = getFirst();

	if (!value.isNull()) {
		bool ok;
		int  res = value.toDouble(&ok);

		if (ok) {
			newValue = res;
			return res;
		}
		else {
			sendCastFailed(value, QStringLiteral("Double"));
		}
	}

	return 0.0;
}

const QString List::toString() {
	QString value = getFirst();

	if (!value.isNull()) {
		newValue = value;
		return value;
	}

	return 0;
}

const QStringList List::toList() {
	newValue = getValue();
	return newValue.toStringList();
}

}  // namespace icL::context::object
