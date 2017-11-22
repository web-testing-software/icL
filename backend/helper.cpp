#include "helper.h"

#include <QtMath>

Helper::Helper (QObject *parent) : QObject (parent) {

}

QColor Helper::mix (QColor color1, QColor color2, qreal alpha) {
	int r	= color1.red ();
	int g	= color1.green ();
	int b	= color1.blue ();

	if (color1.lightness () > color2.lightness ()) {
		alpha = qSqrt (alpha);
	}
	else {
		alpha *= alpha;
	}

	QColor ret;

	ret.setRgb (r + (color2.red () - r) * alpha,
				g + (color2.green () - g) * alpha,
				b + (color2.blue () - b) * alpha);

	return ret;
}

QColor Helper::linearMix(QColor color1, QColor color2, qreal alpha) {
	int r	= color1.red ();
	int g	= color1.green ();
	int b	= color1.blue ();
	QColor ret;

	ret.setRgb (r + (color2.red () - r) * alpha,
				g + (color2.green () - g) * alpha,
				b + (color2.blue () - b) * alpha);

	return ret;
}

void Helper::connect_f(QQuickItem *i1, QQuickItem *i2)
{
	QObject::connect (i1, SIGNAL(needGrab()), i2, SLOT(grab2()));
}
