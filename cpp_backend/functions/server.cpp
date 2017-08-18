#include "server.h"

#include <QMessageBox>
#include <QPushButton>
#include <QStringList>

Server *Server::m_instance = nullptr;

Server::Server (QObject *parent) : QObject (parent) {
	if (m_instance == nullptr) {
		m_instance = this;
	}

	connect (this, SIGNAL (invoke_executeJS ()), this, SLOT (release_executeJS ()));
	connect (this, SIGNAL (invoke_goTo ()), this, SLOT (release_goTo ()));
	connect (this, SIGNAL (invoke_waitForPageLoading ()), this, SLOT (release_waitForPageLoading ()));
	connect (this, SIGNAL (invoke_showErrorDialog ()), this, SLOT (release_showErrorDialog ()));
}

bool Server::goTo (const QString &url) {
	working		= true;
	this->url	= url;

	emit invoke_goTo ();
	while (working) {
		;
	}
	return boolean;
}

bool Server::waitForPageLoading () {
	working = true;

	emit invoke_waitForPageLoading ();
	while (working) {
		;
	}
	return boolean;
}

QVariant Server::executeJS (const QString &code) {
	working		= true;
	this->code	= code;

	emit invoke_executeJS ();
	while (working) {
		;
	}
	return variant;
}

bool Server::showErrorDialog () {
	working = true;

	emit invoke_showErrorDialog ();
	while (working) {
		;
	}
	return boolean;
}

void Server::addToErrorsStack (const QString &error) {
	errors_stack.append (error);
}

QString Server::getErrorsStr () {
	QString ret = errors_stack.join ('\n');

	errors_stack.clear ();
	return ret;
}

Server * Server::instance () {
	return m_instance;
}

void Server::check_success (bool success, const QString &func) {
	if (success) {
		return;
	}

	if (stop_on_error) {
		worker->setToErrorState ();
		addToErrorsStack ("error detected in " + func);
	}
}




void Server::release_goTo () {
	browser->get (url, [this] (bool success) {
		this->boolean = success;
		this->working = false;
	});
}

void Server::release_waitForPageLoading () {
	browser->waitForPageLoading ( [this] (bool success) {
		this->boolean = success;
		this->working = false;
	});
}
void Server::release_executeJS () {
	browser->runJS (code, [this] (const QVariant &variant) {
		this->variant = variant;
		this->working = false;
	});
}

void Server::release_showErrorDialog () {
	QMessageBox mbox;

	mbox.setWindowTitle ("Error occurer");
	mbox.setText ("Do you want to ignore it?");
	mbox.setInformativeText (getErrorsStr ());
	QPushButton *yesButton = mbox.addButton (QMessageBox::Yes);
	mbox.addButton (QMessageBox::No);
	mbox.show ();
	mbox.exec ();

	boolean = mbox.clickedButton () == yesButton;
	working = false;
}
