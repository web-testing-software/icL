#include "base.h"

#include <QColor>

namespace icL::look::base {

Base::Base(QObject * parent)
	: QObject(parent) {}

QColor Base::objToColor(const QJsonObject & obj) {
	QJsonValue hex = obj.value("hex");

	if (hex.isString()) {
		return {hex.toString()};
	}
	else {
		int r = obj.value("r").toInt(0);
		int g = obj.value("g").toInt(0);
		int b = obj.value("b").toInt(0);
		int a = obj.value("a").toInt(255);

		return {r, g, b, a};
	}
}

}  // namespace icL::look::base
