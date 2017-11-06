import QtQuick 2.0

import "constants.js" as CONST;

Base {
	id: root;
	primaryColor: "#5b5b5b";
	secondaryColor: "#b60000";
	hoverColor: "#5b5b5b";

	alpha: reversed ? 2.0 : (containsMouse ? 1.0 : 0.0);

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();

	onClicked: reversed = true;

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

			if (alpha <= 1) {
				var center_step = 2 * alpha * CONST.SIN_COS_PI2;
				var ten_minus = 10 - center_step;
				var ten_plus = 10 + center_step;

				ctx.moveTo(4.343, 4.343);
				ctx.lineTo(ten_minus, ten_minus);

				ctx.moveTo(15.656, 4.343);
				ctx.lineTo(ten_plus, ten_minus);

				ctx.moveTo(15.656, 15.656);
				ctx.lineTo(ten_plus, ten_plus);

				ctx.moveTo(4.343, 15.656);
				ctx.lineTo(ten_minus, ten_plus);
			}
			else {
				var radian_step = (alpha - 1) * CONST.PI_O5;
				center_step = (2 + ((alpha - 1) * 4)) * CONST.SIN_COS_PI2;
				ten_minus = 10 - center_step;
				ten_plus = 10 + center_step;

				ctx.moveTo(ten_minus, ten_minus);
				ctx.arc(10, 10, 8, CONST.PI_125, CONST.PI_125 + radian_step);

				ctx.moveTo(ten_plus, ten_minus);
				ctx.arc(10, 10, 8, CONST.PI_175, CONST.PI_175 + radian_step);

				ctx.moveTo(ten_plus, ten_plus);
				ctx.arc(10, 10, 8, CONST.PI_025, CONST.PI_025 + radian_step);

				ctx.moveTo(ten_minus, ten_plus);
				ctx.arc(10, 10, 8, CONST.PI_075, CONST.PI_075 + radian_step);
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
