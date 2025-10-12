//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_ISCENE_H
#define CMAKESFMLPROJECT_ISCENE_H
#include <string>
#include <vector>
#include <memory>

#include "../UI/UIManager/UIManager.h"


class IScene {
public:
    const std::string m_name;

    virtual ~IScene() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual std::vector<std::unique_ptr<IUIElement>>* getUIElements() {
        return &m_UIElements;
    }


    IScene(UIManager& uimanager) : ui_manager(uimanager) {
    }



protected:
    UIManager& ui_manager;
    std::vector<std::unique_ptr<IUIElement>> m_UIElements; // Her scene'in kendi vector'ü

private:

};


#endif //CMAKESFMLPROJECT_ISCENE_H