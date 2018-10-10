import QtQuick 2.5
import icL.Toolkit 1.0
import icL 1.0

MouseField {
	id: moveResizeArea

	property bool wasMaximised: false
	property point beginXY
	property point winXY
	property size beginSize
	property int lastXPositon
	property int lastWinWidth
	property int flag
	property int copyOfFlag: 0x0

	MouseTrack {
		id: mtrack

		onPositionChanged: move(position)
	}

	onPressed: {
		if (mouse.button == Qt.LeftButton) {
			if (win.isMaximized) {
				wasMaximised = true
				lastXPositon = mapToGlobal(mouseX, 0).x
				lastWinWidth = win.width
				win.showNormal()
			} else {
				wasMaximised = false
			}

			resizeMoveTimer.resizeMoveArea = moveResizeArea
			resizeMoveTimer.start()
		}
	}

	function pressedDelayFunction() {

		beginXY = mtrack.startTracking()

		copyOfFlag = flag
		winXY = Qt.point(win.x, win.y)
		beginSize = Qt.size(win.width, win.height)

		if (wasMaximised) {
			var alpha = lastXPositon > lastWinWidth - width
					/ 2 ? 1 - (lastWinWidth - lastXPositon) / width : lastXPositon
						  < width / 2 ? lastXPositon / width : 0.5

			winXY.x = beginXY.x - win.width * alpha
			winXY.y = beginXY.y - Math.min(beginXY.y, win.height)
		}
	}

	function move(pos) {
		if (copyOfFlag == 0x0) {
			return
		}

		var dx = pos.x - beginXY.x
		var dy = pos.y - beginXY.y
		var newX = winXY.x
		var newY = winXY.y
		var newWidth = beginSize.width
		var newHeight = beginSize.height
		var hResize = (flag & MoveFlags.hResize) != 0
		var vResize = (flag & MoveFlags.vResize) != 0
		var hMove = (flag & MoveFlags.hMove) != 0
		var vMove = (flag & MoveFlags.vMove) != 0

		if (hResize) {
			newWidth += hMove ? -dx : dx
			if (newWidth < win.minimumWidth) {
				newWidth = win.minimumWidth
			}
		}

		if (vResize) {
			newHeight += vMove ? -dy : dy
			if (newHeight < win.minimumHeight) {
				newHeight = win.minimumHeight
			}
		}

		if (hMove) {
			newX += hResize ? beginSize.width - newWidth : dx
		}

		if (vMove) {
			newY += vResize ? beginSize.height - newHeight : dy
		}

		win.x = newX
		win.y = newY
		win.width = newWidth
		win.height = newHeight
	}

	onReleased: {
		if (resizeMoveTimer.running) {
			move(mtrack.stopTracking());
			resizeMoveTimer.stop()
		}

		copyOfFlag = 0x0
	}
}
