#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <icl-context/context-base/context.h>
#include <icl-context/context-base/object/int.h>
#include <icl-memory/structures/functioncontainer.h>
#include <icl-memory/structures/return.h>

#include <functional>

#include <QObject>


/**
 * vm
 *	|- context
 *  |  |- complex
 *  |  |- code
 *  |  |  '- control
 *  |  |     '- catch0
 *  |  |- data
 *  |  '- object
 *  |- @namespace inter
 *  |- logic
 *  |  |- cross
 *  |  '- rich
 *  '- memory
 */
namespace vm::inter {

class Interpreter : public QObject
{
	Q_OBJECT
public:
	explicit Interpreter(QObject* parent = nullptr);

signals:
	void interrupt(memory::FunctionCall, std::function<void(memory::Return&)>);

public slots:
	void repeat(
	  memory::FunctionCall run, std::function<void(memory::Return&)> feedback);

private:
	context::Context* context = new context::object::Int(QVariant(0));
};

}  // namespace vm::inter

#endif  // INTERPRETER_H
