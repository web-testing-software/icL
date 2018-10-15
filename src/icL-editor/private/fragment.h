#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QObject>

namespace icL::editor {

class Fragment : public QObject
{
	Q_OBJECT
public:
	explicit Fragment(QObject *parent = nullptr);

signals:

public slots:
};

} // namespace

#endif // FRAGMENT_H
