#ifndef icL_look_Look
#define icL_look_Look

#include "../editor/editor.h"
#include "../session/sessionwindow.h"
#include "../start/startwindow.h"

#include <QObject>

namespace icL::look {

class Look : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(start::StartWindow*       start READ start   WRITE setStart   NOTIFY startChanged)
	Q_PROPERTY(session::SessionWindow* session READ session WRITE setSession NOTIFY sessionChanged)
	Q_PROPERTY(editor::Editor*          editor READ editor  WRITE setEditor  NOTIFY editorChanged)
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

signals:
	void startChanged(start::StartWindow * start);
	void sessionChanged(session::SessionWindow * session);
	void editorChanged(editor::Editor * editor);

public slots:
	/**
	 * @brief setStart changes the look of start window
	 * @param start is the new look for start window
	 */
	void setStart(start::StartWindow * start);

	/**
	 * @brief setSession changes the look of session window
	 * @param session is the new look for session window
	 */
	void setSession(session::SessionWindow * session);

	/**
	 * @brief setEditor changes the look of code editor
	 * @param editor is the new look for code editor
	 */
	void setEditor(editor::Editor * editor);
};

}  // namespace icL::look

#endif  // icL_look_Look
