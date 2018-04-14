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
	void interrupt (QString *, int, int, std::function <void ( QVariant& )> );

public slots:
	void repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func);
};

} // namespace

#endif // INTERPRETER_H
