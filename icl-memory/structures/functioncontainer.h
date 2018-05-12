#ifndef FUNCTIONCONTAINER_H
#define FUNCTIONCONTAINER_H

#include "type.h"
#include <QLinkedList>
#include <QMap>
#include <QString>
#include <QVector>

namespace vm::context {
class Context;
}

namespace vm::memory {

// Additional Stuctures

// Function header

struct Argument
{
	QString name;
	Type    type;
};

using ArgList = QLinkedList<Argument>;

struct CodeFragment
{
	int      begin = 0, end = -1, line = 0;
	QString* source = nullptr;
};

struct Function
{
	ArgList      argList;
	CodeFragment source;
};

using FunctionMap = QMap<QString, Function>;

// Function call

struct Parameter
{
	QString           name;
	context::Context* object;
};

using ParamList = QVector<Parameter>;

struct FunctionCall
{
	ParamList    params;
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
