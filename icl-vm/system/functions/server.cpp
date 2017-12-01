#include "../../parser.h"
//#include "../main/virtualmachine.h"
#include "server.h"

#include <QStringList>

vm::main::Server::Server (QObject *parent) : QObject (parent) {

	connect (this, SIGNAL (invoke_executeJS ()), this, SLOT (release_executeJS ()));
	connect (this, SIGNAL (invoke_goTo ()), this, SLOT (release_goTo ()));
	connect (this, SIGNAL (invoke_waitForPageLoading ()), this, SLOT (release_waitForPageLoading ()));
	connect (this, SIGNAL (invoke_showErrorDialog ()), this, SLOT (release_showErrorDialog ()));
}

bool vm::main::Server::goTo (const QString &url) {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor		= WaitFor::GoTo;
	working		= true;
	this->url	= url;

	emit invoke_goTo ();
	while (working) {
		;
	}
	return boolean;
}

bool vm::main::Server::waitForPageLoading () {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor = WaitFor::PageLoading;
	working = true;

	emit invoke_waitForPageLoading ();
	while (working) {
		;
	}
	return boolean;
}

QVariant vm::main::Server::executeJS (const QString &code) {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor		= WaitFor::ExecuteJS;
	working		= true;
	this->code	= code;

	emit invoke_executeJS ();
	while (working) {
		;
	}
	return variant;
}

bool vm::main::Server::showErrorDialog () {
	if (waitFor != WaitFor::Nothing) {
		return false;
	}

	waitFor = WaitFor::ErrorDialog;
	working = true;

	emit invoke_showErrorDialog ();
	while (working) {
		;
	}
	return boolean;
}

void vm::main::Server::addToErrorsStack (const QString &error) {
	errors_stack.append (error);
}

QString vm::main::Server::getErrorsStr () {
	QString ret = errors_stack.join ('\n');

	errors_stack.clear ();
	return ret;
}

void vm::main::Server::check_success (bool success, const QString &func) {
	if (success) {
		return;
	}

	if (stop_on_error) {
//		if (virtualMachine != nullptr) {
//			drive.setError (vm::Error::SERVER_ERROR);
//		}
//		else {
//			worker->setToErrorState ();
//		}
		addToErrorsStack ("error detected in " + func);
	}
}

void vm::main::Server::finish_PageLoading (bool success) {
	if (waitFor == WaitFor::GoTo || waitFor == WaitFor::PageLoading) {
		boolean = success;
		waitFor = WaitFor::Nothing;
		working = false;
	}
}

void vm::main::Server::finish_executeJS (QVariant variant) {
	if (waitFor == WaitFor::ExecuteJS) {
		this->variant	= variant;
		this->waitFor	= WaitFor::Nothing;
		this->working	= false;
	}
}

void vm::main::Server::finish_showErrorDialog (bool skip) {
	if (waitFor == WaitFor::ErrorDialog) {
		boolean = skip;
		waitFor = WaitFor::Nothing;
		working = false;
	}
}

void vm::main::Server::release_goTo () {
//	webBrowser->get (url);
}

void vm::main::Server::release_waitForPageLoading () {
//	webBrowser->waitForPageLoading ();
}
void vm::main::Server::release_executeJS () {
//	webBrowser->runJS (code);
}

void vm::main::Server::release_showErrorDialog () {
//	QMessageBox mbox;

//	mbox.setWindowTitle ("Error occurer");
//	mbox.setText ("Do you want to ignore it?");
//	mbox.setInformativeText (getErrorsStr ());
//	QPushButton *yesButton = mbox.addButton (QMessageBox::Yes);
//	mbox.addButton (QMessageBox::No);
//	mbox.show ();
//	mbox.exec ();

//	boolean = mbox.clickedButton () == yesButton;
//	working = false;
}
