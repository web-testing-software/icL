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

    lastTime.start();

    needUpdate = true;
}

void Alpha::forceSetCurrentAlpha(float value) {
    lastTime.start();
    currentAlpha = nextAlpha = lastAlpha = value;
}

void Alpha::setInterval(int interval) {
    intervalInMs = interval;
}

void Alpha::setSpeedUpOnFadeIn(bool value) {
    speedUpFadein = value;
}

bool Alpha::update() {
    if (!needUpdate) {
        return false;
    }

    bool ret     = false;
    int  elapsed = lastTime.elapsed();

    if (speedUpFadein && nextAlpha > lastAlpha) {
        elapsed *= 2;
    }

    if (elapsed > intervalInMs) {
        if (nextAlpha != currentAlpha) {
            currentAlpha = nextAlpha;
            ret          = true;
        }
        needUpdate = false;
    }
    else {
        float alpha =
          static_cast<float>(elapsed) / static_cast<float>(intervalInMs);

        alpha = transition(alpha);

        currentAlpha = lastAlpha + (nextAlpha - lastAlpha) * alpha;
        ret          = true;
        needUpdate   = true;
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
