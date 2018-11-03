import QtQuick 2.0
import icL.Look 1.0
import icL.Editor 1.0
import icL.Toolkit 1.0
import QtGraphicalEffects 1.0

Item {
	id: editor

	property alias chars: intern.chars
	property alias style: intern.style
	property alias scrollBar: intern.scrollBar
	property alias intern: intern

	function updateNow() {
		ln.update()
		intern.update()
	}

	// C++ classes realization
	LineNumbers {
		id: ln

		visible: false
		anchors {
			left: intern.left
			top: intern.top
			bottom: intern.bottom
		}

		Component.onCompleted: setEditor(intern)
	}

	EditorOpacityMask {
		id: opacityMask

		visible: false
		anchors.fill: ln

		Component.onCompleted: setEditor(intern)
	}

	EditorInternal {
		id: intern

		lineN: ln
		anchors.fill: parent

		charsInLine: (width - ln.width - yScroll.width) / style.charW
		visbileLines: (height) / (style.charH + style.lineS)

		onActiveFocusChanged: {
			if (activeFocus) {
				cursors.update()
			}
		}

		onRequestRepaint: {
			// Don't change this order
			// That will case drawing artefacts
			update()
			opacityMask.update()
			ln.update()
		}

		onMakeCursorOpaque: {
			cursors.makeCursorsOpaque()
		}

		Component.onCompleted: forceActiveFocus()
	}

	// Scroll bars design
	Item {
		id: yScrollContainer

		width: rd(rq * 12)
		anchors {
			top: parent.top
			bottom: parent.bottom
			right: parent.right
		}

		ShaderEffectSource {
			id: yScrollBackground

			anchors.fill: yScrollContainer
			sourceItem: intern
			sourceRect: Qt.rect(yScrollContainer.x, 0, width, height)
			visible: false
		}

		FastBlur {
			id: yScrollBlur

			anchors.fill: yScrollContainer
			source: yScrollBackground
			radius: rd(rq * 28)
		}

		Rectangle {
			id: yScroll

			anchors.fill: parent
			color: scrollBar.background
			layer.enabled: true

			opacity: 0.65

			MouseArea {
				id: yScrollArea

				anchors.fill: parent

				onClicked: {
					if (mouseY < yScrollBar.y) {
						intern.scrollY(yScrollBar.aPos - yScrollBar.aHeight)
					} else {
						intern.scrollY(yScrollBar.aPos + yScrollBar.aHeight)
					}
				}
			}

			Rectangle {
				id: yScrollBar

				color: scrollBar.bar

				property real lines: intern.linesCount - 1
				property real aPos: (intern.firstLineNr - 1) / lines
				property real aHeight: intern.visbileLines / lines
				property real pHeight: parent.height * aHeight

				y: (parent.height - height - rd(rq * 6)) * aPos + rd(rq * 3)
				height: pHeight > rd(rq * 10) ? pHeight : rd(rq * 10)

				width: rd(rq * 6)
				radius: width * 0.5

				anchors.horizontalCenter: parent.horizontalCenter

				MouseArea {
					id: yBarArea
					anchors.fill: parent

					property real beginAlpha: 0
					property int beginY: 0
					property real beginPos: 0

					MouseTrack {
						id: ytrack
						onPositionChanged: yBarArea.move(position)
					}

					function move(pos) {
						var newY = beginPos - beginY + pos.y
						var alpha = (newY - rd(
										 rq * 3)) / (yScroll.height - height - rd(
														 rq * 6))

						intern.scrollY(alpha)
					}

					onPressed: {
						beginPos = yScrollBar.y
						beginY = ytrack.startTracking().y
					}

					onReleased: move(ytrack.stopTracking())
				}
			}
		}
	}

	Item {
		id: xScrollContainer

		height: rd(rq * 12)
		anchors {
			bottom: parent.bottom
			right: yScrollContainer.left
			left: parent.left
			leftMargin: intern.lnWidth
		}

		ShaderEffectSource {
			id: xScrollBackground

			anchors.fill: xScrollContainer
			sourceItem: intern
			sourceRect: Qt.rect(xScrollContainer.x, xScrollContainer.y,
								width, height)
			visible: false
		}

		FastBlur {
			id: xScrollBlur

			anchors.fill: xScrollContainer
			source: xScrollBackground
			radius: rd(rq * 28)
		}

		Rectangle {
			id: xScroll

			anchors.fill: parent
			color: scrollBar.background
			layer.enabled: true

			opacity: 0.65

			MouseArea {
				id: xScrollArea

				anchors.fill: parent

				onClicked: {
					if (mouseX < xScrollBar.x) {
						intern.scrollX(xScrollBar.aPos - xScrollBar.aWidth)
					} else {
						intern.scrollX(xScrollBar.aPos + xScrollBar.aWidth)
					}
				}
			}

			Rectangle {
				id: xScrollBar

				color: scrollBar.bar

				property real chars: 160 - intern.charsInLine
				property real aPos: intern.firstCharNr / chars
				property real aWidth: intern.charsInLine / chars
				property real pWidth: parent.width * aWidth

				x: (parent.width - width - rd(
						rq * 6) - style.charH / 2) * aPos + rd(
					   rq * 3) + style.charH / 2
				width: pWidth > rd(rq * 10) ? pWidth : rd(rq * 10)

				height: rd(rq * 6)
				radius: height * 0.5

				anchors.verticalCenter: parent.verticalCenter

				MouseArea {
					id: xBarArea
					anchors.fill: parent

					property real beginAlpha: 0
					property int beginX: 0
					property real beginPos: 0

					MouseTrack {
						id: xtrack
						onPositionChanged: xBarArea.move(position)
					}

					function move(pos) {
						var newX = beginPos - beginX + pos.x
						var alpha = (newX - rd(rq * 3) - style.charH / 2)
								/ (xScroll.width - width - rd(
									   rq * 6) - style.charH / 2)

						intern.scrollX(alpha)
					}

					onPressed: {
						beginPos = xScrollBar.x
						beginX = xtrack.startTracking().x
					}

					onReleased: move(xtrack.stopTracking())
				}
			}
		}
	}

	// Lines numbers area design
	ShaderEffectSource {
		id: editorSource

		anchors.fill: ln
		live: true

		sourceItem: intern
		sourceRect: Qt.rect(0, 0, width, height)
		visible: false
	}

	FastBlur {
		id: editorBlurred

		source: editorSource
		cached: true
		radius: rd(rq * 28)

		anchors.fill: editorSource
		visible: false
	}

	OpacityMask {
		id: blurOpacityMask

		maskSource: opacityMask
		source: editorBlurred

		anchors.fill: ln
	}

	ShaderEffectSource {
		id: lnSource

		sourceItem: ln
		anchors.fill: ln
		live: true
	}

	// Cursors drawing over all content
	CursorsArea {
		id: cursors

		clip: true
		cursorW: rd(rq * 2)

		anchors {
			top: parent.top
			left: ln.right
			leftMargin: -cursorW / 2
			right: parent.right
			bottom: parent.bottom
		}

		Component.onCompleted: setEditor(intern)
	}
}
