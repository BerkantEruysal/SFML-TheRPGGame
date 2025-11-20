//
// Created by arwen on 24.10.2025.
//

#ifndef CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#define CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#include <memory>
#include <vector>

#include "TextBox.h"
#include "../../Models/Dialog.h"
#include  "../IUIElement/IUIElement.h"
#include "../UIManager/UIManager.h"

class ScrollableTextContainer : public IUIElement {
public:

    ScrollableTextContainer(UIManager& ui_manager, sf::Vector2f position, float width, float height);

    //IUIElement* addTextBox(std::unique_ptr<TextBox> element);
    IUIElement* createTextBox(const Model::Dialog& dialog, int groupID,  std::function<void(Model::Dialog)> onClick);

    bool removeElementFromVector(TextBox*);
    bool removeElementFromVector(size_t index);

    void draw(sf::RenderWindow &window) override;
    void setPosition(sf::Vector2f position) override;
    sf::FloatRect getGLobalBounds() override;
    void handleEvent(const sf::Event &event) override;
    void removeOptionGroup();
    void scheduleOptionGroupRemoval(int groupID);
    bool isTherePendingRemoval {false};
    void update() override;

private:
    static constexpr float BOX_SPACING {10.0f};
    float m_width;
    float m_height;
    float m_scrollValue {0};
    float m_firstElementAnchor;
    sf::RectangleShape m_background;
    sf::View m_scrollView;
    UIManager& ui_manager;
    std::vector<std::unique_ptr<TextBox>> m_TextElems;
    sf::FloatRect m_globalBounds;
    void adjustScrollToBottom();


};


#endif //CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H