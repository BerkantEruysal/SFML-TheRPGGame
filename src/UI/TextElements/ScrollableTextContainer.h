//
// Created by arwen on 24.10.2025.
//

#ifndef CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#define CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#include <memory>
#include <vector>

#include "TextBox.h"
#include  "../IUIElement/IUIElement.h"
#include "../UIManager/UIManager.h"

class ScrollableTextContainer : public IUIElement {
public:

    ScrollableTextContainer(UIManager& ui_manager, sf::Vector2f position, float width, float height);

    //IUIElement* addTextBox(std::unique_ptr<TextBox> element);
    IUIElement* createTextBox(std::string_view text, TextBoxType type, int groupID = -1);

    bool removeElementFromVector(TextBox*);
    bool removeElementFromVector(size_t index);

    void draw(sf::RenderWindow &window) override;
    void setPosition(sf::Vector2f position) override;
    sf::FloatRect getGLobalBounds() override;

private:
    float m_width;
    float m_height;
    float m_scrollValue {0};
    sf::RectangleShape m_background;
    UIManager& ui_manager;
    std::vector<std::unique_ptr<IUIElement>> m_TextElems;
    sf::FloatRect m_globalBounds;

};


#endif //CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H