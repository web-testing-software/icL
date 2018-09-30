#ifndef icL_look_editor_CharFormatBase
#define icL_look_editor_CharFormatBase

#include "../base/text.h"

#include <QObject>



namespace icL::look::editor {

class CharFormatBase : public base::Text
{
	Q_OBJECT

	// clang-format off
	Q_PROPERTY(bool   bold READ bold   WRITE setBold   NOTIFY boldChanged)
	Q_PROPERTY(bool italic READ italic WRITE setItalic NOTIFY italicChanged)
	// clang-format on

	bool m_bold;
	bool m_italic;

public:
	/**
	 * @brief CharFormatBase is the default constructor
	 * @param parent is the default QObject arg
	 */
	explicit CharFormatBase(QObject * parent = nullptr);

	/**
	 * @brief bold is the weight switcher of text
	 * @return the weight for the text
	 */
	bool bold() const;

	/**
	 * @brief italic is the angle switcher of text
	 * @return the angle for the text
	 */
	bool italic() const;

	/**
	 * @brief setUp set up the state from JSON object
	 * @param obj is the configuration object
	 */
	void setUp(const QJsonObject & obj);

signals:
	void boldChanged(bool bold);
	void italicChanged(bool italic);

public slots:
	/**
	 * @brief setBold changes the weight of text
	 * @param bold is the new weight for text
	 */
	void setBold(bool bold);

	/**
	 * @brief setItalic changes the angle of text
	 * @param italic is the new angle for text
	 */
	void setItalic(bool italic);
};

}  // namespace icL::look::editor

#endif  // icL_look_editor_CharFormatBase
