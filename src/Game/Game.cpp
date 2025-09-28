//
// Created by arwen on 28.09.2025.
//

#include "Game.h"
#include <iostream>
#include <string>

Game::Game():
m_window(sf::VideoMode({800, 600}), "The RPG Game") {

}

void Game::run() {
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (const std::optional event = m_window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_window.close();
        }

        if (event->is<sf::Event::MouseButtonPressed>()) {
            counter++;
        }
    }
}

void Game::update() {

}

void Game::render() {
    m_window.clear(sf::Color::Black);

    sf::Font font("assets/fonts/arial.ttf");

    sf::Text text(font);
    text.setString("Naber mudur ? " + std::to_string(counter));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);

    m_window.draw(text);

    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Blue);
    button.setPosition({300,400});

    sf::Text buttonText(font, "Bu bir buton", 16);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition({button.getPosition().x + 50, button.getPosition().y + 10});

    m_window.draw(button);
    m_window.draw(buttonText);



    m_window.display();
}