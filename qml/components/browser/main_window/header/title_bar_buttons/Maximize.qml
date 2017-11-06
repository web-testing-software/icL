import QtQuick 2.0

import "../../../ui/controls/constants_controls.js" as CONST;

Base {
	id: root;

	property bool is_maximized: web_browser.isMaximized;

	onAlphaChanged: canvas.requestPaint();
	onWidthChanged: canvas.requestPaint();
	onIs_maximizedChanged: canvas.requestPaint();

	onClicked: {
		if (web_browser.isMaximized) {
			web_browser.showNormal();
		}
		else {
			web_browser.showMaximized();
		}
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
			ctx.lineCap = "square"; // butt round square
			ctx.lineJoin = "milter"; // milter bevel round
			ctx.lineWidth = 2;

			ctx.beginPath();

			if (!is_maximized) {
				var step = alpha * 6;
				var steph = alpha * 4;
				var key_y = 12 - step;
				var key_y2 = 12 + 2 * alpha;

				ctx.moveTo(6, key_y);
				ctx.lineTo(10, 8 - 2 * alpha);
				ctx.lineTo(14, key_y);
				ctx.lineTo(14, key_y2);

				if (alpha < 1.0) {
					ctx.lineTo(14 - steph, key_y2);
					ctx.stroke();
					ctx.beginPath();
					ctx.moveTo(6 + steph, key_y2);
					ctx.lineTo(6, key_y2);
					ctx.lineTo(6, key_y);
				}
				else {
					ctx.lineTo(6, key_y2);
					ctx.closePath();
				}
			}
			else {
				var angle = Math.PI * 0.25 * alpha;
				var sin = Math.sin(angle);
				var cos = Math.cos(angle);
				var sin4 = sin * 4;
				var cos4 = cos * 4;

				ctx.moveTo(10 - sin4, 10 + cos4);
				ctx.lineTo(10 + cos4, 10 + sin4);
				ctx.lineTo(10 + sin4, 10 - cos4);
				ctx.lineTo(10 - cos4, 10 - sin4);

				ctx.closePath();

				if (alpha > 0.5) {
					step = (alpha - 0.5) * 6;
					key_y = -8 + step;

					var step_cos = step * cos;
					var step_sin = step * sin;
					var key_y_sin = key_y * sin;
					var key_y_cos = key_y * cos;

					ctx.moveTo(10 + (-step_cos - key_y_sin), 10 + (-step_sin + key_y_cos));
					ctx.lineTo(10 + 8 * sin, 10 - 8 * cos);
					ctx.lineTo(10 + (step_cos - key_y_sin), 10 + (step_sin + key_y_cos));
				}
			}

			ctx.stroke();
			ctx.restore();
		}
	}
}
