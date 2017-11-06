import QtQuick 2.0

Base {
	id: root;

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	onClicked: web_browser.showMinimized();

	Canvas {
		id: canvas;
		anchors.fill: parent;

		onPaint: {
			var ctx = getContext("2d");

			ctx.save();
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			ctx.scale(_ratio, _ratio);
			ctx.strokeStyle = drawColor; //root.drawColor;
			ctx.lineCap = "square"; // butt round square
			ctx.lineJoin = "milter"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.beginPath();

			var key_y = 8 + alpha * 4;

			ctx.moveTo(6, key_y);
			ctx.lineTo(10, 12);
			ctx.lineTo(14, key_y);

			ctx.stroke();
			ctx.restore();
		}
	}
}
