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
    

    if (!rm.loadFont("arial", "assets/fonts/arial.ttf")
        || !rm.loadFont("crimsonBold", "assets/fonts/CrimsonText-Bold.ttf")
        || !rm.loadFont("crimsonBoldItalic", "assets/fonts/CrimsonText-BoldItalic.ttf")
        || !rm.loadFont("crimsonItalic", "assets/fonts/CrimsonText-Italic.ttf")
        || !rm.loadFont("crimson", "assets/fonts/CrimsonText-Regular.ttf")
        || !rm.loadFont("crimsonSemiBold", "assets/fonts/CrimsonText-SemiBold.ttf")
        || !rm.loadFont("crimsonSemiBoldItalic", "assets/fonts/CrimsonText-SemiBoldItalic.ttf"))
    {
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
        m_sceneManager.handleEvent(event);
    }
}

void Game::update() {
    m_UIManager.update();
    m_sceneManager.update();
}

void Game::render() {
    m_UIManager.render();
}