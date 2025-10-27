//
// Created by arwen on 24.10.2025.
//

#include "ScrollableTextContainer.h"

ScrollableTextContainer::ScrollableTextContainer(UIManager &ui_manager, sf::Vector2f position) :
    IUIElement(position), ui_manager(ui_manager){

}

IUIElement *ScrollableTextContainer::addElementToVector(IUIElement *element) {
    m_TextElems.push_back(element);
    return element;
}

IUIElement *ScrollableTextContainer::addElementToVector(std::unique_ptr<IUIElement> element) {
    m_TextElems.push_back(element.get());
    return element.get();
}

void ScrollableTextContainer::removeElementFromVector(IUIElement *element) {
    auto it = std::find(m_TextElems.begin(), m_TextElems.end(), element);
    if (it != m_TextElems.end()) {
        m_TextElems.erase(it);
    }
}

void ScrollableTextContainer::draw(sf::RenderWindow &window) {}

sf::FloatRect ScrollableTextContainer::getGLobalBounds() {
    return m_globalBounds;
}

void ScrollableTextContainer::setPosition(const sf::Vector2f position) {
    // Empty becouse we won't need it for now.
}




