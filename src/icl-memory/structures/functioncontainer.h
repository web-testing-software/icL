#ifndef icL_memory_FunctionContainer
#define icL_memory_FunctionContainer

#include "type.h"

#include <QLinkedList>
#include <QMap>
#include <QString>
#include <QVector>

namespace icL::context::object {
class Object;
}

/**
 *  icL
 *  |- app
 *  |- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '-> memory
 */
namespace icL::memory {

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
	int             begin = 0, end = -1, line = 0;
	const QString * source = nullptr;
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
	QString                   name;
	context::object::Object * object;
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

	Function & getFunction(const QString & name);
	bool       contains(const QString & name);
	void       registerFunction(const QString & name, Function & func);

private:
	FunctionMap fmap;
};

}  // namespace icL::memory

#endif  // icL_memory_FunctionContainer