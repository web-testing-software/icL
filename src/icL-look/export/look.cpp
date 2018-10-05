#include "look.h"

#include "../editor/editor.h"
#include "../session/sessionwindow.h"
#include "../start/startwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

Look::Look(QObject * parent)
	: BaseLook(parent) {
	m_editor  = new Editor(this);
	m_session = new SessionWindow(this);
	m_start   = new StartWindow(this);
}

Look::~Look() {
	icL_dropField(m_editor);
	icL_dropField(m_session);
	icL_dropField(m_start);
}

StartWindow * Look::start() const {
	return m_start;
}

SessionWindow * Look::session() const {
	return m_session;
}

Editor * Look::editor() const {
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
	return {{"editor", m_editor->getUp()},
			{"session", m_session->getUp()},
			{"start", m_start->getUp()}};
}
