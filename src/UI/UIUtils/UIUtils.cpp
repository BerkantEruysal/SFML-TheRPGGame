//
// Created by arwen on 12.10.2025.
//

#include "UIUtils.h"

#include <iostream>

void UIUtils::makeGrid(const std::vector<IUIElement*>& uiElements , UIUtils::Position position, UIManager& UIManager, float distance) {
    float windowCenterX = UIManager.getWindow().getSize().x / 2;
    float windowCenterY = UIManager.getWindow().getSize().y / 2;

    float y_offset = 0;

    for (int i = 0; i < uiElements.size(); i++) {
        float heightOfElement = uiElements[i]->getGLobalBounds().size.y;
        uiElements[i]->setPosition(sf::Vector2f(windowCenterX, windowCenterY + (i * distance) + (y_offset)));
        y_offset += heightOfElement;
    }
}
