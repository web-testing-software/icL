#ifndef icL_toolkit_session_Session
#define icL_toolkit_session_Session

#include "../tree/folder.h"

#include <QObject>

namespace icL::toolkit::session {

/**
 * @brief The Session class describes a icL IDE session
 */
class Session : public tree::Folder
{
public:
	/**
	 * @brief Session is the default constructor
	 */
	explicit Session();

	/**
	 * @brief loadSession sets up a session from a JSON object
	 * @param obj is the JSON object to analize
	 * @return true if loaded successfull, otherwise false
	 */
	bool loadSession(const QJsonObject & obj);

	// Item interface
public:
	QVariant     data(int column) override;
	tree::Item * parent() override;
	QString      getIcon() override;

private:
	/// @brief m_name is the name of loaded session
	QString m_name;
};

}  // namespace icL::toolkit::session

#endif  // icL_toolkit_session_Session
