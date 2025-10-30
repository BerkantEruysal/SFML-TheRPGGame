//
// Created by arwen on 24.10.2025.
//

#include "ScrollableTextContainer.h"

#include <iostream>

ScrollableTextContainer::ScrollableTextContainer(UIManager &ui_manager, sf::Vector2f position, float width, float height) :
    IUIElement(position), m_width(width), m_height(height), ui_manager(ui_manager), m_background(sf::Vector2f(width, height)){
    m_background.setPosition(position);
    m_background.setFillColor(sf::Color::Transparent);
}
/*
IUIElement *ScrollableTextContainer::addTextBox(std::unique_ptr<TextBox> element) {
    auto *textBox = element.get();
    m_TextElems.push_back(std::move(element));
    return textBox;
}
*/

bool ScrollableTextContainer::removeElementFromVector(TextBox* element) {
    auto it = std::find_if(m_TextElems.begin(), m_TextElems.end(),
        [element](const std::unique_ptr<IUIElement>& ptr) {
            return ptr.get() == element;
        });

    if (it != m_TextElems.end()) {
        m_TextElems.erase(it);
        return true;
    }

    return false;
}

bool ScrollableTextContainer::removeElementFromVector(size_t index) {
    if (index < m_TextElems.size()) {
        m_TextElems.erase(m_TextElems.begin() + index);
        return true;
    }
    return false;
}



void ScrollableTextContainer::draw(sf::RenderWindow &window) {
    window.draw(m_background);
    for (auto& element : m_TextElems) {
        element->draw(window);
    }
}

sf::FloatRect ScrollableTextContainer::getGLobalBounds() {
    return m_globalBounds;
}

void ScrollableTextContainer::setPosition(const sf::Vector2f position) {
    // Empty becouse we won't need it for now.
}

IUIElement *ScrollableTextContainer::createTextBox(std::string_view text, TextBoxType type, int groupID) {
    //float bottomPoint {m_position.y + m_height};
    float bottomPoint {m_position.y};
    sf::Vector2f calculatedPosition { m_position.x, bottomPoint + (m_TextElems.size() * 30)};
    m_TextElems.push_back(std::make_unique<TextBox>(text , calculatedPosition, m_width, type, groupID));
    return m_TextElems.back().get();
}



