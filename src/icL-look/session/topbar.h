#ifndef TOPBAR_H
#define TOPBAR_H

#include <QObject>

namespace icL {
namespace look {
namespace session {

class TopBar : public QObject
{
	Q_OBJECT
public:
	explicit TopBar(QObject *parent = nullptr);

signals:

public slots:
};

} // namespace session
} // namespace look
} // namespace icL

#endif // TOPBAR_H