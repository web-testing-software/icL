import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
	id: root;
	width: 300;
	height: 400;

	property var content: null;
	property real center_x: 0;
	property real center_y: 0;
	property real max_radius: 0;
	property real progress: 0;
	visible: progress !== 0;

	function fixCenterTo(x0, y0) {
		var x1 = width - x0;
		var y1 = height - y0;
		var dis0 = Math.sqrt(x0 * x0 + y0 * y0);
		var dis1 = Math.sqrt(x1 * x1 + y0 * y0);
		var dis2 = Math.sqrt(x0 * x0 + y1 * y1);
		var dis3 = Math.sqrt(x1 * x1 + y1 * y1);

		center_x = x0;
		center_y = y0;
		max_radius = Math.max(Math.max(dis0, dis1), Math.max(dis2, dis3));
	}

	function show (_x, y) {
		fixCenterTo(_x, y);
		progress = 1;
	}

	Behavior on progress {
		NumberAnimation {
			duration: max_radius * anim_time_multiplier;
		}
	}

	onProgressChanged: {
		canvas_mask.requestPaint ();
		if (progress == 0) parent.requestRemove (this);
	}

	Canvas {
		id: canvas_mask;
		anchors.fill: parent;
		layer.enabled: true;

		onPaint: {
			var ctx = getContext("2d");
			var radius = max_radius * progress;

			ctx.clearRect(0, 0, root.width, root.height);

			ctx.fillStyle = "rgba(255, 255, 255, 0.5)";
			ctx.beginPath();
			ctx.arc(center_x, center_y, radius, 0, 2*Math.PI);
			ctx.fill();


			ctx.fillStyle = "rgba(255, 255, 255, 1)";
			ctx.beginPath();
			ctx.arc(center_x, center_y, radius * progress, 0, 2*Math.PI);
			ctx.fill();
		}

		visible: false;
	}

	OpacityMask {
		id: opacity_mask;
		anchors.fill: parent;
		source: content;
		maskSource: canvas_mask;
		visible: progress != 1.0;
	}
}
