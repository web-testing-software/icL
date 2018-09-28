#ifndef INPUT_H
#define INPUT_H

#include "../base/link.h"

#include <QObject>

namespace icL::look::start {

class Input : public base::Link
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(base::Text * inactive READ inactive WRITE setInactive NOTIFY inactiveChanged)
	Q_PROPERTY(base::Text * selection READ selection WRITE setSelection NOTIFY selectionChanged)
	Q_PROPERTY(QColor cursor READ cursor WRITE setCursor NOTIFY cursorChanged)
	// clang-format on

	base::Text * m_inactive  = nullptr;
	base::Text * m_selection = nullptr;
	QColor       m_cursor;

public:
	explicit Input(QObject * parent = nullptr);
	~Input();

	/**
	 * @brief inactive is the look for an inactive input
	 * @return the look for an inactive input
	 */
	base::Text * inactive() const;

	/**
	 * @brief selection is the look for an selection
	 * @return the for an selection
	 */
	base::Text * selection() const;

	/**
	 * @brief cursor is the color for the text cursor
	 * @return the color for the text input
	 */
	QColor cursor() const;

signals:

	void inactiveChanged(base::Text * inactive);
	void selectionChanged(base::Text * selection);
	void cursorChanged(QColor cursor);

public slots:
	/**
	 * @brief setInactive changes the look for an inactive input
	 * @param inactive is the new look of inactive inputs
	 */
	void setInactive(base::Text * inactive);

	/**
	 * @brief setSelection changes the look for an text selection
	 * @param selectionis the new look for inactive inputs
	 */
	void setSelection(base::Text * selection);

	/**
	 * @brief setCursor changes the color of text cursor
	 * @param cursor is the new color for text cursors
	 */
	void setCursor(QColor cursor);
};

}  // namespace icL::look::start
#endif  // INPUT_H
