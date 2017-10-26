#ifndef HELPER_H
#define HELPER_H

#include <QColor>
#include <QObject>

class Helper : public QObject
{
	Q_OBJECT

public:
	explicit Helper (QObject *parent = nullptr);

	Q_INVOKABLE QColor mix (QColor color1, QColor color2, qreal alpha);

signals:

public slots:
};

#endif // HELPER_H
