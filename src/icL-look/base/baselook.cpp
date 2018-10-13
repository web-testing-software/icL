#include "baselook.h"

#include <QColor>
#include <QJsonObject>

namespace icL::look {

BaseLook::BaseLook(QObject * parent)
	: QObject(parent) {}

QColor BaseLook::objToColor(const QJsonObject & obj) {
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

QJsonObject BaseLook::colorToObj(const QColor & color) {
	if (color.alpha() == 255) {
		return {{"hex", color.name()}};
	}
	else {
		return {{"r", color.red()},
				{"g", color.green()},
				{"b", color.blue()},
				{"a", color.alpha()}};
	}
}

}
