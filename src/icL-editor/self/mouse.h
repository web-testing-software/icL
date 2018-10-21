#ifndef MOUSE_H
#define MOUSE_H

#include "keyboard.h"

namespace icL::editor {

class Mouse : public Keyboard
{
	Q_OBJECT
public:
	explicit Mouse(QObject * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // MOUSE_H
