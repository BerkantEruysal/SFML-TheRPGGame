//
// Created by arwen on 28.09.2025.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include <SFML/Graphics.hpp>


class Game {

public:
    Game();
    void run();

private:
    sf::RenderWindow m_window;
    int counter {0};

    void processEvents();
    void update();
    void render();
};


#endif //CMAKESFMLPROJECT_GAME_H