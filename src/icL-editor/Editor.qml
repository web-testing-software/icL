import QtQuick 2.0
import icL.Look 1.0
import icL.Editor 1.0
import QtGraphicalEffects 1.0

Item {
	id: editor

	property alias chars: editorIntern.chars
	property alias style: editorIntern.style
	property alias intern: editorIntern

	function updateNow() {
		ln.update()
		editorIntern.update()
	}

	LineNumbers {
		id: ln

		visible: false
		anchors {
			left: editorIntern.left
			top: editorIntern.top
			bottom: editorIntern.bottom
		}

		Component.onCompleted: setEditor(editorIntern)
	}

	EditorOpacityMask {
		id: opacityMask

		visible: false
		anchors.fill: ln

		Component.onCompleted: setEditor(editorIntern)
	}

	EditorInternal {
		id: editorIntern

		lineN: ln
		anchors.fill: parent

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

		Component.onCompleted: forceActiveFocus()
	}

	ShaderEffectSource {
		id: editorSource

		anchors.fill: ln
		live: true

		sourceItem: editorIntern
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

		Component.onCompleted: setEditor(editorIntern)
	}
}
