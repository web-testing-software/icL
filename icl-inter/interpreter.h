#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <functional>
#include <QObject>

#include "icl-context/context.h"

namespace vm::inter {

class Interpreter : public QObject
{
	Q_OBJECT
public:
	explicit Interpreter (QObject *parent = nullptr);

signals:
	void interrupt (memory::Function, std::function <void ( memory::Return& )> );

public slots:
	void repeat (memory::Function run, std::function <void ( memory::Return& )> feedback);
};

} // namespace

#endif // INTERPRETER_H
