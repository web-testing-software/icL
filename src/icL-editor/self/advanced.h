#ifndef ADVANCED_H
#define ADVANCED_H

#include "mouse.h"

#include <QObject>

namespace icL::editor {

class Advanced : public Mouse
{
	Q_OBJECT
public:
	explicit Advanced(QObject * parent = nullptr);

signals:

public slots:
};

}  // namespace icL::editor

#endif  // ADVANCED_H
