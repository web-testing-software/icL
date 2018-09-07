import QtQuick 2.0

Base {
	id: root;
	drawColor: "#3e3e3e";

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

			var step = 5 + 2 * alpha;

			ctx.moveTo(10 - step, 10);
			ctx.lineTo(10 + step, 10);

			ctx.moveTo(10, 10 - step);
			ctx.lineTo(10, 10 + step);

			ctx.stroke();
			ctx.restore();
		}
	}
}
