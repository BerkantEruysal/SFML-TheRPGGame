//
// Created by arwen on 24.10.2025.
//

#include "TypeAScene.h"
#include <iostream>
#include "../../UI/MenuButton/MenuButton.h"
#include "../../UI/UIUtils/UIUtils.h"
#include "SFML/Graphics/Font.hpp"
#include "../../UI/Image/Image.h"



void TypeAScene::onEnter() {
    std::cout << "Type A Scene" << std::endl;


    auto background = std::make_unique<Image>(std::string_view("assets/images/brickBG.jpeg"), ui_manager, sf::Vector2f(0,0), true);

    constexpr float framePositionX = 375;
    const float framePositionY = ui_manager.getWindow().getSize().y / 2 + 5;
    auto frame = std::make_unique<Image>(std::string_view("assets/images/frame.png"), ui_manager, sf::Vector2f(framePositionX,framePositionY), false, sf::Vector2f(1.4,1.4), true);

    auto paper = std::make_unique<Image>(std::string_view("assets/images/paper.jpeg"), ui_manager, sf::Vector2f(0,0), false, sf::Vector2f(1.35,1.35), false);
    paper->m_backgroundSprite.rotate(sf::degrees(90));

    auto frameImage = std::make_unique<Image>(std::string_view("assets/images/menuBackground1.jpeg"), ui_manager, sf::Vector2f(115,120), false, sf::Vector2f(1,1), false);





    sf::Vector2f paperPosition {static_cast<float>(ui_manager.getWindow().getSize().x), 0};
    paper->m_backgroundSprite.setPosition(paperPosition);


    addUIElement(std::move(background));
    addUIElement(std::move(frameImage));
    addUIElement(std::move(frame));
    addUIElement(std::move(paper));






}

void TypeAScene::onExit() {

}

TypeAScene::TypeAScene(UIManager &uimanager) : IScene(uimanager) {


}


