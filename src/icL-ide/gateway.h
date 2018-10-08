#ifndef GATEWAY_H
#define GATEWAY_H

#include <QObject>

namespace icL::ide {

class GateWay : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY (qreal userInterfaceScale READ userInterfaceScale WRITE setUserInterfaceScale NOTIFY userInterfaceScaleChanged)
	Q_PROPERTY (bool     startWindowMode READ startWindowMode    WRITE setStartWindowMode    NOTIFY startWindowModeChanged)
	// clang-format on

public:
	explicit GateWay(QObject * parent = nullptr);

	/**
	 * @brief userInterfaceScale is the scale of interface requested by user
	 * @return the scale for interface requested by user
	 */
	qreal userInterfaceScale() const;

	/**
	 * @brief startWindowMode is true if the program is in start window mode
	 * @return true if the program is in start window mode, otheerwise false
	 */
	bool startWindowMode() const;

	/**
	 * @brief closeSessionWindow reuest to close all session windows
	 */
	Q_INVOKABLE void closeSessionWindows();

signals:
	void userInterfaceScaleChanged(qreal userInterfaceScale);
	void startWindowModeChanged(bool startWindowMode);

	/**
	 * @brief requestToCloseSessionWindows sends to QML the request to close
	 * session window, all window get closed imediatly
	 */
	void requestToCloseSessionWindows();

public slots:
	/**
	 * @brief setUserInterfaceScale changes the interface scale
	 * @param userInterfaceScale a value >= 0.25 and <= 4
	 */
	void setUserInterfaceScale(qreal userInterfaceScale);

	/**
	 * @brief setStartWindowMode change current mode
	 * @param startWindowMode true - start window, false - session window
	 */
	void setStartWindowMode(bool startWindowMode);

private:
	qreal m_userInterfaceScale;
	bool  m_startWindowMode;
};

}  // namespace icL::ide

#endif  // GATEWAY_H
