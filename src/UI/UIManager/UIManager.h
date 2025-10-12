//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_UIMANAGER_H
#define CMAKESFMLPROJECT_UIMANAGER_H
#include <vector>
#include <memory>

#include "../IButton/IButton.h"
#include "SFML/Graphics/RenderWindow.hpp"


class UIManager {

public:
    UIManager();
    void setUIElements(std::vector<std::unique_ptr<IUIElement>>* uiElements);
    std::vector<std::unique_ptr<IUIElement>>* getUIElements();
    sf::RenderWindow& getWindow();
    void render();
    void handleEvent(const std::optional<sf::Event>& event);



private:
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<IUIElement>>* m_UIElements; // Pointer to scene's vector


};


#endif //CMAKESFMLPROJECT_UIMANAGER_H