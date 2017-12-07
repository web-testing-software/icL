#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QObject>

namespace vm::inter {

class Interpreter : public QObject
{
	Q_OBJECT
public:
	explicit Interpreter (QObject *parent = nullptr);

signals:

public slots:
};

} // namespace

#endif // INTERPRETER_H
