#ifndef icL_toolkit_session_Libs
#define icL_toolkit_session_Libs

#include "../tree/folder.h"



namespace icL::toolkit::session {

class Libs : tree::Folder
{
public:
	Libs(Item * parent);

	bool setLibsList(const QStringList & libs);

	// Item interface
public:
	QVariant data(int column) override;
	QString  getIcon() override;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Libs
