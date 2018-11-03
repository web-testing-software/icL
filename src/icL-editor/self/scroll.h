#ifndef SCROLL_H
#define SCROLL_H

#include "drawing.h"

namespace icL::editor {

class Scroll : public Drawing
{
	Q_OBJECT
public:
	explicit Scroll(QQuickItem * parent = nullptr);

	/**
	 * @brief scrollX scrolls to absolute relative position
	 * @param ratio get a value from 0.0 to 1.0
	 */
	Q_INVOKABLE void scrollX(qreal ratio);

	/**
	 * @brief scrollY
	 * @param ratio
	 */
	Q_INVOKABLE void scrollY(qreal ratio);

signals:

public slots:

protected:
	/**
	 * @brief moveUp move first visible line up by n lines
	 * @param by is the number of lines
	 */
	void scrollUpBy(int by) override;

	/**
	 * @brief moveDown move first visible down by n lines
	 * @param by is the number of lines
	 */
	void scrollDownBy(int by) override;
};

}  // namespace icL::editor

#endif  // SCROLL_H
