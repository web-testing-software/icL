//#ifndef VIRTUALMACHINE_H
//#define VIRTUALMACHINE_H

//#include "../../parser.h"
//#include "memorystate.h"
//#include "stackstate.h"

//#include <QThread>

//// Fast access to main active objects
//#define virtualMachine vm::main::VirtualMachine::instance ()
//#define stackStateIterator virtualMachine->stackStateIt ()
//#define stackState stackStateIterator->stack ()
//#define memoryStateIterator virtualMachine->memoryStateIt ()
//#define memoryState memoryStateIterator->state ()
//#define inStream ( *vm::main::VirtualMachine::getInStream () )
//#define outStream ( *vm::main::VirtualMachine::getOutStream () )

//namespace vm {
//namespace main {

//struct CommandsToSearch {           // By default it search:
//	int command1	= 0xFFFFFFFF;   // -1 - Stack out
//	int command2	= 0x00000000;   //  0 - EOF
//};

//class VirtualMachine : public QThread
//{
//	static VirtualMachine *m_instance;

//public:
//	enum class WorkMode {
//		EXECUTING,
//		SHOWING_ON_SCREEN,
//		WRITING
//	};

//	VirtualMachine ();

//	// External access to functions
//	MemoryStateIterator* memoryStateIt ();
//	StackStateIterator* stackStateIt ();

//	static void makeCurrent (VirtualMachine *vm);
//	static VirtualMachine* instance ();

//	// Base functions
//	void openFile (const QString &path);
//	bool containsVar (const QString &name);
//	bool checkType (const QString &name, DataState::Type &type);
//	QVariant getVar (const QString &name);

//	void search (const CommandsToSearch &commands);
//	bool runIsPermited ();

//	// Debug functions
//	void setError (Error m_error, const QString &description = "");
//	void setStepNumber (int step);
//	void setCommandNumber (int command);

//	// `Loop current` mode helper functions
//	MemoryState* memoryStateToStop ();
//	void setMemoryStateToStop (MemoryState *ms);

//	// Data streams access functions
//	QDataStream* getInStream ();
//	QDataStream* getOutStream ();

//protected:
//	void run ();

//private:
//	MemoryStateIterator m_memoryStateIt;
//	StackStateIterator m_stackStateIt;
//	MemoryState *m_memoryStateToStop;

//	Error m_error;
//	QString last_error;

//	bool m_runIsPermited	= true;
//	int m_stepNumber		= 0;
//	int m_commandNumber		= 0;
//	CommandsToSearch m_searchedCommands;

//	// Files and streams
//	QFile m_inFile;
//	QDataStream m_inStream;
//	QFile m_outFile;
//	QDataStream m_outStream;
//};

//}
//}

//#endif // VIRTUALMACHINE_H
