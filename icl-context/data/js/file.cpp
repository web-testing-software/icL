#include "file.h"

#include <icl-context/base/object/object.h>

#include <QFile>
#include <QTextStream>

namespace icL::context::data::js {

File::File(memory::InterLevel * il)
	: Js(il){
	m_role = Role::JsFile;
}

QString File::getFileContent() {
	QFile file;
	bool  absolutePath;

	fileName = dynamic_cast<object::Object *>(m_next)->getValue().toString();

#ifdef Q_OS_WIN
	absolutePath = fileName.length() > 1 && fileName[1] == ":";
#else
	absolutePath = fileName.length() > 0 && fileName[0] == "/";
#endif

	QString path =
	  absolutePath ? fileName : il->vms->getWorkingDir() + fileName;

	file.setFileName(path);
	if (!file.open(QFile::ReadOnly)) {
		il->vm->exception(
		  {-10, QStringLiteral("File `%1` not found.").arg(fileName)});
		return QString{};
	}

	QTextStream stream{&file};

	return stream.readAll();
}

bool File::checkArgs() {
	return m_next->role() == Role::Object &&
		   dynamic_cast<object::Object *>(m_next)->type() ==
			 memory::Type::String &&
		   m_next->next() == nullptr;
}

bool File::checkPrev(const Context * context) const {
	return context == nullptr;
}

memory::StepType::Value File::execute() {
	if (!checkArgs()) {
		il->vm->exception(
		  {-203, "Wrong arglist for $file, expected <String, CommandEnd>"});
		return memory::StepType::NONE;
	}

	QString code = getFileContent();

	if (!code.isEmpty()) {
		il->server->runJS(code);
	}

	return memory::StepType::MINI_STEP;
}

Context * File::getBeginContext() {
	return this;
}

Context * File::getEndContext() {
	return m_next;
}


}  // namespace icL::context::data::js
