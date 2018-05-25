#include "file.h"

#include <icl-context/base/object/object.h>

#include <QFile>
#include <QTextStream>

namespace icL::context::data::js {

File::File(memory::InterLevel * il, const QString & fileName)
	: Js(il)
	, fileName(fileName) {
	m_role = Role::JsFile;
}

QString File::getFileContent() {
	QFile file;
	bool  absolutePath;

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

bool File::execute() {
	if (!checkArgs()) {
		il->vm->exception(
		  {-203, "Wrong arglist for $file, expected <String, CommandEnd>"});
		return false;
	}

	QString code = getFileContent();

	if (!code.isEmpty()) {
		il->server->runJS(code);
	}
	else {
		return true;
	}

	return true;
}  // namespace icL::context::data::js

Context * File::getBeginContext() {
	return this;
}

Context * File::getEndContext() {
	return m_next;
}


}  // namespace icL::context::data::js