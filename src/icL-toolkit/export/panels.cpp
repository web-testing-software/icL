#include "panels.h"

#include "../panels/browser.h"
#include "../panels/code.h"
#include "../panels/debug.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

namespace icL::toolkit::panels {

Panels::Panels(QObject * parent)
	: QObject(parent) {
	m_browser = new Browser(this);
	m_code    = new Code(this);
	m_debug   = new Debug(this);
}

Panels::~Panels() {
	m_browser->deleteLater();
	m_code->deleteLater();
	m_debug->deleteLater();
}

Browser * Panels::browser() const {
	return m_browser;
}

Code * Panels::code() const {
	return m_code;
}

Debug * Panels::debug() const {
	return m_debug;
}

bool Panels::projectsOrFiles() const {
	return m_projectsOrFiles;
}

bool Panels::loadConf(const QString & path) {
	QFile         file(path);
	QTextStream   stream(&file);
	QJsonDocument doc;

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}
	else {
		m_path = path;
	}

	QString content = stream.readAll();
	doc             = QJsonDocument::fromJson(content.toUtf8());

	if (!doc.isObject()) {
		doc = QJsonDocument::fromJson(QString("{}").toUtf8());
	}

	QJsonObject obj = doc.object();

	m_browser->setUp(obj.value("browser").toObject());
	m_code->setUp(obj.value("code").toObject());
	m_debug->setUp(obj.value("debug").toObject());
	m_projectsOrFiles = obj.value("projects-or-files").toBool();

	file.close();

	return true;
}

bool Panels::saveConf() {
	QFile         file(m_path);
	QTextStream   stream(&file);
	QJsonDocument doc;

	if (!file.open(QFile::WriteOnly)) {
		return false;
	}

	QJsonObject obj = {{"browser", m_browser->getUp()},
					   {"code", m_code->getUp()},
					   {"debug", m_debug->getUp()},
					   {"projects-or-files", m_projectsOrFiles}};

	doc.setObject(obj);

	stream << doc.toJson(QJsonDocument::Indented);

	file.close();
	return true;
}

void Panels::setProjectsOrFiles(bool projectsOrFiles) {
	if (m_projectsOrFiles == projectsOrFiles)
		return;

	m_projectsOrFiles = projectsOrFiles;
	emit projectsOrFilesChanged(m_projectsOrFiles);
}

}  // namespace icL::toolkit::panels
