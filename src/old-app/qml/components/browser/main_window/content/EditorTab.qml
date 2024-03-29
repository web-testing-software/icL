import QtQuick 2.0
import QtWebEngine 1.3
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "../../ui/controls/speed_dial" as SpeedDialControls;
import "../../ui/button_icons" as ButtonIcons;
import "../header";

import icL.VM 1.0
import icL.Enums 1.0

ContentBase {
	id: root;
	anchors.fill: parent;

	property alias wview: wview;
	property NavigationBar navBar;

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

	property var colors: ["#b60000", "#005cb8",  "#00b850"];

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

//		zoomFactor: 1.5;
//		contentsSize: Qt.size(width / 1.5, height / 1.5);

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

		onLoadingChanged: {
			/*if (loadRequest.status == WebEngineLoadRequest.LoadSucceededStatus) {
				server.finish_PageLoading(true);
			}
			else */if (loadRequest.status == WebEngineLoadRequest.LoadFailedStatus) {
				server.finish_PageLoading(false);
			}
			navBar.setLoading(loading)
		}

		onJavaScriptConsoleMessage: {
			//JavaScriptConsoleMessageLevel level, string message, int lineNumber, string sourceID
			if (sourceID == "userscript:web_nm.js" && message == "DOM_Ready") {
				server.finish_PageLoading(true);
				console.log("loaded");
			}
//			else {
//				console.log(sourceID + message);
//			}
		}

		onUrlChanged: if (!!url) navBar.setUrl(url);
		onCanGoBackChanged: navBar.setBack(canGoBack);
		onCanGoForwardChanged: navBar.setForward(canGoForward);
	}

	Server {
		id: server;

		webEngine: wview;

		function printCodeRes(res) {

			if (typeof res == "object") {
				var ret = "{ ";
				for (var prop in res) {
					ret += prop + ":" + res[prop] + " ";
				}
				console.log(" <- " + ret + "}");
			}
			else {
				console.log(" <- " + res);
			}
		}

		onRequest_JsRun: {
			console.log(" -> " + code);

			wview.runJavaScript(code, function(result){
//				console.log("executed");

				if (typeof result == "object" && typeof result.x == "number") {
					result = Qt.point(result.x, result.y);
				}

				printCodeRes(result);
				finish_executeJS(result);
			});
		}

		onRequest_LogOut: {
			console_model.append({mlevel: level, message: mess});
			console_list.incrementCurrentIndex();
		}

		onRequest_UrlLoad: {
			if (wview.url == url) {
				wview.reload();
			}
			else {
				wview.url = helper.urlFromUserInput(url);
			}
		}
	}

	VMStack {
		id: vmstack;


		server: server;

		onRequest_Highlight: {
			editor.select(pos1, pos2);
		}
	}

	Item {
		id: side;

		anchors {
			top: parent.top;
			right: parent.right;
			bottom: parent.bottom;
		}
		width: 400 * _ratio;

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
			clip: true;


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

				property bool edited: true;

				style: TextAreaStyle {
					decrementControl: null
					incrementControl: null
					frame: null;
					corner: null;

					selectionColor: vmstack.sColor;
					selectedTextColor: "black";

					Behavior on selectionColor {
						ColorAnimation {
							duration: 250
						}
					}

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

				Keys.onAsteriskPressed: {
					vmstack.init(text, edited);
					vmstack.step(StepType.Any);
				}

				Keys.onPressed: {
					var ret = true;

					switch (event.key) {
					case Qt.Key_F8:
						vmstack.init(text, edited);
						vmstack.step(StepType.Any);
						break;

					case Qt.Key_F9:
						vmstack.init(text, edited);
						vmstack.step(StepType.CommandInto);
						break;

					case Qt.Key_F10:
						vmstack.init(text, edited);
						vmstack.step(StepType.CommandEnd);
						break;

					case Qt.Key_F11:
						vmstack.init(text, edited);
						vmstack.step(StepType.CommandOut);
						break;

					case Qt.Key_F12:
						vmstack.init(text, edited);
						vmstack.step(StepType.None);
						break;

					default:
						ret = false;
					}

					return ret;
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
							alpha: vmstack.running ? 1.0 : 0.0;
							anchors.left: parent.left;

							Behavior on alpha {
								NumberAnimation {
									duration: 200 * anim_time_multiplier;
								}
							}
						}
					}
				}
			}

			ListModel {
				id: console_model;

				ListElement {
					mlevel: 0;
					message: "Wellcome to icL!";
				}
			}

			ListView {
				id: console_list;

				model: console_model;
				clip: true;

				anchors {
					top: console_header.bottom;
					left: parent.left;
					right: parent.right;
					bottom: parent.bottom;
				}

				delegate: Text {
					textFormat: TextEdit.PlainText;
					font.family: "monospace";
					font.pixelSize: Math.round(18 * _ratio);

					anchors.left: parent.left;
					anchors.right: parent.right;
					anchors.margins: Math.round(5 * _ratio);

					color: colors[mlevel];
					text: message;
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
