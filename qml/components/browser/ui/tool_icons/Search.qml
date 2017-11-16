import QtQuick 2.0

import "constants.js" as CONST;

Base {
	id: root;
	primaryColor: "#3e3e3e";

	alpha: containsMouse ? 2.0 : 0.0;
	drawColor: alpha < 1.0 ? helper.mix(primaryColor, hoverColor, alpha) : hoverColor;

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
			ctx.fillStyle = drawColor;
			ctx.strokeStyle = drawColor; //root.drawColor;
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.beginPath();
			ctx.moveTo(16, 8);
			ctx.arc(9, 9, 7, 0, CONST.PI_2);
			ctx.fill();

			ctx.beginPath();
			ctx.moveTo(14, 14);
			ctx.lineTo(18, 18);
			ctx.stroke();
			
			ctx.fillStyle = "#ffffff";
			
			if (alpha <= 1.0) {
				ctx.beginPath();
				ctx.moveTo(14, 9);
				ctx.arc(9, 9, 5, 0, CONST.PI_2);
			}
			else {
				var step = alpha - 1;

				ctx.beginPath();
				ctx.moveTo(14 - step, 9 );
				ctx.arc(9, 9, 5 - step, 0, CONST.PI_2);
			}

			ctx.fill();
			ctx.restore();
		}
	}
}
