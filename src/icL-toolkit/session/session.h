#ifndef icL_toolkit_session_Session
#define icL_toolkit_session_Session

#include "../tree/folder.h"

#include <QObject>

namespace icL::toolkit::session {

class Session : public tree::Folder
{

public:
	explicit Session();

	// Item interface
public:
	QVariant     data(int column) override;
	tree::Item * parent() override;
	QString      getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Session
