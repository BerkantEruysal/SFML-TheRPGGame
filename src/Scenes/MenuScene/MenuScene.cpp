//
// Created by arwen on 29.09.2025.
//

#include "MenuScene.h"

#include <iostream>

#include "../../UI/MenuButton/MenuButton.h"
#include "../../UI/UIUtils/UIUtils.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

void MenuScene::onEnter() {
    /*std::cout << "Menu Scene" << std::endl;

    auto btn = std::make_unique<MenuButton>("MenuButonu", sf::Vector2f(100, 100));
    auto btn2 = std::make_unique<MenuButton>("MenuButonu2", sf::Vector2f(100, 100));
    MenuButton *btnPtr = btn.get();
    MenuButton *btnPtr2 = btn2.get();
    btn->onClick = [btnPtr]() {std::cout << "Clicked" << std::flush;};
    btn2->onClick = [btnPtr2]() {std::cout << "Clic" << std::flush;};

    // add button to mageGrid func,
    UIUtils::makeGrid(std::vector<IUIElement*> {btnPtr, btnPtr2}, UIUtils::CENTER, ui_manager , 10);


    // add a background image, the location of image is assets/images/menuBackground1.jpeg
    auto deneme = std::make_unique<SceneBackground>(std::string_view("assets/images/menuBackground1.jpeg"), ui_manager);

    auto *denemePtr = deneme.get();

    m_UIElements.push_back(std::move(deneme));
    m_UIElements.push_back(std::move(btn));
    m_UIElements.push_back(std::move(btn2)); */



}

void MenuScene::onExit() {

}

MenuScene::MenuScene(UIManager &uimanager) : IScene(uimanager) {


}
