//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_IBUTTON_H
#define CMAKESFMLPROJECT_IBUTTON_H
#include <functional>
#include <string>

#include "../IUIElement/IUIElement.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


class IButton : public IUIElement{
public:

    explicit IButton(const sf::Vector2f& position) : m_position(position) {}
    virtual ~IButton() = default;


    virtual void setText(const std::string& text) = 0;
    virtual void setFont(const sf::Font& font) = 0;
    virtual void setColor(const sf::Color& color) =0;
    virtual void handleEvent(const sf::Event& event) = 0;

    std::function<void()> onClick;
    std::function<void()> onHover;

private:
    sf::Vector2f m_position;


};


#endif //CMAKESFMLPROJECT_IBUTTON_H