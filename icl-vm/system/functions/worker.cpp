#include "server.h"
#include "structures/webelement.h"
#include "worker.h"

Worker *Worker::m_instance = nullptr;

Worker::Worker () : QThread () {
	if (m_instance == nullptr) {
		m_instance = this;
	}
}

void Worker::setToErrorState () {
	error_state = true;
}

Worker * Worker::instance () {
	return m_instance;
}

void Worker::run () {
	// TODO: Write this function
}

bool Worker::check_errors () {
	if (error_state) {
//		return server->showErrorDialog ();
	}
	else {
		return true;
	}
}
