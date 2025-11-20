//
// Created by arwen on 29.09.2025.
//

#include "UIManager.h"

#include <iostream>
#include <vector>

#include "../SceneBackgorund/SceneBackground.h"

UIManager::UIManager() : m_window(sf::VideoMode({1536, 1023}), "The RPG Game", sf::Style::Close) {

}

std::vector<std::unique_ptr<IUIElement>>& UIManager::getUIElements() {
    return m_UIElements;
}

void UIManager::render() {
    getWindow().clear(sf::Color::Black);

    for (auto& element : m_UIElements) {
        element->draw(getWindow());
    }
    getWindow().display();
}


sf::RenderWindow& UIManager::getWindow() {
    return m_window;
}

void UIManager::handleEvent(const std::optional<sf::Event>& event){
    //check if the event is valid or not
    if (event.has_value()) {
        for (auto& element : m_UIElements) {
            element->handleEvent(event.value());
        }
    }
}

IUIElement* UIManager::addUIElementToVector(std::unique_ptr<IUIElement> element) {
    IUIElement* ptr = element.get();
    m_UIElements.push_back(std::move(element));
    return ptr;
}

void UIManager::update() {
    for (auto& element : m_UIElements) {
        element->update();
    }
}




