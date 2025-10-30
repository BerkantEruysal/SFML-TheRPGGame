//
// Created by arwen on 27.10.2025.
//

#include "TextBox.h"

#include <iostream>

#include "../../Resources/ResourceManager.h"

TextBox::TextBox(std::string_view text, sf::Vector2f position, float width, TextBoxType type, int groupID):
m_text(text),
IUIElement(position),
m_width(width),
m_type(type),
m_groupID(groupID),
m_textObject(ResourceManager::getInstance().getFont("arial"), m_text, m_characterSize)
{
 m_textObject.setCharacterSize(m_characterSize);
 m_textObject.setFillColor(sf::Color::Black);
 m_textObject.setString(m_text);
 m_textObject.setPosition(position);

}

std::string& TextBox::getText() {
 return m_text;
}

void TextBox::setText(const std::string_view text) {
 m_text = text;
}

void TextBox::draw(sf::RenderWindow &window) {
  window.draw(m_textObject);
}

sf::FloatRect TextBox::getGLobalBounds() {
 return m_textObject.getGlobalBounds();
}

void TextBox::setPosition(const sf::Vector2f position) {
 m_textObject.setPosition(position);
}

void TextBox::handleEvent(const sf::Event &event) {
  // TODO : Hover and Click events.
}

