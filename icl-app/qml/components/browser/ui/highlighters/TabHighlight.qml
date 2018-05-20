import QtQuick 2.0

MouseArea {
	id: root;

	hoverEnabled: true;

	property real alpha: 0.0;
	property bool reverse: false;
	property real bottom_normalized: height / _ratio - 1;
	property real right_normalized: width / _ratio - 1;
	property real width_0_5: (right_normalized - 1) * 0.5;
	property real step_start: bottom_normalized / (bottom_normalized + width_0_5);

	property color drawColor: "#232323";

	Behavior on alpha {
		NumberAnimation {
			duration: 240 * anim_time_multiplier;
		}
	}

	onAlphaChanged: canvas.requestPaint();
	onContainsMouseChanged: {
		if (containsMouse) {
			if (alpha == 0.0) {
				reverse = false;
			}
			alpha = 1.0;
		}
		else {
			if (alpha == 1.0) {
				reverse = true;
			}
			alpha = 0.0;
		}
	}

	Canvas {
		id: canvas;
		anchors.fill: parent;

		onPaint: {
			var ctx = getContext("2d");

			ctx.save();
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			ctx.scale(_ratio, _ratio);
			ctx.strokeStyle = drawColor; //root.drawColor;
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			var step;

			ctx.beginPath();

			if (!reverse) {
				ctx.moveTo(1, bottom_normalized);

				if (alpha > step_start) {
					ctx.lineTo(1, 1);

					if (alpha < 1.0) {
						step = (alpha - step_start) / (1 - step_start) * width_0_5;
						ctx.lineTo(1 + step, 1);
						ctx.moveTo(right_normalized - step, 1);
					}

					ctx.lineTo(right_normalized, 1);
				}
				else {
					step = bottom_normalized - alpha / step_start * bottom_normalized + 1;

					ctx.lineTo(1, step);
					ctx.moveTo(right_normalized, step);
				}

				ctx.lineTo(right_normalized, bottom_normalized);
			}
			else {
				var step_start2 = 1 - step_start;
				if (alpha > step_start2) {
					step = (alpha - step_start2) / (1 - step_start2) *
							bottom_normalized + 1;

					ctx.moveTo(1, step);
					ctx.lineTo(1, 1);
					ctx.lineTo(right_normalized, 1);
					ctx.lineTo(right_normalized, step);
				}
				else {
					step = width_0_5 - alpha / step_start2 * width_0_5;

					ctx.moveTo(step, 1);
					ctx.lineTo(right_normalized - step, 1);
				}
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
