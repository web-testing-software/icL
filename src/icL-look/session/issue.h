#ifndef icL_look_session_Issue
#define icL_look_session_Issue

#include "../base/linkadv.h"


// clang-format off
namespace icL::look::base  { class Effect; }
// clang-format on

namespace icL::look::session {

/**
 * @brief The Issue class describe a look for a issue item
 */
class Issue : public base::LinkAdv
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Effect* effect READ effect)
	// clang-format on

	base::Effect * m_effect;

public:
	/**
	 * @brief Issue is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Issue(QObject * parent = nullptr);

	~Issue();

	/**
	 * @brief effect is the underline effect
	 * @return the underline effect
	 */
	base::Effect * effect() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;
};

}  // namespace icL::look::session

#endif  // icL_look_session_Issue
