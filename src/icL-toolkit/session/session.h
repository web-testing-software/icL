#ifndef icL_toolkit_session_Session
#define icL_toolkit_session_Session

#include "../tree/folder.h"

#include <QObject>

namespace icL::toolkit::session {

class Session : public tree::Folder
{
public:
	explicit Session();

	bool loadSession(const QJsonObject & obj);

	// Item interface
public:
	QVariant     data(int column) override;
	tree::Item * parent() override;
	QString      getIcon() override;

private:
	QString m_name;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Session
