//
// Created by arwen on 12.10.2025.
//

#include "Image.h"

#include <iostream>


Image::Image(std::string_view path, UIManager& ui_manager, sf::Vector2f position, bool isFullscreen, sf::Vector2f scaleFactor, bool isOriginCentered) : IUIElement(position) , m_backgroundTexture(path) , m_backgroundSprite(m_backgroundTexture) {

    if (isOriginCentered) {
        //make origin center
        const float width = m_backgroundTexture.getSize().x;
        const float height = m_backgroundTexture.getSize().y;
        setOrigin(sf::Vector2f(width / 2, height / 2));
    }

    Image::setPosition(position);
    if (isFullscreen) {
        // Calculate scale to fit window
        const sf::Vector2u windowSize = ui_manager.getWindow().getSize();
        const sf::Vector2u textureSize = m_backgroundTexture.getSize();

        float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x);
        float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);

        m_backgroundSprite.setScale(sf::Vector2f(scaleX, scaleY));
    }else {
        m_backgroundSprite.setScale(scaleFactor);
    }
}

void Image::draw(sf::RenderWindow &window) {
    window.draw(m_backgroundSprite);
}

void Image::setPosition(const sf::Vector2f position) {
    m_backgroundSprite.setPosition(position);
}

sf::FloatRect Image::getGLobalBounds() {
    return m_backgroundSprite.getGlobalBounds();
}

void Image::setOrigin(sf::Vector2f origin) {
    m_backgroundSprite.setOrigin(origin);
}