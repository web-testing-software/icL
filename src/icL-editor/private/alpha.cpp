#include "alpha.h"

#include <QDebug>
#include <QtMath>

namespace icL::editor {

float Alpha::nextValue() {
	return nextAlpha;
}

void Alpha::setCurrentAlpha(float value) {
	if (nextAlpha == value) {
		return;
	}

	nextAlpha = value;
	lastAlpha = currentAlpha;

	last_time.start();

	need_update = true;
}

void Alpha::forceSetCurrentAlpha(float value) {
	last_time.start();
	currentAlpha = nextAlpha = lastAlpha = value;
}

void Alpha::setInterval(int interval) {
	interval_in_ms = interval;
}

void Alpha::setSpeedUpOnFadeIn(bool value) {
	speed_up_fadein = value;
}

bool Alpha::update() {
	if (!need_update) {
		return false;
	}

	bool ret     = false;
	int  elapsed = last_time.elapsed();

	if (speed_up_fadein && nextAlpha > lastAlpha) {
		elapsed *= 2;
	}

	if (elapsed > interval_in_ms) {
		if (nextAlpha != currentAlpha) {
			currentAlpha = nextAlpha;
			ret          = true;
		}
		need_update = false;
	}
	else {
		float alpha =
		  static_cast<float>(elapsed) / static_cast<float>(interval_in_ms);

		alpha = transition(alpha);

		currentAlpha = lastAlpha + (nextAlpha - lastAlpha) * alpha;
		ret          = true;
		need_update  = true;
	}

	if (currentAlpha != 0) {
		qDebug() << currentAlpha << lastAlpha << nextAlpha;
	}

	return ret;
}

qreal Alpha::transition(qreal x) {
	// x = (e^(x*e) - 1) / (e^e - 1) for x {0, 1}, max error 0.0015 = 0.15%
	return x * (x * (x * (x * 0.6755328851108425f - 0.3190423664446824f) +
					 0.47886115389358097f) +
				0.1646483274402586f);
}

}  // namespace icL::editor
