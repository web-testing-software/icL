import QtQuick 2.0
import QtWebEngine 1.2

Rectangle {
	id: root;

	anchors.fill: parent;

	WebEngineView {
		id: wview;
		anchors.fill: parent;

//		url: "about:blank";
		url: "https://yandex.ru/";

//		settings.autoLoadImages: false;
		settings.javascriptCanOpenWindows: false;
		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

//		onTitleChanged: console.log("Title changed:" + title);

//		onIconChanged: console.log(icon);
//		Component.onCompleted: console.log(icon);
	}

	Keys.forwardTo: [active_area];
}
