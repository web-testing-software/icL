#ifndef TYPE_H
#define TYPE_H

#include <QString>


namespace vm::memory {

enum class Type {
	Void,
	Boolean,
	Int,
	Double,
	String,
	List,
	Element
};

QString typeToString (Type type) {
	QString ret;

	switch (type) {
	case Type::Void:
		ret = "Void";
		break;

	case Type::Boolean:
		ret = "Boolean";
		break;

	case Type::Int:
		ret = "Int";
		break;

	case Type::Double:
		ret = "Double";
		break;

	case Type::String:
		ret = "String";
		break;

	case Type::List:
		ret = "List";
		break;

	case Type::Element:
		ret = "Element";
		break;
	}

	return ret;
}

}

#endif // TYPE_H
