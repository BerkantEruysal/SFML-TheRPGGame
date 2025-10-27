//
// Created by arwen on 12.10.2025.
//

#ifndef CMAKESFMLPROJECT_SCENEBACKGROUND_H
#define CMAKESFMLPROJECT_SCENEBACKGROUND_H
#include <string>

#include "../IUIElement/IUIElement.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "../UIManager/UIManager.h"

class SceneBackground : public IUIElement {
public:
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    explicit SceneBackground(std::string_view path, UIManager& ui_manager );
    void draw(sf::RenderWindow &window) override;
    void setPosition(const sf::Vector2f position) override;
    sf::FloatRect getGLobalBounds() override;
};


#endif //CMAKESFMLPROJECT_SCENEBACKGROUND_H