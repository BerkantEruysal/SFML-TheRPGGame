//
// Created by arwen on 28.09.2025.
//

#include "Game.h"
#include "../Resources/ResourceManager.h"
#include <iostream>
#include <string>

Game::Game():
 m_sceneManager(m_UIManager)
{

    
    // Tüm fontları başlangıçta yükle
    auto& rm = ResourceManager::getInstance();
    

    if (!rm.loadFont("arial", "assets/fonts/arial.ttf")) {
        std::cerr << "ERROR: Failed to load arial font" << std::endl;
        throw std::runtime_error("Failed to load arial font");
    }

    

}

void Game::run() {


    m_sceneManager.initialize();
    while (m_UIManager.getWindow().isOpen()) {
        processEvents();
        update();
        render();
    }
    
    std::cout << "Game loop ended!" << std::endl;
}

void Game::processEvents() {
    while (auto event = m_UIManager.getWindow().pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            std::cout << "Close event received!" << std::endl;
            m_UIManager.getWindow().close();
        }

        m_UIManager.handleEvent(event);
    }
}

void Game::update() {

}

void Game::render() {
    m_UIManager.render();
}