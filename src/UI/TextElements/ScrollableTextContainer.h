//
// Created by arwen on 24.10.2025.
//

#ifndef CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#define CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H
#include <memory>
#include <vector>
#include  "../IUIElement/IUIElement.h"
#include "../UIManager/UIManager.h"

class ScrollableTextContainer : public IUIElement {
public:

    ScrollableTextContainer(UIManager& ui_manager, sf::Vector2f position);

    IUIElement* addElementToVector(IUIElement* element);
    IUIElement* addElementToVector(std::unique_ptr<IUIElement> element);
    void removeElementFromVector(IUIElement*);

    void draw(sf::RenderWindow &window) override;
    void setPosition(sf::Vector2f position) override;
    sf::FloatRect getGLobalBounds() override;

private:
    std::vector<IUIElement*> m_TextElems;
    UIManager& ui_manager;
    sf::FloatRect m_globalBounds;
};


#endif //CMAKESFMLPROJECT_SCROLLABLETEXTCONTAINER_H