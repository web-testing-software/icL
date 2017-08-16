import QtQuick 2.0
import QtWebEngine 1.5

Item {

	WebEngineView {
		anchors.fill: parent;
		anchors.topMargin: 50;

		url: "http://disk.yandex.ru";

		settings.autoLoadImages: false;
		settings.javascriptCanOpenWindows: false;
		profile.persistentCookiesPolicy: WebEngineProfile.NoPersistentCookies;

		onTitleChanged: console.log("Title changed:" + title);
	}
}
