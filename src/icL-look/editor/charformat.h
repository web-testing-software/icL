#ifndef icL_look_CharFormat
#define icL_look_CharFormat

#include "charformatbase.h"



namespace icL::look {

/**
 * @brief The CharFormat class define a format for a fragment of text
 */
class CharFormat : public CharFormatBase
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(int     underline READ underline  WRITE setUnderline  NOTIFY underlineChanged)
	Q_PROPERTY(QColor undercolor READ undercolor WRITE setUndercolor NOTIFY undercolorChanged)
	// clang-format on

public:
	/**
	 * @brief CharFormat is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit CharFormat(QObject * parent = nullptr);

	/**
	 * @brief underline is the type of underline
	 * @return the type for underline
	 */
	int underline() const;

	/**
	 * @brief undercolor is the color of underline
	 * @return the color for underline
	 */
	QColor undercolor() const;

	void setUp(const QJsonObject & obj) override;

	QJsonObject getUp() override;

signals:
	void underlineChanged(int underline);
	void undercolorChanged(QColor undercolor);

public slots:
	/**
	 * @brief setUnderline changes the type of underline
	 * @param underline is the new underline color
	 */
	void setUnderline(int underline);

	/**
	 * @brief setUndercolor changes the coor of underline
	 * @param undercolor is the new color for underline
	 */
	void setUndercolor(const QColor & undercolor);

private:
	int    m_underline;
	QColor m_undercolor;
};

}  // namespace icL::look

#endif  // icL_look_CharFormat
