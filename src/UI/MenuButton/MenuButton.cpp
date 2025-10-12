//
// Created by arwen on 6.10.2025.
//

#include <utility>

#include "./MenuButton.h"

#include <iostream>

#include "../../Resources/ResourceManager.h"  // Path'i projen yapısına göre ayarla

MenuButton::MenuButton(std::string text, sf::Vector2f position) :
    IButton(position),
    m_text{std::move(text)},
    m_textObject{ResourceManager::getInstance().getFont("arial"), m_text},  // ✅
    m_shape{sf::Vector2f(200, 50)}
{
    // Text objesini ayarla
    m_textObject.setCharacterSize(24);
    m_textObject.setFillColor(sf::Color::White);

    // Shape'i ayarla
    m_shape.setPosition(position);
    m_shape.setFillColor(sf::Color(50, 50, 50));


    // Text'i butonun ortasına hizala
    sf::FloatRect textBounds = m_textObject.getLocalBounds();
    m_textObject.setOrigin(textBounds.getCenter());
    m_textObject.setPosition(
        sf::Vector2f(\
            position.x + m_shape.getSize().x / 2.0f,
            position.y + m_shape.getSize().y / 2.0f));
}

void MenuButton::setText(const std::string &text) {
    m_text = text;
    m_textObject.setString(text);
}

void MenuButton::setFont(const sf::Font &font) {
    m_textObject.setFont(font);
}

void MenuButton::setColor(const sf::Color &color) {
    m_shape.setFillColor(color);
}

void MenuButton::handleEvent(const sf::Event &event) {

    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
            if (m_shape.getGlobalBounds().contains(
        static_cast<sf::Vector2f>(mouseButtonPressed->position)))
            {
                onClick(); // ya da istediğin fonksiyon
            }

        }
    }
}

void MenuButton::draw(sf::RenderWindow &window) {
    window.draw(m_shape);
    window.draw(m_textObject);
}