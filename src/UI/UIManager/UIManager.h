//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_UIMANAGER_H
#define CMAKESFMLPROJECT_UIMANAGER_H
#include <vector>
#include <memory>

#include "../IButton/IButton.h"
#include "SFML/Graphics/RenderWindow.hpp"


class SceneBackground;

class UIManager {

public:
    UIManager();

    std::vector<std::unique_ptr<IUIElement>>& getUIElements();
    sf::RenderWindow& getWindow();
    void render();
    void handleEvent(const std::optional<sf::Event>& event);
    IUIElement* addUIElementToVector(std::unique_ptr<IUIElement> element);
    void update();



private:
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<IUIElement>> m_UIElements;


};


#endif //CMAKESFMLPROJECT_UIMANAGER_H