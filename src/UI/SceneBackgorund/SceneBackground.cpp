//
// Created by arwen on 12.10.2025.
//

#include "SceneBackground.h"


SceneBackground::SceneBackground(std::string_view path, UIManager& ui_manager) : IUIElement(sf::Vector2f(0,0)) , m_backgroundTexture(path) , m_backgroundSprite(m_backgroundTexture) {
    // Calculate scale to fit window
    sf::Vector2u windowSize = ui_manager.getWindow().getSize();
    sf::Vector2u textureSize = m_backgroundTexture.getSize();

    float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);

    m_backgroundSprite.setScale(sf::Vector2f(scaleX, scaleY));

}

void SceneBackground::draw(sf::RenderWindow &window) {
    window.draw(m_backgroundSprite);
}

void SceneBackground::setPosition(const sf::Vector2f position) {
    m_backgroundSprite.setPosition(position);
}

sf::FloatRect SceneBackground::getGLobalBounds() {
    return m_backgroundSprite.getGlobalBounds();
}