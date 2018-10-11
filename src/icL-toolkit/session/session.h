#ifndef SESSION_H
#define SESSION_H

#include "../tree/folder.h"

#include <QObject>

namespace icL::toolkit::session {

class Session : public tree::Folder
{
	Q_OBJECT
public:
	explicit Session();

signals:

public slots:

	// Item interface
public:
	QVariant     data(int column) override;
	tree::Item * parent() override;
	QString      getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // SESSION_H
