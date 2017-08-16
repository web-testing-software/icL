#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QWidget>

class WebBrowser : public QWidget
{
	Q_OBJECT

public:
	WebBrowser(QWidget *parent = 0);
	~WebBrowser();
};

#endif // WEBBROWSER_H
