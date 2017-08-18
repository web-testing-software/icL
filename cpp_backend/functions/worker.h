#ifndef WORKER_H
#define WORKER_H

#include <QThread>

#define worker Worker::instance ()

/**
 * @brief The Worker class - execute .icf in parallel thread
 */
class Worker : public QThread
{
	static Worker *m_instance;

public:
	Worker ();

	void setToErrorState ();

	static Worker* instance ();

protected:
	void run ();

	bool check_errors ();

private:
	bool error_state = false;
};

#endif // WORKER_H
