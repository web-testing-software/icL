#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "side.h"

#include <QObject>

/**
 * The icL.look.start namespace contains look for the start window
 */
namespace icL::look::start {

/**
 * @brief The StartWindow class describes a look for start window
 */
class StartWindow : public QObject
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text* header READ header WRITE setHeader NOTIFY headerChanged)
	Q_PROPERTY(Side* left READ left WRITE setLeft NOTIFY leftChanged)
	Q_PROPERTY(Side* right READ right WRITE setRight NOTIFY rightChanged)
	Q_PROPERTY(base::Text* underline READ underline WRITE setUnderline NOTIFY underlineChanged)
	// clang-format on

	base::Text * m_header;
	Side *       m_left;
	Side *       m_right;
	base::Text * m_underline;

public:
	/**
	 * @brief StartWindow is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit StartWindow(QObject * parent = nullptr);

	/**
	 * @brief header is the look for window header
	 * @return the look for window header
	 */
	base::Text * header() const;

	/**
	 * @brief left is look for the left side
	 * @return the look for left side
	 */
	Side * left() const;

	/**
	 * @brief right is look for the right side
	 * @return the look for the right side
	 */
	Side * right() const;

	/**
	 * @brief underline is the look for bottom line
	 * @return the look for bottom line
	 */
	base::Text * underline() const;

signals:
	void headerChanged(base::Text * header);
	void leftChanged(Side * left);
	void rightChanged(Side * right);
	void underlineChanged(base::Text * underline);

public slots:
	/**
	 * @brief setHeader changes the header look
	 * @param header is the new header look
	 */
	void setHeader(base::Text * header);

	/**
	 * @brief setLeft changes the left side look
	 * @param left is the new look for left side
	 */
	void setLeft(Side * left);

	/**
	 * @brief setRight changes the right side look
	 * @param right is the new look for right side
	 */
	void setRight(Side * right);

	/**
	 * @brief setUnderline changes the look of bottom line
	 * @param underline is the new look for bottom line
	 */
	void setUnderline(base::Text * underline);
};

}  // namespace icL::look::start

#endif  // STARTWINDOW_H
