#ifndef icL_look_session_Issue
#define icL_look_session_Issue

#include "../base/effect.h"
#include "../base/linkadv.h"



namespace icL::look::session {

/**
 * @brief The Issue class describe a look for a issue item
 */
class Issue : public base::LinkAdv
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Effect* effect READ effect WRITE setEffect NOTIFY effectChanged)
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

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:

	void effectChanged(base::Effect * effect);

public slots:
	/**
	 * @brief setEffect changes the underline effect
	 * @param effect is the new underline effect
	 */
	void setEffect(base::Effect * effect);
};

}  // namespace icL::look::session

#endif  // icL_look_session_Issue
