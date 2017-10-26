import QtQuick 2.0

import "constants_controls.js" as CONST;

MouseArea {
	id: root;

	width: Math.round(40 * _ratio);
	height: Math.round(width / 2);

	property real alpha: value ? 1.0 : 0.0;
	property bool value: false;
	property bool reversed: true;
	property color activeColor: "#0fac00";
	property color pasiveColor: "#5b5b5b";
	property color drawColor1: helper.mix(activeColor, pasiveColor, alpha);
	property color drawColor2: helper.mix(pasiveColor, activeColor, alpha);

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	onClicked: {
		if (value) {
			if (alpha == 1.0) {
				reversed = true;
			}
		}
		else {
			if (alpha == 0.0) {
				reversed = false;
			}
		}

		value = !value;
	}

	Behavior on alpha {
		NumberAnimation {
			duration: 500 * anim_time_multiplier;
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
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.strokeStyle = drawColor1;
			ctx.fillStyle = drawColor1;
			ctx.beginPath();

			if (!reversed) {

				if (alpha < 0.65) {
					var begin_angle = CONST.PI_2_5 - CONST.PI_2_0 * alpha * 1.538;

					ctx.moveTo(11 + CONST.R * Math.cos(begin_angle), 10 + CONST.R * Math.sin(begin_angle));
					ctx.arc(11, 10, CONST.R, begin_angle, CONST.PI_0_5, true);
				}

				if (alpha < 0.5) {
					ctx.lineTo(11 + 36 * alpha, 18);
				}
				else {
					if (alpha < 0.65) {
						ctx.lineTo(29, 18);
					}
					else {
						if (alpha == 1.0) {
							ctx.moveTo(29, 18);
						}
						else {
							ctx.moveTo(11 + 55 * (alpha - 0.65), 18);
						}
					}

					ctx.arc(29, 10, CONST.R, CONST.PI_0_5, CONST.PI_0_5 - CONST.PI_4_0 * (alpha - 0.5), true);
				}

				ctx.stroke();
				ctx.beginPath();

				if (alpha < 0.5) {
					begin_angle = CONST.PI_2_5 - CONST.PI_2_0 * alpha;

					ctx.moveTo(29 + CONST.R * Math.cos(begin_angle), 10 + CONST.R * Math.sin(begin_angle));
					ctx.arc(29, 10, CONST.R, begin_angle, CONST.PI_1_5, true);
					ctx.lineTo(29 - 18 * alpha, 2);
				}
				else if (alpha < 0.75) {
					var step = (alpha - 0.5) * 36;

					ctx.moveTo(29 - step, 2);
					ctx.lineTo(20 - step, 2);
				}
				else {
					var local_alpha = alpha - 0.75;
					ctx.moveTo(20 - local_alpha * 36, 2);
					ctx.arc(11, 10, CONST.R, CONST.PI_1_5, CONST.PI_1_5 - CONST.PI_4_0 * local_alpha, true);
				}
			}
			else {
				// If reversed
				if (alpha < 0.65) {
					begin_angle = CONST.PI_1_5 + CONST.PI_2_0 * alpha * 1.538;

					ctx.moveTo(11 + CONST.R * Math.cos(begin_angle), 10 + CONST.R * Math.sin(begin_angle));
					ctx.arc(11, 10, CONST.R, begin_angle, CONST.PI_3_5, false);
				}

				if (alpha < 0.5) {
					ctx.lineTo(11 + 36 * alpha, 2);
				}
				else {
					if (alpha < 0.65) {
						ctx.lineTo(29, 2);
					}
					else {
						if (alpha == 1.0) {
							ctx.moveTo(29, 2);
						}
						else {
							ctx.moveTo(11 + 55 * (alpha - 0.65), 2);
						}
					}

					ctx.arc(29, 10, CONST.R, CONST.PI_3_5, CONST.PI_3_5 + CONST.PI_4_0 * (alpha - 0.5), false);
				}

				ctx.stroke();
				ctx.beginPath();

				if (alpha < 0.5) {
					begin_angle = CONST.PI_1_5 + CONST.PI_2_0 * alpha;

					ctx.moveTo(29 + CONST.R * Math.cos(begin_angle), 10 + CONST.R * Math.sin(begin_angle));
					ctx.arc(29, 10, CONST.R, begin_angle, CONST.PI_2_5, false);
					ctx.lineTo(29 - 18 * alpha, 18);
				}
				else if (alpha < 0.75) {
					step = (alpha - 0.5) * 36;

					ctx.moveTo(29 - step, 18);
					ctx.lineTo(20 - step, 18);
				}
				else {
					local_alpha = alpha - 0.75;
					ctx.moveTo(20 - local_alpha * 36, 18);
					ctx.arc(11, 10, CONST.R, CONST.PI_0_5, CONST.PI_0_5 + CONST.PI_4_0 * local_alpha, false);
				}
			}

			ctx.strokeStyle = drawColor2;
			ctx.stroke();

			ctx.beginPath();

			if (alpha <= 0.25) {
				ctx.moveTo(13, 10);
				ctx.arc(11, 10, 2, 0, CONST.PI_2_0);
			}
			else if (alpha >= 0.75) {
				ctx.moveTo(31, 10);
				ctx.arc(29, 10, 2, 0, CONST.PI_2_0);
			}
			else {
				var circle_x = 11 + 36 * (alpha - 0.25);

				ctx.moveTo(circle_x + 2, 10);
				ctx.arc(circle_x, 10, 2, 0, CONST.PI_2_0);
			}

			ctx.fill();

			ctx.restore();
		}
	}

	Timer {
		onTriggered: {
			if (value) {
				reversed = true;
			}
			else {
				reversed = false;
			}

			value = !value;
		}
		interval: 2000;
		running: true;
		repeat: true;
	}
}
