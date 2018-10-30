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
		ln.update();
		editorIntern.update();
	}

	LineNumbers {
		id: ln

		editor: editorIntern

		anchors {
			left: editorIntern.left
			top: editorIntern.top
			bottom: editorIntern.bottom
		}
		visible: false
		z: -2
	}

	EditorOpacityMask {
		id: opacityMask

		editor: editorIntern

		anchors.fill: ln
		visible: false
		z: -1
	}

	EditorInternal {
		id: editorIntern

		lineN: ln
		anchors.fill: parent

		onRequestRepaint: {
			update();
			opacityMask.update();
			ln.update();
		}

		Component.onCompleted: forceActiveFocus();
	}

	ShaderEffectSource {
		id: editorSource

		anchors.fill: ln
		live: true

		sourceItem: editorIntern
		sourceRect: Qt.rect(0, 0, width, height);
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
}
