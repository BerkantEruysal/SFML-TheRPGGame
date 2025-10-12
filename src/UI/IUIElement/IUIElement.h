//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_UIELEMENT_H
#define CMAKESFMLPROJECT_UIELEMENT_H
#include <SFML/Graphics.hpp>

class IUIElement {
public:
    virtual ~IUIElement() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void handleEvent(const sf::Event& event) {};
};


#endif //CMAKESFMLPROJECT_UIELEMENT_H