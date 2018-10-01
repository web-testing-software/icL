#include "look.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

namespace icL::look {

Look::Look(QObject * parent)
	: Base(parent) {
	m_editor  = new editor::Editor(this);
	m_session = new session::SessionWindow(this);
	m_start   = new start::StartWindow(this);
}

Look::~Look() {
	icL_dropField(m_editor);
	icL_dropField(m_session);
	icL_dropField(m_start);
}

start::StartWindow * Look::start() const {
	return m_start;
}

session::SessionWindow * Look::session() const {
	return m_session;
}

editor::Editor * Look::editor() const {
	return m_editor;
}

bool Look::loadConf(const QString & path) {
	QFile         file(path);
	QTextStream   stream(&file);
	QJsonDocument doc;

	if (!file.open(QFile::ReadOnly)) {
		return false;
	}
	else {
		confFilePath = path;
	}

	QString content = stream.readAll();
	doc             = QJsonDocument::fromJson(content.toUtf8());

	if (!doc.isObject()) {
		doc = QJsonDocument::fromJson(QString("{}").toUtf8());
	}

	QJsonObject obj = doc.object();

	setUp(obj);
	file.close();

	return true;
}

void Look::setUp(const QJsonObject & obj) {
	m_editor->setUp(obj.value("editor").toObject());
	m_session->setUp(obj.value("session").toObject());
	m_start->setUp(obj.value("start").toObject());
}

bool Look::saveConf() {
	QFile         file(confFilePath);
	QTextStream   stream(&file);
	QJsonDocument doc;

	if (!file.open(QFile::WriteOnly)) {
		return false;
	}

	doc.setObject(getUp());

	stream << doc.toJson(QJsonDocument::Indented);

	file.close();
	return true;
}

QJsonObject Look::getUp() {
	QJsonObject obj;

	obj["editor"]  = m_editor->getUp();
	obj["session"] = m_session->getUp();
	obj["start"]   = m_start->getUp();

	return obj;
}

}  // namespace icL::look
