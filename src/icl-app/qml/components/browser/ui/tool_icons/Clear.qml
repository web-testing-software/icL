import QtQuick 2.0

Hover {
	id: root;
	primaryColor: "#bbbbbb";
	secondaryColor: "#5b5b5b";
	drawColor: clean ? helper.mix(primaryColor, secondaryColor, alpha)
					 : secondaryColor;

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	property bool clean: false;

	onClicked: {
		clean = true;
		hoverEnabled = false;
		alpha = 0.0;
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

			ctx.beginPath();

			ctx.moveTo(7.036, 4.651);
			ctx.lineTo(7.036, 3.313);
			ctx.bezierCurveTo(7.036, 2.5,
							  7.619, 1.841,
							  8.508, 1.841);
			ctx.lineTo(11.552, 1.841);
			ctx.bezierCurveTo(12.367, 1.841,
							  13.024, 2.5,
							  13.024, 3.313);
			ctx.lineTo(13.024, 4.651);

			ctx.moveTo(3.939, 4.651);
			ctx.lineTo(4.842, 17.627);
			ctx.quadraticCurveTo(4.842, 18.156,
								 5.234, 18.156);
			ctx.lineTo(14.621, 18.156);
			ctx.quadraticCurveTo(15.617, 18.156,
								 15.617, 17.025);
			ctx.lineTo(15.982, 4.651);

			ctx.stroke();

			ctx.lineCap = "round"; // butt round square
			ctx.beginPath();

			ctx.moveTo(2.852, 4.677);
			ctx.lineTo(17.148, 4.677);

			var h1, h2;

			if (!clean) {
				if (!reversed) {
					if (alpha < 0.5) {
						h1 = 2 + alpha * 10;
						h2 = 2;
					}
					else if (alpha ) {
						h1 = 7;
						h2 = 2 + 10 * (alpha - 0.5);
					}
				}
				else {
					if (alpha < 0.5) {
						h1 = 2;
						h2 = 2 + alpha * 10;
					}
					else {
						h1 = 2 + 10 * (alpha - 0.5);
						h2 = 7;
					}
				}
			}
			else {
				h1 = h2 = alpha * 7;
			}

			if (h1 !== 0.0) {
				ctx.moveTo(8.127, 17.59);
				ctx.lineTo(8.127, 17.59 - h1);

				ctx.moveTo(11.883, 17.59);
				ctx.lineTo(11.883, 17.59 - h2);
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
