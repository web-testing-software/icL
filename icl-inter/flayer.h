#ifndef FLAYER_H
#define FLAYER_H

#include <QObject>

namespace vm::inter::_private {

/**
 * @brief The Flayer class - flayer is a flying cursor.
 */
class Flayer : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int begin READ begin WRITE setBegin NOTIFY beginChanged)
	Q_PROPERTY(int end READ end WRITE setEnd NOTIFY endChanged)

public:
	Flayer();
	~Flayer() override;

	int begin() const;
	int end() const;

public slots:
	void setBegin(int begin);
	void setEnd(int end);

signals:
	void beginChanged(int begin);
	void endChanged(int end);

private:
	int m_begin;
	int m_end;
};

}  // namespace vm::inter::_private

#endif  // FLAYER_H
