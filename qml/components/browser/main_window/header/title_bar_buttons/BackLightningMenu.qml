import QtQuick 2.0

import "../../../ui" as Ui;

Ui.AnimatedIconIterface {
	id: root;

	x: Math.round(2 * _ratio);
	y: Math.round(win.isMaximized ? -4 : 2 * _ratio);
	width: height * 0.75;
	height: Math.round(40 * _ratio);

	reversed: !containsMouse;
	alpha: containsMouse ? (need_back ? -1 : 1) : 0;

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();
	onDrawColorChanged: canvas.requestPaint();

	property bool need_back: true;

	drawColor: focus_color;

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

			if (alpha > 0) {

				// Top line
				if (alpha < 0.360097) {
					var ralpha1 = alpha * 2.77703;

					ctx.moveTo(12 + 10 * ralpha1, 20 - 18 * ralpha1);
					ctx.lineTo(22, 2);
				}
				else if (alpha < 0.5) {
					ralpha1 = (alpha - 0.360097) * 7.14782;

					ctx.moveTo(22 - 8 * ralpha1, 2);
				}

				if (alpha < 0.5) {
					ralpha1 = alpha * 2;

					ctx.lineTo(14, 2);
					ctx.lineTo(14 - 10 * ralpha1, 2 + 13 * ralpha1);
				}
				else {
					ralpha1 = (alpha - 0.5) * 2;

					ctx.moveTo(14 - 10 * ralpha1, 2 + 13 * ralpha1);
					ctx.lineTo(4, 15);
					ctx.lineTo(4 + 22 * ralpha1, 15);
				}

				// Bottom line
				if (alpha < 0.359982) {
					ralpha1 = alpha * 2.77791;

					ctx.moveTo(14 - 6 * ralpha1, 25 + 13 * ralpha1);
					ctx.lineTo(8, 38);
					ctx.lineTo(26, 20);
				}
				else if (alpha < 1) {
					ralpha1 = (alpha - 0.359982) * 28.1243; // 28.1243 = 18 * 1.56246

					ctx.moveTo(8 + ralpha1, 38 - ralpha1);
					ctx.lineTo(26, 20);
				}
				else {
					ctx.moveTo(26, 20);
				}

				ctx.lineTo(14 - 10 * alpha, 20);

				// Center line
				if (alpha < 1) {
					ctx.moveTo(11.556 - 7.556 * alpha, 8 + 17 * alpha);
					ctx.lineTo(4, 25);
					ctx.lineTo(14 + 12 * alpha, 25);
				}
				else {
					ctx.moveTo(4, 25);
					ctx.lineTo(26, 25);
				}
			}
			else {
				var alpha3 = alpha * 3;
				var alpha9 = alpha * 9;

				ctx.moveTo(14 - alpha3, 2 - 12 * alpha);
				ctx.lineTo(22, 2 - alpha9);
				ctx.lineTo(12 - 10 * alpha, 20 + alpha3);
				ctx.lineTo(26 + 4 * alpha, 20 - alpha3);
				ctx.lineTo(8 - 14 * alpha, 38 + alpha9);
				ctx.lineTo(14 - 0.5 * alpha, 25 + 0.5 * alpha);
				ctx.lineTo(4 - alpha3, 25 + 5 * alpha);
				ctx.lineTo(11.556 - 2.444 * alpha, 8 - 7.8 * alpha);
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
