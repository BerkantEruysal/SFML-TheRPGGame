//
// Created by arwen on 29.09.2025.
//

#include "MenuScene.h"

#include <iostream>

#include "../../UI/MenuButton/MenuButton.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

void MenuScene::onEnter() {
    std::cout << "Menu Scene" << std::endl;

    auto btn = std::make_unique<MenuButton>("MenuButonu", sf::Vector2f(100, 100));
    MenuButton *btnPtr = btn.get();
    btn->onClick = [btnPtr]() {std::cout << "Clicked" << std::flush;};

    m_UIElements.push_back(std::move(btn));

}

void MenuScene::onExit() {

}

MenuScene::MenuScene(UIManager &uimanager) : IScene(uimanager) {

}
