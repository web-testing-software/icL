#include "keyboard.h"

#include "../private/cursor.h"
#include "../private/line.h"
#include "../private/selection.h"
#include "linenumbers.h"

namespace icL::editor {

Keyboard::Keyboard(QQuickItem * parent)
    : History(parent) {}

void Keyboard::keyPressEvent(QKeyEvent * event) {
    auto mods = event->modifiers();

    if (event->key() >= Qt::Key_F1 && event->key() <= Qt::Key_F12) {
        if (mods.testFlag(Qt::ShiftModifier)) {
            if (mods.testFlag(Qt::ControlModifier)) {
                if (mods.testFlag(Qt::AltModifier)) {
                    functionCtrlAltShiftKey(event);
                }
                else {
                    functionShiftCtrlKey(event);
                }
            }
            else {
                if (mods.testFlag(Qt::AltModifier)) {
                    functionShiftAltKey(event);
                }
                else {
                    functionShiftKey(event);
                }
            }
        }
        else {
            if (mods.testFlag(Qt::ControlModifier)) {
                if (mods.testFlag(Qt::AltModifier)) {
                    functionCtrlAltKey(event);
                }
                else {
                    functionCtrlKey(event);
                }
            }
            else {
                if (mods.testFlag(Qt::AltModifier)) {
                    functionAltKey(event);
                }
                else {
                    functionKey(event);
                }
            }
        }
    }
    else {
        if (mods.testFlag(Qt::ShiftModifier)) {
            if (mods.testFlag(Qt::ControlModifier)) {
                if (mods.testFlag(Qt::AltModifier)) {
                    anyCtrlAltShiftKey(event);
                }
                else {
                    anyShiftCtrlKey(event);
                }
            }
            else {
                if (mods.testFlag(Qt::AltModifier)) {
                    anyShiftAltKey(event);
                }
                else {
                    anyShiftKey(event);
                }
            }
        }
        else {
            if (mods.testFlag(Qt::ControlModifier)) {
                if (mods.testFlag(Qt::AltModifier)) {
                    anyCtrlAltKey(event);
                }
                else {
                    anyCtrlKey(event);
                }
            }
            else {
                if (mods.testFlag(Qt::AltModifier)) {
                    anyAltKey(event);
                }
                else {
                    anyKey(event);
                }
            }
        }
    }

    emit requestRepaint();
}

void Keyboard::functionKey(QKeyEvent * event) {}

void Keyboard::functionShiftKey(QKeyEvent * event) {}

void Keyboard::functionCtrlKey(QKeyEvent * event) {}

void Keyboard::functionAltKey(QKeyEvent * event) {}

void Keyboard::functionShiftCtrlKey(QKeyEvent * event) {}

void Keyboard::functionShiftAltKey(QKeyEvent * event) {}

void Keyboard::functionCtrlAltKey(QKeyEvent * event) {}

void Keyboard::functionCtrlAltShiftKey(QKeyEvent * event) {}

void Keyboard::anyKey(QKeyEvent * event) {
    switch (event->key()) {

    case Qt::Key_Escape:
        break;

    case Qt::Key_Delete:
        break;

    case Qt::Key_Backspace:
        break;

    case Qt::Key_Left:
        hMoveCursorChar(-1);
        break;

    case Qt::Key_Right:
        hMoveCursorChar(+1);
        break;

    default:
        if (!event->text().isEmpty()) {
            m_mainSelection->insert(event->text());
        }
    }
}

void Keyboard::anyShiftKey(QKeyEvent * event) {
    switch (event->key()) {
    default:
        if (!event->text().isEmpty()) {
            m_mainSelection->insert(event->text());
        }
    }
}

void Keyboard::anyCtrlKey(QKeyEvent * event) {}

void Keyboard::anyAltKey(QKeyEvent * event) {}

void Keyboard::anyShiftCtrlKey(QKeyEvent * event) {}

void Keyboard::anyShiftAltKey(QKeyEvent * event) {}

void Keyboard::anyCtrlAltKey(QKeyEvent * event) {}

void Keyboard::anyCtrlAltShiftKey(QKeyEvent * event) {}

}  // namespace icL::editor
