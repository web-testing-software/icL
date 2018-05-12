#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "icl-context/context.h"
#include <QObject>
#include <functional>

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
};

}  // namespace vm::inter

#endif  // INTERPRETER_H
