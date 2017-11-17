import QtQuick 2.5

import "../../"

AnimatedIconIterface {
	id: root;

	alpha: 0.0;
	drawColor: "#e1e1e2";
	reversed: false;

	anchors.top: parent.top;
	anchors.bottom: parent.bottom;
	hoverEnabled: true;
	onDrawColorChanged: canvas.requestPaint();
	onAlphaChanged: canvas.requestPaint();

	Canvas {
		id: canvas;
		anchors.left: parent.left;
		anchors.right: parent.right;
		anchors.bottom: parent.bottom;
		height: Math.round(2 * _ratio);

		onPaint: {
			var ctx = getContext("2d");

			ctx.save();
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			ctx.scale(1, _ratio);
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			if (!reversed) {
				var step = width * alpha;

				if (alpha > 0) {
					ctx.strokeStyle = focus_color;
					ctx.beginPath();
					ctx.moveTo(0, 1);
					ctx.lineTo(step, 1);
					ctx.stroke();
				}

				ctx.beginPath();
				ctx.strokeStyle = drawColor;
				ctx.moveTo(step, 1);
				ctx.lineTo(width, 1);
				ctx.stroke();
			}
			else {
				step = width * (1 - alpha);

				if (alpha > 0) {
					ctx.strokeStyle = focus_color;
					ctx.beginPath();
					ctx.moveTo(width, 1);
					ctx.lineTo(step, 1);
					ctx.stroke();
				}

				ctx.beginPath();
				ctx.strokeStyle = drawColor;
				ctx.moveTo(0, 1);
				ctx.lineTo(step, 1);
				ctx.stroke();
			}

			ctx.restore();
		}
	}
}
