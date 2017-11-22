#ifndef HELPER_H
#define HELPER_H

#include <QColor>
#include <QObject>
#include <QQuickItem>

class Helper : public QObject
{
	Q_OBJECT

public:
	explicit Helper (QObject *parent = nullptr);

	Q_INVOKABLE QColor mix (QColor color1, QColor color2, qreal alpha);
	Q_INVOKABLE QColor linearMix (QColor color1, QColor color2, qreal alpha);

	Q_INVOKABLE void connect_f (QQuickItem *i1, QQuickItem *i2);

signals:

public slots:
};

#endif // HELPER_H
