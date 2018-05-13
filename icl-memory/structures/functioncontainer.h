#ifndef FUNCTIONCONTAINER_H
#define FUNCTIONCONTAINER_H

#include "type.h"

#include <QLinkedList>
#include <QMap>
#include <QString>
#include <QVector>

namespace vm::context::object {
class Object;
}

namespace vm::memory {

// Additional Stuctures

// Function header

struct Parameter
{
	QString name;
	Type    type;
};

using ParamList = QLinkedList<Parameter>;

struct CodeFragment
{
	int      begin = 0, end = -1, line = 0;
	QString* source = nullptr;
};

struct Function
{
	ParamList    paramList;
	CodeFragment source;
};

using FunctionMap = QMap<QString, Function>;

// Function call

struct Argument
{
	QString                  name;
	context::object::Object* object;
};

using ArgList = QVector<Argument>;

struct FunctionCall
{
	ArgList      args;
	CodeFragment source;
};

// Main Class

class FunctionContainer
{
public:
	FunctionContainer();

	Function& getFunction(const QString& name);
	bool      contains(const QString& name);
	void      registerFunction(const QString& name, Function& func);

private:
	FunctionMap fmap;
};

}  // namespace vm::memory

#endif  // FUNCTIONCONTAINER_H
