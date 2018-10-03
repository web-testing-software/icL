#ifndef CHARS_H
#define CHARS_H

#include <QObject>
#include <QTextCharFormat>

namespace icL::editor::look {

class Chars : public QObject
{
	Q_OBJECT
public:
	explicit Chars(QObject * parent = nullptr);

	static QTextCharFormat comment;
	static QTextCharFormat function;
	static QTextCharFormat global;
	static QTextCharFormat keyword;
	static QTextCharFormat local;
	static QTextCharFormat method;
	static QTextCharFormat number;
	static QTextCharFormat property;
	static QTextCharFormat string;
	static QTextCharFormat system;
	static QTextCharFormat type;
	// occurence

	static void update();

signals:

public slots:

private:
	/**
	 * @brief instance is needed to send signals to QML to update current file
	 * systax highlighting
	 * @return a static intance of chars
	 */
	Chars * instance();

private:
	Chars * m_instance = nullptr;
};

}  // namespace icL::editor::look

#endif  // CHARS_H
