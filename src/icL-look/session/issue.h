#ifndef icL_look_session_Issue
#define icL_look_session_Issue

#include "../base/linkadv.h"


class Effect;

/**
 * @brief The Issue class describe a look for a issue item
 */
class Issue : public LinkAdv
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(Effect* effect READ effect NOTIFY effectChanged)
	// clang-format on

	Effect * m_effect;

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
	Effect * effect() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void effectChanged(Effect * effect);
};

#endif  // icL_look_session_Issue
