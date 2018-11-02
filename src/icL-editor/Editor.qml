import QtQuick 2.0
import icL.Look 1.0
import icL.Editor 1.0
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

		onCharsInLineChanged: console.log("charsInLine", charsInLine)
		onVisbileLinesChanged: console.log("visbileLines", visbileLines)
		onLinesCountChanged: console.log("linesCount", linesCount)

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
	Rectangle {
		id: yScroll

		color: scrollBar.background
		layer.enabled: true

		width: rd(rq * 12)
		anchors {
			top: parent.top
			bottom: parent.bottom
			right: parent.right
		}
//		opacity: 0.65;

		Rectangle {
			id: yScrollBar

			color: scrollBar.bar

			property real lines: intern.linesCount + intern.visbileLines - 1
			property real aPos: intern.firstLineNr / lines
			property real aHeight: intern.linesCount / lines
			property real pHeight: parent.height * aHeight

			onLinesChanged: console.log("lines", lines)
			onAPosChanged: console.log("apos", aPos)
			onAHeightChanged: console.log("aheight", aHeight)
			onPHeightChanged: console.log("pheight", pHeight)

			y: (parent.height - height) * aPos
			height: pHeight > rd(rq * 10) ? pHeight : rd(rq * 10)

			onHeightChanged: console.log(height);
			width: rd(rq * 6)
			radius: width * 0.5

			anchors.horizontalCenter: parent.horizontalCenter
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
