import QtQuick 2.0

Hover {
	id: root;
	drawColor: "#5b5b5b";

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

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

			ctx.beginPath();

			var step_x, step_y;

			if (!reversed) {
				if (alpha < 0.5) {
					step_x = 5;
					step_y = 5 + 6 * alpha;
				}
				else {
					step_x = 2 + 6 * alpha // 5 + 6 * (alpha - 0.5) simplified
					step_y = 8;
				}
			}
			else {
				if (alpha < 0.5) {
					step_x = 5 + 6 * alpha;
					step_y = 5;
				}
				else {
					step_x = 8;
					step_y = 2 + 6 * alpha // 5 + 6 * (alpha - 0.5) simplified
				}
			}

			ctx.moveTo(10 - step_x, 10);
			ctx.lineTo(10 + step_x, 10);

			ctx.moveTo(10, 10 - step_y);
			ctx.lineTo(10, 10 + step_y);

			ctx.stroke();
			ctx.restore();
		}
	}
}
