

#ifndef CMAKESFMLPROJECT_Image_H
#define CMAKESFMLPROJECT_Image_H
#include <string>

#include "../IUIElement/IUIElement.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "../UIManager/UIManager.h"

class Image : public IUIElement {
public:
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    explicit Image(std::string_view path, UIManager& ui_manager, sf::Vector2f position, bool isFullscreen = false, sf::Vector2f scaleFactor = sf::Vector2f(1,1), bool isOriginCentered = false );
    void draw(sf::RenderWindow &window) override;
    void setPosition(const sf::Vector2f position) override;
    sf::FloatRect getGLobalBounds() override;
    void setOrigin(sf::Vector2f origin);
};


#endif //CMAKESFMLPROJECT_Image_H