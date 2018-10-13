#include "static.h"

#include "../base/effectadv.h"
#include "../base/linkadv.h"

#include <QJsonObject>

namespace icL::look {

Static::Static(QObject * parent)
	: BaseLook(parent) {
	m_menuItem      = new LinkAdv(this);
	m_submenuItem   = new LinkAdv(this);
	m_submenuBorder = new EffectAdv(this);
	m_button        = new LinkAdv(this);
}

LinkAdv * Static::menuItem() const {
	return m_menuItem;
}

LinkAdv * Static::submenuItem() const {
	return m_submenuItem;
}

EffectAdv * Static::submenuBorder() const {
	return m_submenuBorder;
}

LinkAdv * Static::button() const {
	return m_button;
}

QColor Static::background() const {
	return m_background;
}

QColor Static::handle() const {
	return m_handle;
}

QColor Static::handleVisible() const {
	return m_handleVisible;
}

QColor Static::handleHidden() const {
	return m_handleHidden;
}

void Static::setUp(const QJsonObject & obj) {
	m_menuItem->setUp(obj.value("menu-item").toObject());
	m_submenuItem->setUp(obj.value("submenu-item").toObject());
	m_submenuBorder->setUp(obj.value("submenu-border").toObject());
	m_button->setUp(obj.value("button").toObject());
	m_background    = objToColor(obj.value("background").toObject());
	m_handle        = objToColor(obj.value("handle").toObject());
	m_handleVisible = objToColor(obj.value("handle-visible").toObject());
	m_handleHidden  = objToColor(obj.value("handle-hidden").toObject());
	m_menuShadow    = objToColor(obj.value("menu-shadow").toObject());
	m_submenuShadow = objToColor(obj.value("submenu-shadow").toObject());

	emit backgroundChanged(m_background);
	emit handleChanged(m_handle);
	emit handleVisibleChanged(m_handleVisible);
	emit handleHiddenChanged(m_handleHidden);
	emit menuShadowChanged(m_menuShadow);
	emit submenuShadowChanged(m_submenuShadow);
}

QJsonObject Static::getUp() {
	return {{"menu-item", m_menuItem->getUp()},
			{"submenu-item", m_submenuItem->getUp()},
			{"submenu-border", m_submenuBorder->getUp()},
			{"button", m_button->getUp()},
			{"background", colorToObj(m_background)},
			{"handle", colorToObj(m_handle)},
			{"handle-visible", colorToObj(m_handleVisible)},
			{"handle-hidden", colorToObj(m_handleHidden)},
			{"menu-shadow", colorToObj(m_menuShadow)},
			{"submenu-shadow", colorToObj(m_submenuShadow)}};
}

QColor Static::menuShadow() const {
	return m_menuShadow;
}

QColor Static::submenuShadow() const {
	return m_submenuShadow;
}

void Static::setBackground(QColor background) {
	if (m_background == background)
		return;

	m_background = background;
	emit backgroundChanged(m_background);
}

void Static::setHandle(QColor handle) {
	if (m_handle == handle)
		return;

	m_handle = handle;
	emit handleChanged(m_handle);
}

void Static::setHandleVisible(QColor handleVisible) {
	if (m_handleVisible == handleVisible)
		return;

	m_handleVisible = handleVisible;
	emit handleVisibleChanged(m_handleVisible);
}

void Static::setHandleHidden(QColor handleHidden) {
	if (m_handleHidden == handleHidden)
		return;

	m_handleHidden = handleHidden;
	emit handleHiddenChanged(m_handleHidden);
}

void Static::setMenuShadow(QColor menuShadow) {
	if (m_menuShadow == menuShadow)
		return;

	m_menuShadow = menuShadow;
	emit menuShadowChanged(m_menuShadow);
}

void Static::setSubmenuShadow(QColor submenuShadow) {
	if (m_submenuShadow == submenuShadow)
		return;

	m_submenuShadow = submenuShadow;
	emit submenuShadowChanged(m_submenuShadow);
}

}  // namespace icL::look
