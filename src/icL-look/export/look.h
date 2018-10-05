#ifndef icL_look_Look
#define icL_look_Look

#include "../base/baselook.h"



namespace icL::look {

class StartWindow;
class SessionWindow;
class Editor;

class Look : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(StartWindow*     start READ start   NOTIFY startChanged)
	Q_PROPERTY(SessionWindow* session READ session NOTIFY sessionChanged)
	Q_PROPERTY(Editor*         editor READ editor  NOTIFY editorChanged)
	// clang-format on

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
	StartWindow * start() const;

	/**
	 * @brief session is the look of session window
	 * @return the look for session window
	 */
	SessionWindow * session() const;

	/**
	 * @brief editor is the look of code editor
	 * @return the look for code editor
	 */
	Editor * editor() const;

	/**
	 * @brief loadConf loads the configuration from JSON file
	 * @param path is the path to the JSON file
	 * @return true, if so file exists, otherwise false
	 */
	Q_INVOKABLE bool loadConf(const QString & path);

	void setUp(const QJsonObject & obj) override;

	/**
	 * @brief saveConf saves the configuration in loaded JSON file
	 * @return true, if file is writtable, otherwise false
	 */
	Q_INVOKABLE bool saveConf();

	QJsonObject getUp() override;

signals:
	void startChanged(StartWindow * start);
	void sessionChanged(SessionWindow * session);
	void editorChanged(Editor * editor);

private:
	StartWindow *   m_start   = nullptr;
	SessionWindow * m_session = nullptr;
	Editor *        m_editor  = nullptr;

	QString confFilePath;
};

}  // namespace icL::look

#endif  // icL_look_Look
