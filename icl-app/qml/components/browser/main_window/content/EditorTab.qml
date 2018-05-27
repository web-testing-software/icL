import QtQuick 2.0
import QtWebEngine 1.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "../../ui/controls/speed_dial" as SpeedDialControls;
import "../../ui/button_icons" as ButtonIcons;

ContentBase {
	id: root;
	anchors.fill: parent;

	state: "active";

	states: [
		State {
			name: "active"
			PropertyChanges {
				target: wview;
				visible: true;
			}
			PropertyChanges {
				target: copy;
				live: true;
			}
		},
		State {
			name: "unfocused"
			PropertyChanges {
				target: wview;
				visible: false;
			}
			PropertyChanges {
				target: copy;
				live: false;
			}
		}
	]

	// ContentBase interface

	function focus_me () {
		state = "active";
		wview.forceActiveFocus();
	}

	function unfocus_me () {
		state = "unfocused";
	}

	function activate_me () {
		// TODO: Write this function
	}

	function deactivate_me () {
		// TODO: Write this function
	}

	// ContentBase interface end

	WebEngineView {
		id: wview;
		anchors {
			left: parent.left;
			top: parent.top;
			right: side.left;
			bottom: parent.bottom;
		}

		backgroundColor: "white";
		url: "about:blank";

//		settings.autoLoadImages: false;
		settings.javascriptCanOpenWindows: false;
		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

		Keys.forwardTo: [win_rectangle];

//		onJavaScriptConsoleMessage: {
//			console.log(level, message, lineNumber, sourceID);
//		}

		userScripts: [
			WebEngineScript {
				injectionPoint: WebEngineScript.DocumentCreation;
				name: "web_nm.js";
				sourceUrl: "qrc:/scripts/web_nm.js";
				worldId: WebEngineScript.MainWorld;
			}
		]
	}

	Item {
		id: side;

		anchors {
			top: parent.top;
			right: parent.right;
			bottom: parent.bottom;
		}
		width: 400;

		Rectangle {
			id: border;
			anchors {
				top: parent.top;
				bottom: parent.bottom;
				left: parent.left;
			}
			width: 2 * _ratio;
			color: border_color;
		}

		Rectangle {
			id: header;
			anchors.top: parent.top;
			anchors.left: border.right;
			anchors.right: parent.right;
			height: Math.round(40 * _ratio);

			color: "#f1f1f2";

			SpeedDialControls.New {
				id: new_button;

				anchors.left: parent.left;
				anchors.leftMargin: 10 * _ratio;
			}

			SpeedDialControls.Open {
				id: open_button;

				anchors.left: new_button.right;
			}

			Text {
				id: text_item;
				anchors.left: open_button.right;
				anchors.leftMargin: Math.round(6 * _ratio);
				anchors.right: parent.right;
				anchors.top: parent.top;
				anchors.bottom: parent.bottom;
				font.pixelSize: Math.round(18.5 * _ratio);
				font.family: "Ubuntu";
				verticalAlignment: Text.AlignVCenter;
				color: "#3e3e3e";
				elide: Text.ElideRight;

				text: "Untilited*";
			}
		}

		Item {
			anchors {
				top: header.bottom;
				left: border.right;
				right: parent.right;
				bottom: console_block.top;
			}


			Rectangle {
				anchors.left: parent.left;
				anchors.right: parent.right;

				y:  editor.cursorRectangle.y - editor.flickableItem.contentY;
				height: editor.cursorRectangle.height;

				color: "#e3eef9";
			}

			TextArea {
				id: editor;
				anchors.fill: parent;

				wrapMode: TextEdit.NoWrap;

				style: TextAreaStyle {
					decrementControl: null
					incrementControl: null
					frame: null;
					corner: null;
					handle: Item {
						implicitWidth: 20 * _ratio;
						implicitHeight: 20 * _ratio;

						Rectangle {
							anchors.fill: parent;
							anchors.margins: 5 * _ratio;
							radius: 10 * _ratio;

							color: styleData.pressed
								   ? focus_color
								   : styleData.hovered
									 ? "#3e3e3f"
									 : "#808081";

							Behavior on color {
								ColorAnimation {
									duration: 200 * anim_time_multiplier
								}
							}
						}
					}

					scrollBarBackground: Item {
						implicitWidth: 20 * _ratio;
						implicitHeight: 20 * _ratio;
					}
				}

				frameVisible: false;
				backgroundVisible: false;
				textFormat: TextEdit.PlainText;
				font.family: "monospace";
				font.pixelSize: Math.round(18 * _ratio);

				Keys.onTabPressed: {
					insert(cursorPosition, '\t');
					return true;
				}

				Component.onCompleted: {
					helper.setTabsize(font.pixelSize, textDocument);
				}
			}
		}

		Item {
			id: console_block;

			anchors {
				left: border.right;
				right: parent.right;
				bottom: parent.bottom;
			}
			height: 200 * _ratio;

			Rectangle {
				id: console_header;
				anchors.top: parent.top;
				anchors.left: parent.left;
				anchors.right: parent.right;
				height: Math.round(40 * _ratio);

				color: "#f1f1f2";

				Row {
					height: Math.round(40 * _ratio);
					spacing: 10 * _ratio;
					x: 10 * _ratio;

					SpeedDialControls.TextButton {
						text: qsTr("Into");
						icon_item: s_into;

						ButtonIcons.StepInto {
							id: s_into
							alpha: parent.alpha;
							anchors.left: parent.left;
						}
					}

					SpeedDialControls.TextButton {
						text: qsTr("Over");
						icon_item:  s_over;

						ButtonIcons.StepOver {
							id: s_over
							alpha: parent.alpha;
							anchors.left: parent.left;
						}
					}

					SpeedDialControls.TextButton {
						text: qsTr("Out");
						icon_item:  s_out;

						ButtonIcons.StepOut {
							id: s_out
							alpha: parent.alpha;
							anchors.left: parent.left;
						}
					}

					SpeedDialControls.TextButton {
						text: qsTr("Run");
						icon_item: s_rsp;

						ButtonIcons.RunPauseStop {
							id: s_rsp
							alpha: parent.alpha;
							anchors.left: parent.left;
						}
					}
				}
			}

		}

	}

	ShaderEffectSource {
		id: copy;
		live: false;
		mipmap: false;
		recursive: false;
		sourceItem: wview;
		anchors.fill: wview;
		wrapMode: ShaderEffectSource.Repeat;
	}
}
