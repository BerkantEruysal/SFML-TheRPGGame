//
// Created by arwen on 28.09.2025.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include <SFML/Graphics.hpp>

#include "../Scenes/SceneManager.h"
#include "../UI/UIManager/UIManager.h"


class Game {

public:
    Game();
    void run();

private:
    UIManager m_UIManager {};
    SceneManager m_sceneManager;

    void processEvents();
    void update();
    void render();
};


#endif //CMAKESFMLPROJECT_GAME_H