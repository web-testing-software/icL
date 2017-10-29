import QtQuick 2.0
import "constants_controls.js" as CONST

MouseArea {
	id: root;

	hoverEnabled: true;

	height: text_item.height + 10;
	width: text_item.width + height;
	cursorShape: Qt.PointingHandCursor;

	property real alpha: 0.0;
	property bool reverse: false;
	property real width_normalized: width / _ratio;
	property real height_normalized: height / _ratio;
	property real radius: height_normalized / 2 - 2;
	property real left_normalized: radius + 2;
	property real y_center: radius + 2;
	property real bottom_normalized: y_center + radius;
	property real right_normalized: width_normalized - radius - 2;
	property real step_start: (width - height) / (width + height * CONST.PI_MINUS_1);

	property color drawColor: focus_color;

	property alias text: text_item.text;
	property alias pixelSize: text_item.font.pixelSize;
	property alias color: text_item.color;

	Behavior on alpha {
		NumberAnimation {
			duration: 250 * anim_time_multiplier;
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
				ctx.moveTo(left_normalized, 2);

				if (alpha > step_start) {
					step = Math.PI * (alpha - step_start) / (1 - step_start);

					ctx.arc(right_normalized, y_center, radius, CONST.PI_1_5, CONST.PI_1_5 + step);
					ctx.moveTo(right_normalized, bottom_normalized);
					ctx.arc(left_normalized, y_center, radius, CONST.PI_0_5, CONST.PI_0_5 + step);
				}
				else {
					step = (width_normalized - height_normalized) * alpha / step_start;

					ctx.lineTo(left_normalized + step, 2);
					ctx.moveTo(right_normalized, bottom_normalized);
					ctx.lineTo(right_normalized - step, bottom_normalized);
				}
			}
			else {
				var step_start2 = 1 - step_start;

				if (alpha > step_start2) {
					step = (alpha - step_start2) / (1 - step_start2) * (width_normalized - height_normalized);

					ctx.moveTo(right_normalized - step, 2);
					ctx.arc(right_normalized, y_center, radius, CONST.PI_1_5, CONST.PI_2_5);
					ctx.moveTo(left_normalized + step, bottom_normalized);
					ctx.arc(left_normalized, y_center, radius, CONST.PI_0_5, CONST.PI_1_5);
				}
				else {
					step = alpha / step_start2 * Math.PI;

					ctx.moveTo(right_normalized, bottom_normalized);
					ctx.arc(right_normalized, y_center, radius, CONST.PI_0_5, CONST.PI_0_5 - step, true);
					ctx.moveTo(left_normalized, 1);
					ctx.arc(left_normalized, y_center, radius, CONST.PI_1_5, CONST.PI_1_5 - step, true);
				}
			}

			ctx.stroke();
			ctx.restore();
		}
	}

	Text {
		id: text_item;
		anchors.centerIn: parent;

		color: "#2b2b2b";
		text: "BUTTON";

		font.pixelSize: Math.round(14 * _ratio);
		font.family: "Ubuntu";
	}
}
