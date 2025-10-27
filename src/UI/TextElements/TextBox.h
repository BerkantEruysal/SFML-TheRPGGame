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
    TextBox(sf::Vector2f position, float width, TextBoxType type, int groupID = -1);
    std::string& getText();
    void setText(std::string_view text);
    std::function<void()> onClick;

    int m_groupID;
private:
    TextBoxType m_type;
    std::string m_text;
    float m_width;
};


#endif //CMAKESFMLPROJECT_TEXTBOX_H