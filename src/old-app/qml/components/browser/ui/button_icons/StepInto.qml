import QtQuick 2.0

Base {
	id: root;

	drawColor: helper.linearMix(primary_color, focus_color, alpha);

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	property color primary_color: "#3e3e3e";

	Canvas {
		id: canvas;
		anchors.fill: parent;

		onPaint: {
			var ctx = getContext("2d");

			ctx.save();
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			ctx.scale(_ratio, _ratio);
			ctx.fillStyle = primary_color; //root.drawColor;
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.rect(12, 9, 8, 2); // 3
			ctx.rect(12, 13, 8, 2); // 4
			ctx.rect(0, 17, 20, 2); // 5

			ctx.fill();

			ctx.beginPath();
			ctx.fillStyle = drawColor;

			ctx.rect(0, 1, 20, 2); // 1
			ctx.rect(12, 5, 8, 2); // 2

			var step = alpha;

			ctx.moveTo(step, 15);
			ctx.lineTo(8 + step, 10);
			ctx.lineTo(step, 5);

			ctx.fill();

			ctx.restore();
		}
	}
}
