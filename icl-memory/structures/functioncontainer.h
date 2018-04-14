#ifndef FUNCTIONCONTAINER_H
#define FUNCTIONCONTAINER_H

#include <QLinkedList>
#include <QMap>
#include <QString>

#include "type.h"


namespace vm::memory {

// Additional Stuctures

struct Argument {
	QString name;
	Type type;
};

typedef QLinkedList <Argument> ArgList;

struct CodeFragment {
	int begin = 0, end = -1;
	QString *source = nullptr;
};

struct Function {
	ArgList argList;
	CodeFragment source;
};

typedef QMap <QString, Function> FunctionMap;

// Main Class

class FunctionContainer
{
public:
	FunctionContainer ();

	Function& getFunction (const QString &name);
	bool contains (const QString &name);
	void registerFunction (const QString &name, Function &func);

private:
	FunctionMap fmap;
};

}

#endif // FUNCTIONCONTAINER_H
