#ifndef VM_CONTEXT_CONTEXT_H
#define VM_CONTEXT_CONTEXT_H

#include <QObject>
#include <functional>

namespace vm::context {

class Context : public QObject
{

public:
	Context ();

signals:
	void interrupt (QString *, int, int, std::function <void ( Context * )> );
	void interrupt (QString *, int, int, std::function <void ( QVariant& )> );

public slots:
	void repeat (QString *str, int begin, int end, std::function <void ( QVariant& )> func);
};


} // namespace

#endif // VM_CONTEXT_CONTEXT_H
