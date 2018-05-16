#include "list.h"

#include "boolean.h"
#include "double.h"
#include "int.h"
#include "string.h"

namespace icL::context::object {



List::List(memory::DataState * container, const QString & varName)
	: Object(container, varName) {}

List::List(const QVariant & rvalue, bool readonly)
	: Object(rvalue, readonly) {}

List::List(const QString & getter, const QString & setter)
	: Object(getter, setter) {}

List::List(const Object * const object)
	: Object(object) {}


int List::length() {
	return getValue().toStringList().length();
}


void List::runGetLength() {
	newValue   = length();
	newContext = new Int(newValue, true);
}


void List::prepend(const QString & value) {
	QStringList list = getValue().toStringList();

	list.prepend(value);
	setValue(list);
}

void List::append(const QString & value) {
	QStringList list = getValue().toStringList();

	list.append(value);
	setValue(list);
}

void List::insert(int index, const QString & value) {
	QStringList list = getValue().toStringList();

	list.insert(index, value);
	setValue(list);
}

void List::merge(const QStringList & list) {
	QStringList list1 = getValue().toStringList();

	list1.append(list);
	setValue(list1);
}

void List::popFront() {
	QStringList list = getValue().toStringList();

	if (list.isEmpty()) {
		emit exception({-3, "Can not remove first item of empty list"});
	}
	else {
		list.removeFirst();
		setValue(list);
	}
}

void List::popBack() {
	QStringList list = getValue().toStringList();

	if (list.isEmpty()) {
		emit exception({-3, "Can not remove first item of empty list"});
	}
	else {
		list.removeLast();
		setValue(list);
	}
}

void List::remove(int index) {
	QStringList list = getValue().toStringList();

	if (index < 0 || index >= list.length()) {
		emit exception({-8, "Index out of bounds"});
	}
	else {
		list.removeAt(index);
		setValue(list);
	}
}

void List::removeOnce(const QString & value) {
	QStringList list = getValue().toStringList();

	list.removeOne(value);
	setValue(list);
}

void List::removeAll(const QString & value) {
	QStringList list = getValue().toStringList();

	list.removeAll(value);
	setValue(list);
}

QString List::get(int index) {
	QStringList list = getValue().toStringList();

	if (index < 0 || index >= list.length()) {
		emit exception({-8, "Index out of bounds"});
	}
	else {
		return list.at(index);
	}

	return QString{};
}

int List::indexOf(const QString & value) {
	QStringList list = getValue().toStringList();

	return list.indexOf(value);
}

int List::lastIndexOf(const QString value) {
	QStringList list = getValue().toStringList();

	return list.lastIndexOf(value);
}

QString List::join(const QString & delimiter) {
	QStringList list = getValue().toStringList();

	return list.join(delimiter);
}

double List::sumUp() {
	QStringList list = getValue().toStringList();
	double      sum  = 0;

	for (auto & str : list) {
		bool ok;
		sum += str.toDouble(&ok);

		if (!ok) {
			emit exception(
			  {-2, QString("Failed to parse `%1` to double").arg(str)});
			break;
		}
	}

	return sum;
}

double List::max() {
	QStringList list = getValue().toStringList();

	if (list.isEmpty()) {
		emit exception({-3, "Cannot find max value in empty list"});
		return 0.0;
	}

	double max = list.at(0).toDouble();

	for (auto & str : list) {
		bool   ok;
		double number = str.toDouble(&ok);

		if (!ok) {
			emit exception(
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
	QStringList list = getValue().toStringList();

	if (list.isEmpty()) {
		emit exception({-3, "Cannot find min value in empty list"});
		return 0.0;
	}

	double min = list.at(0).toDouble();

	for (auto & str : list) {
		bool   ok;
		double number = str.toDouble(&ok);

		if (!ok) {
			emit exception(
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
	QStringList list = getValue().toStringList();
	bool        res  = true;

	for (auto & str : list) {
		bool ok;

		if (str == QStringLiteral("false")) {
			res = false;
		}
		else if (str != QStringLiteral("true")) {
			emit exception(
			  {-2, QString("Failed to parse `%1` to bool").arg(str)});
			break;
		}
	}

	return res;
}

bool List::logicOr() {
	QStringList list = getValue().toStringList();
	bool        res  = false;

	for (auto & str : list) {
		bool ok;

		if (str == QStringLiteral("true")) {
			res = true;
		}
		else if (str != QStringLiteral("false")) {
			emit exception(
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
		newContext = new String{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<Int>"));
	}
}

void List::runIndexOf(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue   = indexOf(args[0].object->getValue().toString());
		newContext = new Int{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<String>"));
	}
}

void List::runLastIndexOf(memory::ArgList & args) {
	if (args.length() == 1 && args[0].object->type() == memory::Type::String) {
		newValue   = lastIndexOf(args[0].object->getValue().toString());
		newContext = new Int{newValue, true};
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

	newContext = new String{newValue, true};
}


void List::runSumUp(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = sumUp();
		newContext = new Double{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runMax(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = max();
		newContext = new Double{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runMin(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = min();
		newContext = new Double{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runLogicAnd(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = logicAnd();
		newContext = new Boolean{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}

void List::runLogicOr(memory::ArgList & args) {
	if (args.length() == 0) {
		newValue   = logicOr();
		newContext = new Boolean{newValue, true};
	}
	else {
		sendWrongArglist(args, QStringLiteral("<>"));
	}
}



QString List::getFirst() {
	QStringList value = getValue().toStringList();
	QString     ret;

	if (value.isEmpty()) {
		emit exception({-3, "Empty list cannot be casted to any types"});
	}
	else if (value.size() > 1) {
		emit exception(
		  {-4, "List with multiple values cannot be casted to any types"});
	}
	else {
		ret = value[0];
	}

	return ret;
}

Context * List::runProperty(Prefix prefix, const QString & name) {
	if (prefix != Prefix::None) {
		emit exception(
		  {-405, "List objects are not support for prefixed properties"});
	}
	else {
		if (name == "Length") {
			runGetLength();
		}
		else {
			Context::runProperty(prefix, name);
		}
	}

	return newContext;
}

Context * List::runMethod(const QString & name, memory::ArgList & args) {


	if (name == QStringLiteral("Prepend")) {
		runPrepend(args);
	}
	else if (name == QStringLiteral("Append")) {
		runAppend(args);
	}
	else if (name == QStringLiteral("Insert")) {
		runInsert(args);
	}
	else if (name == QStringLiteral("Merge")) {
		runMerge(args);
	}
	else if (name == QStringLiteral("PopFront")) {
		runPopFront(args);
	}
	else if (name == QStringLiteral("PopBack")) {
		runPopBack(args);
	}
	else if (name == QStringLiteral("Remove")) {
		runRemove(args);
	}
	else if (name == QStringLiteral("RemoveOnce")) {
		runRemoveOnce(args);
	}
	else if (name == QStringLiteral("RemoveAll")) {
		runRemoveAll(args);
	}
	else if (name == QStringLiteral("Get")) {
		runGet(args);
	}
	else if (name == QStringLiteral("IndexOf")) {
		runIndexOf(args);
	}
	else if (name == QStringLiteral("LastIndexOf")) {
		runLastIndexOf(args);
	}
	else if (name == QStringLiteral("Join")) {
		runJoin(args);
	}
	else if (name == QStringLiteral("SumUp")) {
		runSumUp(args);
	}
	else if (name == QStringLiteral("Max")) {
		runMax(args);
	}
	else if (name == QStringLiteral("Min")) {
		runMin(args);
	}
	else if (name == QStringLiteral("LogicAnd")) {
		runLogicAnd(args);
	}
	else if (name == QStringLiteral("LogicOr")) {
		runLogicOr(args);
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
