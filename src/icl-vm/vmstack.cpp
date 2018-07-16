#include "vmstack.h"

#include "virtualmachine.h"

#include <icl-context/base/object/value.h>

#include <QStringBuilder>

namespace icL {

VMStack::VMStack() {
	connect(
	  this, &VMStack::invoke_highlight, this, &VMStack::release_hightlight);

	setSColor(memory::SelectionColor::Executing);
}

memory::Memory * VMStack::memory() {
	return &mem;
}


void VMStack::init(const QString & source, bool contentChanged) {
	if (vm == nullptr || contentChanged) {
		this->source = source;

		if (vm == nullptr) {
			vm = new VirtualMachine(this, nullptr, &this->source);

			//			vm->setFragLimits(0, source.size());
		}

		auto it = vm;

		if (it->getParent() != nullptr) {
			it = it->getParent();
		}

		it->setFragLimits(-1, source.size());
	}
}

void VMStack::step(int stopRule) {
	if (isRunning()) {
		qDebug() << "dropped";
		return;
	}

	setRunning(true);

	this->stopRule = stopRule;

	start(QThread::HighPriority);
}

Server * VMStack::server() const {
	return m_server;
}

QColor VMStack::sColor() const {
	return m_sColor;
}

bool VMStack::running() const {
	return m_running;
}

void VMStack::setServer(Server * server) {
	if (m_server == server)
		return;

	m_server = server;
	emit serverChanged(m_server);
}

void VMStack::setRunning(bool running) {
	if (m_running == running)
		return;

	m_running = running;
	emit runningChanged(m_running);
}


void VMStack::interrupt(
  memory::FunctionCall fcall, std::function<void(memory::Return &)> feedback) {
	qWarning() << "interrupt"
			   << fcall.source.source->mid(
					fcall.source.begin, fcall.source.end - fcall.source.begin);

	vm = new VirtualMachine(this, vm, &source);

	for (const memory::Argument & arg : fcall.args) {
		mem.stackIt().stack()->setValue(arg.name, arg.object->getValue());
	}

	vm->setOnStop(feedback);
	vm->setFragLimits(fcall.source.begin, fcall.source.end);

	setSColor(memory::SelectionColor::NewStack);
	highlight(fcall.source.begin - 1, fcall.source.end + 1);
}

const QString & VMStack::getWorkingDir() {
	return dir_path;
}

const QString & VMStack::getCrossfirePass() {
	return crossfirePass;
}

void VMStack::highlight(int pos1, int pos2) {
	emit invoke_highlight(pos1, pos2);
}

void VMStack::exit(const memory::Exception & exc) {
	m_server->newLog(
	  0, "exited with code " % QString::number(exc.code) % ": " % exc.message);

	setSColor(memory::SelectionColor::Error);
}

void VMStack::setSColor(memory::SelectionColor scolor) {
	if (scolor == e_sColor) {
		return;
	}

	switch (scolor) {
	case memory::SelectionColor::Parsing:
		m_sColor = QColor(0xff7dffb5);
		break;

	case memory::SelectionColor::Executing:
		m_sColor = QColor(0xff6bdaff);
		break;

	case memory::SelectionColor::NewStack:
		m_sColor = QColor(0xfff4cdff);
		break;

	case memory::SelectionColor::Destroying:
		m_sColor = QColor(0xfffdff7d);
		break;

	case memory::SelectionColor::Error:
		m_sColor = QColor(0xffffb0bd);
		break;
	}

	e_sColor = scolor;
	emit sColorChanged(m_sColor);
}

void VMStack::release_hightlight(int pos1, int pos2) {
	emit request_Highlight(pos1, pos2);
}


void VMStack::run() {
	memory::StepType::Value returned = memory::StepType::None;

	while ((returned & stopRule) == 0x0 && vm != nullptr) {
		returned = vm->step();

		if (returned == memory::StepType::None) {
			VirtualMachine * nvm = vm->getParent();

			delete vm;
			vm = nvm;

			returned = memory::StepType::CommandOut;

			if (vm == nullptr) {
				m_server->newLog(0, "exited with code 0");
			}
		}

		//		QThread::msleep(100);
	}

	setRunning(false);
	//	qDebug() << "exited";
}

}  // namespace icL
