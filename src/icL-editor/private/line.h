#ifndef LINE_H
#define LINE_H

#include <QObject>

namespace icL::editor {

class Line : public QObject
{
	Q_OBJECT
public:
	explicit Line(QObject *parent = nullptr);

signals:

public slots:
};

} // namespace

#endif // LINE_H
