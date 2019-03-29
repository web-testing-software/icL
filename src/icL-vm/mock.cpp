#include "mock.h"

namespace icL::vm {

void Mock::signal(const il::Signal & signal) {
    m_signal = signal;
}

void Mock::addDescription(const QString &) {
    // Do nothing
}

void Mock::markStep(const QString &) {
    // Do nothing
}

void Mock::markTest(const QString &) {
    // Do nothing
}

void Mock::break_() {
    // Do nothing
}

void Mock::continue_() {
    // Do nothing
}

void Mock::return_(const QVariant &) {
    // Do nothing
}

bool Mock::hasOkState() {
    return m_signal.code == memory::Signals::NoError;
}

memory::Memory * Mock::getMemory() {
    return nullptr;
}

}  // namespace icL::vm
