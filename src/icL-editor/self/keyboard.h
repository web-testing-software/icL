#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "history.h"

namespace icL::editor {

class Keyboard : public History
{
	Q_OBJECT
public:
	explicit Keyboard(QObject * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // KEYBOARD_H
