#ifndef TYPE_H
#define TYPE_H

#include <QString>
#include <QVariant>


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

QString typeToString (Type type);

Type variantTypeToType (QVariant::Type type);

}

#endif // TYPE_H
