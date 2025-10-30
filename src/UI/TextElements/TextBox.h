//
// Created by arwen on 27.10.2025.
//

#ifndef CMAKESFMLPROJECT_TEXTBOX_H
#define CMAKESFMLPROJECT_TEXTBOX_H
#include <functional>

#include "../IUIElement/IUIElement.h"

enum class TextBoxType {
    Narator,
    User,
    UserChoice
};

class TextBox : public IUIElement {
public:
    void setText(std::string_view text);
    std::function<void()> onClick;
    TextBox(std::string_view text, sf::Vector2f position, float width, TextBoxType type, int groupID = -1);
    void draw(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
    void setPosition(sf::Vector2f position) override;
    std::string& getText();
    sf::FloatRect getGLobalBounds() override;

    int m_groupID;
private:
    float m_width;
    unsigned int m_characterSize {20};
    TextBoxType m_type;
    std::string m_text;

    sf::Text m_textObject;


};


#endif //CMAKESFMLPROJECT_TEXTBOX_H