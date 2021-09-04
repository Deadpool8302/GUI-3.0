#include "TextButton.hpp"

using namespace gui;

TextButton::TextButton(const sf::Vector2f& size):
	Textbox(size, GUI_ID_TEXTBUTTON)
{
	actionEvent = ActionEvent::RELEASE;
}

void TextButton::updateBox()
{
	if (m_isSelected) {
		m_box.setFillColor(m_selected.fillColor);
		m_box.setOutlineColor(m_selected.outlineColor);
		m_box.setOutlineThickness(m_selected.outlineThickness);
		m_box.setScale(m_selected.scaleFactor);
	}
	else {
		m_box.setFillColor(m_original.fillColor);
		m_box.setOutlineColor(m_original.outlineColor);
		m_box.setOutlineThickness(m_original.outlineThickness);
		m_box.setScale(m_original.scaleFactor);
	}
}

void TextButton::setBoxFillColor(const sf::Color& color)
{
	m_original.fillColor = color;
	updateBox();
}
void TextButton::setBoxOutlineColor(const sf::Color& color)
{
	m_original.outlineColor = color;
	updateBox();
}
void TextButton::setBoxOutlineThickness(float thickness)
{
	m_original.outlineThickness = thickness;
	updateBox();
}
void gui::TextButton::setBoxScale(const sf::Vector2f& scaleFactor)
{
	m_original.scaleFactor = scaleFactor;
	updateBox();
}
void TextButton::setSelectionFillColor(const sf::Color& color)
{
	m_selected.fillColor = color;
	updateBox();
}
void TextButton::setSelectionOutlineColor(const sf::Color& color)
{
	m_selected.outlineColor = color;
	updateBox();
}
void TextButton::setSelectionOutlineThickness(float thickness)
{
	m_selected.outlineThickness = thickness;
	updateBox();
}
void gui::TextButton::setSelectionScale(const sf::Vector2f& scaleFactor)
{
	m_selected.scaleFactor = scaleFactor;
	updateBox();
}
void TextButton::activateSelection()
{
	m_isSelected = true;
	updateBox();
}
void TextButton::deactivateSelection()
{
	m_isSelected = false;
	updateBox();
}


