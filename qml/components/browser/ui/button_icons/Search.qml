import QtQuick 2.0

import "../tool_icons/constants.js" as CONST;

Base {
	id: root;

	drawColor: helper.mix(primary_color, focus_color, alpha);

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
			ctx.strokeStyle = drawColor; //root.drawColor;
			ctx.lineCap = "butt"; // butt round square
			ctx.lineJoin = "bevel"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.beginPath();

			ctx.moveTo(15, 9);
			ctx.arc(9, 9, 6, 0, CONST.PI_2);

			ctx.moveTo(14, 14);
			ctx.lineTo(18, 18);

			ctx.stroke();

			ctx.restore();
		}
	}
}
