#ifndef icL_look_Look
#define icL_look_Look

#include "../editor/editor.h"
#include "../session/sessionwindow.h"
#include "../start/startwindow.h"



namespace icL::look {

class Look : public base::Base
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(start::StartWindow*       start READ start)
	Q_PROPERTY(session::SessionWindow* session READ session)
	Q_PROPERTY(editor::Editor*          editor READ editor)
	// clang-format on

	start::StartWindow *     m_start   = nullptr;
	session::SessionWindow * m_session = nullptr;
	editor::Editor *         m_editor  = nullptr;

public:
	/**
	 * @brief Look is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit Look(QObject * parent = nullptr);

	~Look();

	/**
	 * @brief start is the look of start window
	 * @return the look for start window
	 */
	start::StartWindow * start() const;

	/**
	 * @brief session is the look of session window
	 * @return the look for session window
	 */
	session::SessionWindow * session() const;

	/**
	 * @brief editor is the look of code editor
	 * @return the look for code editor
	 */
	editor::Editor * editor() const;

	/**
	 * @brief loadConf loads the configuration from JSON file
	 * @param path is the path to the JSON file
	 * @return true, if so file exists, otherwise false
	 */
	Q_INVOKABLE bool loadConf(const QString & path);

	void setUp(const QJsonObject & obj) override;
};

}  // namespace icL::look

#endif  // icL_look_Look
