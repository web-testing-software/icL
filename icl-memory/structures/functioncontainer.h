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

using ArgList = QLinkedList<Argument>;

struct CodeFragment {
	int begin = 0, end = -1, line = 0;
	QString *source = nullptr;
};

struct Function {
	ArgList argList;
	CodeFragment source;
};

using FunctionMap = QMap <QString, Function>;

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
