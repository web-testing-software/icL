//#include "serverhighlevel.h"

//#include <icl-vm/server.cpp>

//namespace icL::app {

//ServerHighLevel::ServerHighLevel() : Server() {
//	connect(
//	  this, &ServerHighLevel::invoke_executeJS, this,
//	  &ServerHighLevel::release_executeJS);
//	connect(
//	  this, &ServerHighLevel::invoke_goTo, this,
//	  &ServerHighLevel::release_goTo);
//	connect(
//	  this, &ServerHighLevel::invoke_waitForPageLoading, this,
//	  &ServerHighLevel::release_waitForPageLoading);
//}

//bool ServerHighLevel::goTo(const QString & url) {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor   = WaitFor::GoTo;
//	working   = true;
//	this->url = url;

//	emit invoke_goTo();
//	while (working) {
//		;
//	}
//	return variant.toBool();
//}

//bool ServerHighLevel::waitForPageLoading() {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor = WaitFor::PageLoading;
//	working = true;

//	emit invoke_waitForPageLoading();
//	while (working) {
//		;
//	}

//	return variant.toBool();
//}

//QVariant ServerHighLevel::executeJS(const QString & code) {
//	if (waitFor != WaitFor::Nothing) {
//		return false;
//	}

//	waitFor    = WaitFor::ExecuteJS;
//	working    = true;
//	this->code = code;

//	emit invoke_executeJS();
//	while (working) {
//		;
//	}
//	return variant;
//}

//void ServerHighLevel::logOut(int level, const QString & message) {
//	emit request_LogOut(level, message);
//}

//void ServerHighLevel::finish_PageLoading(bool success) {
//	if (waitFor == WaitFor::GoTo || waitFor == WaitFor::PageLoading) {
//		variant = success;
//		waitFor = WaitFor::Nothing;
//		working = false;
//	}
//}

//void ServerHighLevel::finish_executeJS(QVariant variant) {
//	if (waitFor == WaitFor::ExecuteJS) {
//		this->variant = std::move(variant);
//		this->waitFor = WaitFor::Nothing;
//		this->working = false;
//	}
//}

//QQuickItem * ServerHighLevel::webEngine() const {
//	return m_webEngine;
//}

//void ServerHighLevel::setWebEngine(QQuickItem * webEngine) {
//	if (m_webEngine == webEngine) {
//		return;
//	}

//	m_webEngine = webEngine;
//	emit webEngineChanged(m_webEngine);
//}

//void ServerHighLevel::release_goTo() {
//	emit request_UrlLoad(url);
//}

//void ServerHighLevel::release_waitForPageLoading() {
//	// Noting to do, just wait
//}

//void ServerHighLevel::release_executeJS() {
//	emit request_JsRun(code);
//}

//}  // namespace icL::app
