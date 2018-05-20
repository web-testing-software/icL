import QtQuick 2.0

import "constants.js" as CONST;

Base {
	id: root;

	alpha: reversed ? 1.0 : (containsMouse ? -0.01 : 0.0);

	primaryColor: "#5b5b5b";
	secondaryColor: "#b60000";
	drawColor: alpha < 0
			   ? helper.mix(primaryColor, hoverColor, -alpha * 100)
			   : helper.mix(primaryColor, secondaryColor, alpha);

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

			if (alpha < 1) {
				var angle_step = CONST.PI_08 * alpha * alpha;
				var begin_angle = CONST.PI_B + angle_step;

				ctx.moveTo(10 + CONST.R * Math.cos(begin_angle), 10 +
						   CONST.R * Math.sin(begin_angle));
				ctx.arc(10, 10, CONST.R, begin_angle, CONST.PI_175, false);

				if (alpha < 0.5) {
					var delta = (CONST.R_2 - CONST.R_2 * alpha * 2) *
							CONST.SIN_COS_PI2;
					var tx_by = 10 + delta; // Top - x, bottom - y
					var ty_bx = 10 - delta; // Top - y, bottom - x

					ctx.lineTo(tx_by, ty_bx);
					ctx.moveTo(ty_bx, tx_by);
				}

				ctx.arc(10, 10, CONST.R, CONST.PI_075, CONST.PI_E +
						angle_step, true);

				if (alpha > 0.5) {
					delta = (alpha - 0.5) * CONST.D * CONST.SIN_COS_PI2;
					var txy = 10 - delta; // Top - x, y
					var bxy = 10 + delta; // Bottom - x, y

					ctx.moveTo(txy, txy);
					ctx.lineTo(bxy, bxy);
				}
			}
			else {
				ctx.moveTo(4.343, 4.343);
				ctx.lineTo(15.657, 15.657);
				ctx.moveTo(15.657, 4.343);
				ctx.lineTo(4.343, 15.657);
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
