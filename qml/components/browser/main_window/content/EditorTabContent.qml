import QtQuick 2.0
import QtWebEngine 1.2
import QtGraphicalEffects 1.0

Rectangle {
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
			name: "inactive"
			PropertyChanges {
				target: wview;
				visible: false;
			}
			PropertyChanges {
				target: copy;
				live: false;
			}
		}
		// focusedout
		// vm_error
		// wainting
		// dialog
	]

	WebEngineView {
		id: wview;
		anchors.fill: parent;

//		url: "about:blank";
		url: "https://yandex.ru/";

//		settings.autoLoadImages: false;
		settings.javascriptCanOpenWindows: false;
		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

		Keys.forwardTo: [active_area];

//		onJavaScriptConsoleMessage: {
//			console.log(level, message, lineNumber, sourceID);
//		}

		userScripts: [
			WebEngineScript {
				injectionPoint: WebEngineScript.DocumentCreation;
				name: "browser.js";
				sourceUrl: "qrc:/components/browser/main_window/content/browser.js";
				worldId: WebEngineScript.MainWorld;
			}
		]
	}

	ShaderEffectSource {
		id: copy;
		mipmap: false;
		recursive: false;
		sourceItem: wview;
		anchors.fill: wview;
		wrapMode: ShaderEffectSource.Repeat;
	}

	// Focus Out
//	Desaturate {
//		anchors.fill: copy;
//		source: copy;
//		desaturation: 1.0;
//	}

	// VM Error
//	Colorize {
//		anchors.fill: copy;
//		source: copy;
//		hue: 0.0;
//		saturation: 0.5;
//		lightness: 0.2; // -0.2 for dark theme
//	}

	// Wainting state
//	HueSaturation {
//		anchors.fill: copy;
//		source: copy;
//		hue: -0.3;
//		saturation: 0.0;
//		lightness: 0.2;
//	}

	// Dialog
//	FastBlur {
//		anchors.fill: copy;
//		source: copy;
//		radius: 32;
//	}
}
