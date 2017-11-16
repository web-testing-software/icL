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


			var step = 4 * alpha;

			ctx.beginPath();

			ctx.moveTo(10 - step, 2);
			ctx.lineTo(2, 2);
			ctx.lineTo(2, 18);
			ctx.lineTo(18, 18);
			ctx.lineTo(18, 10 + step);

			ctx.moveTo(18, 8);
			ctx.lineTo(18, 2);
			ctx.lineTo(12, 2);

			ctx.moveTo(18, 2);
			ctx.lineTo(6 + step, 14 - step);

			ctx.stroke();
			ctx.restore();
		}
	}
}
