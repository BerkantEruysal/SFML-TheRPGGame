//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_UIELEMENT_H
#define CMAKESFMLPROJECT_UIELEMENT_H
#include <SFML/Graphics.hpp>

class IUIElement {
public:
    explicit IUIElement(sf::Vector2f position) : m_position(position) {}
    virtual ~IUIElement() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void handleEvent(const sf::Event& event) {}
    virtual void setPosition (sf::Vector2f position) = 0;
    virtual sf::FloatRect getGLobalBounds() = 0;
    virtual void cleanup() {}
    virtual void update(){};
protected:
    sf::Vector2f m_position;
private:

};


#endif //CMAKESFMLPROJECT_UIELEMENT_H