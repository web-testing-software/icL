import QtQuick 2.0
import QtWebEngine 1.5

Item {
	id: root;

	anchors.fill: parent;

	WebEngineView {
		id: wview;
		anchors.fill: parent;
		//			anchors.topMargin: 50;

//		url: "about:blank";
		url: "https://gitlab.com/";

		settings.autoLoadImages: false;
		settings.javascriptCanOpenWindows: false;
		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

//		onTitleChanged: console.log("Title changed:" + title);

//		onIconChanged: console.log(icon);
//		Component.onCompleted: console.log(icon);
	}
}
