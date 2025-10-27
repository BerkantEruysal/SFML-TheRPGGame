//
// Created by arwen on 12.10.2025.
//

#ifndef CMAKESFMLPROJECT_UIUTILS_H
#define CMAKESFMLPROJECT_UIUTILS_H
#include <memory>
#include <vector>
#include "../IUIElement/IUIElement.h"
#include "../UIManager/UIManager.h"


namespace UIUtils {

    enum Position {
        CENTER,
        BOTTOM
    };

    void makeGrid(const std::vector<IUIElement*>& uiElements , Position position, UIManager& UIManager, float distance);

}


#endif //CMAKESFMLPROJECT_UIUTILS_H