#include "webbrowser.h"
#include <QApplication>
#include <QtWebEngine>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtWebEngine::initialize();
	WebBrowser w;
	w.show();

	return a.exec();
}
