//
// Created by arwen on 6.10.2025.
//

#ifndef CMAKESFMLPROJECT_MENUBUTTON_H
#define CMAKESFMLPROJECT_MENUBUTTON_H
#include "../IButton/IButton.h"


class MenuButton : public IButton {
public:
    MenuButton(std::string text, sf::Vector2f position);

    void setText(const std::string &text) override;
    void setFont(const sf::Font &font) override;
    void setColor(const sf::Color &color) override;
    void handleEvent(const sf::Event &event) override;
    void draw(sf::RenderWindow &window) override;
private:
    std::string m_text;
    sf::Text m_textObject;
    sf::RectangleShape m_shape;

};


#endif //CMAKESFMLPROJECT_MENUBUTTON_H