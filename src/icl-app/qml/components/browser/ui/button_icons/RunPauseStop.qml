import QtQuick 2.0

Base {
	id: root;

	drawColor: alpha < 1
			   ? helper.linearMix(playColor, pauseColor, alpha)
			   : helper.linearMix(pauseColor, stopColor, alpha - 1.0);

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	property color playColor: "#00b850";
	property color pauseColor: "#005cb8";
	property color stopColor: "#b60000";

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

			if (alpha < 1.0) {
				if (alpha < 0.5) {
					if (alpha < 0.25) {
						if (alpha == 0.0) {
							ctx.moveTo(3, 2);
							ctx.lineTo(18, 10);
							ctx.lineTo(3, 18);
							ctx.closePath();
						}
						else {
							ctx.moveTo(3 + 60 * alpha, 18 - 24 * alpha);
							ctx.lineTo(18, 10);
							ctx.lineTo(3, 2);
							ctx.lineTo(3, 18);
							ctx.lineTo(3 + 56 * alpha, 18);
						}
					}
					else {
						var a1 = alpha - 0.25;

						ctx.moveTo(18 - 60 * a1, 10 - 24 * a1);
						ctx.lineTo(3, 2);
						ctx.lineTo(3, 18);
						ctx.lineTo(17, 18);
						ctx.lineTo(17, 18 - 64 * a1);
					}
				}
				else {
					if (alpha < 0.75) {
						var a2 = alpha - 0.5;
						var l_top = 20 * a2;
						var l_bottom = 8 * a2;

						ctx.moveTo(3 + l_top, 2);
						ctx.lineTo(3, 2);
						ctx.lineTo(3, 18);
						ctx.lineTo(10 - l_bottom, 18);

						ctx.moveTo(17 - l_top, 2);
						ctx.lineTo(17, 2);
						ctx.lineTo(17, 18);
						ctx.lineTo(10 + l_bottom, 18);
					}
					else {
						var a3 = (alpha - 0.75) * 64;

						ctx.moveTo(8, 2 + a3);
						ctx.lineTo(8, 2);
						ctx.lineTo(3, 2);
						ctx.lineTo(3, 18);
						ctx.lineTo(8, 18);

						ctx.moveTo(12, 18 - a3);
						ctx.lineTo(12, 18);
						ctx.lineTo(17, 18);
						ctx.lineTo(17, 2);
						ctx.lineTo(12, 2);
					}
				}
			}
			else /* alpha >= 1 */ {
				if (alpha < 1.5) {
					if (alpha == 1.0) {
						ctx.rect(3, 2, 5, 16);
						ctx.rect(12, 2, 5, 16);
					}
					else {
						var b1 = (alpha - 1.0) * 32;

						ctx.moveTo(8, 2 + b1);
						ctx.lineTo(8, 18);
						ctx.lineTo(3, 18);
						ctx.lineTo(3, 2);
						ctx.lineTo(8, 2);

						ctx.moveTo(12, 18 - b1);
						ctx.lineTo(12, 18);
						ctx.lineTo(17, 18);
						ctx.lineTo(17, 2);
						ctx.lineTo(12, 2);s
					}
				}
				else {
					if (alpha < 2.0) {
						var b2 = (alpha - 1.5) * 8;

						ctx.moveTo(8, 2);
						ctx.lineTo(3, 2);
						ctx.lineTo(3, 18);
						ctx.lineTo(8 + b2, 18);

						ctx.moveTo(12 - b2, 2);
						ctx.lineTo(17, 2);
						ctx.lineTo(17, 18);
						ctx.lineTo(12, 18);
					}
					else {
						ctx.rect(3, 2, 16, 18);
					}
				}
			}

			ctx.stroke();

			ctx.restore();
		}
	}
}
