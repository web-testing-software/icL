import QtQuick 2.0

ToolIcon {
	id: root;

	alpha: reversed ? (containsMouse ? 2.0 : 1.0) : 0.0;

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
			ctx.moveTo(17, 18);
			ctx.lineTo(3, 10);
			ctx.lineTo(17, 2);

			if (alpha > 0) {
				if (alpha >= 1) {
					ctx.lineTo(17, 14);
				}
				else {
					ctx.lineTo(17, 2 + 12 * alpha);
				}
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
