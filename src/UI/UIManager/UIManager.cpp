//
// Created by arwen on 29.09.2025.
//

#include "UIManager.h"

#include <iostream>
#include <vector>

UIManager::UIManager() : m_UIElements(nullptr), m_window(sf::VideoMode({800, 600}), "The RPG Game") {

}

void UIManager::setUIElements(std::vector<std::unique_ptr<IUIElement>>* uiElements) {
    m_UIElements = uiElements;
}

std::vector<std::unique_ptr<IUIElement>>* UIManager::getUIElements() {
    return m_UIElements;
}

void UIManager::render() {
    getWindow().clear(sf::Color::Black);

    if (m_UIElements != nullptr) {
        for (auto& element : *m_UIElements) {
            element->draw(getWindow());
        }
    }

    getWindow().display();
}


sf::RenderWindow& UIManager::getWindow() {
    return m_window;
}

void UIManager::handleEvent(const std::optional<sf::Event>& event){
    //check if the event is valid or not
    if (event.has_value()) {

        if (m_UIElements != nullptr) {
            for (auto& element : *m_UIElements) {
                element->handleEvent(event.value());
            }
        }
    }
}




