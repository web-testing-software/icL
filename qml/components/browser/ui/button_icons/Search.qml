import QtQuick 2.0

import "../tool_icons/constants.js" as CONST;

Base {
	id: root;

	drawColor: helper.mix(primary_color, focus_color, alpha);

	onAlphaChanged: canvas.requestPaint();
	onBetaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();
	onHeightChanged: canvas.requestPaint();

	property color primary_color: "#e3e3e3";
	property real beta: mouse_area.containsMouse ? 1.0 : 0.0;

	MouseArea {
		id: mouse_area;
		anchors.fill: parent;
		propagateComposedEvents: true;
	}

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
			ctx.beginPath();
			ctx.moveTo(14 - beta, 9 );
			ctx.arc(9, 9, 5 - beta, 0, CONST.PI_2);
			ctx.fill();

			ctx.restore();
		}
	}
}
