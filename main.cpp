#include "webbrowser.h"
#include <QApplication>
#include <QtWebEngine>

#include "backend/virtualmachine/language/control/singleshot.h"

int main (int argc, char *argv []) {
	QApplication::setAttribute (Qt::AA_EnableHighDpiScaling);

	QApplication a (argc, argv);

	QtWebEngine::initialize ();

	WebBrowser w;

	w.show ();

	int comm = 0x23;
	VM::Language::Control::SingleShot::parse(comm);

	return a.exec ();
}
