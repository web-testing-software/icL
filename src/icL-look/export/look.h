#ifndef icL_look_Look
#define icL_look_Look

#include "../base/baselook.h"



namespace icL::look {

class StartWindow;
class SessionWindow;
class Editor;

/**
 * @brief The Look class export look model to QML
 */
class Look : public BaseLook
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(icL::look::StartWindow*     start READ start   NOTIFY startChanged)
	Q_PROPERTY(icL::look::SessionWindow* session READ session NOTIFY sessionChanged)
	Q_PROPERTY(icL::look::Editor*         editor READ editor  NOTIFY editorChanged)
	Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
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
	 * @brief path is the path to image folder
	 * @return the path to image folder
	 */
	QString path() const;

	/**
	 * @brief loadConf loads the configuration from JSON file
	 * @param path is the path to the JSON file
	 * @return true, if so file exists, otherwise false
	 */
	Q_INVOKABLE bool loadConf(const QString & path, bool editorOnly);

	/**
	 * @brief saveConf saves the configuration in loaded JSON file
	 * @return true, if file is writtable, otherwise false
	 */
	Q_INVOKABLE bool saveConf(bool editorOnly);

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

public slots:
	/**
	 * @brief setPath changes the path to images folder
	 * @param path is the new path tp images folder
	 */
	void setPath(QString path);

signals:
	void startChanged(StartWindow * start);
	void sessionChanged(SessionWindow * session);
	void editorChanged(Editor * editor);
	void pathChanged(QString path);

private:
	StartWindow *   m_start   = nullptr;
	SessionWindow * m_session = nullptr;
	Editor *        m_editor  = nullptr;

	QString confFilePath;
	QString editorConfFilePath;
	QString m_path = "qrc:/themes-images/light/";
};

}  // namespace icL::look

#endif  // icL_look_Look