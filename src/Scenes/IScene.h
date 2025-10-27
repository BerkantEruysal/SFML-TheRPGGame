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
    virtual std::vector<IUIElement*>* getUIElementPointers() {
        return &m_UIElementPointers;
    }
    virtual IUIElement* addUIElement(std::unique_ptr<IUIElement> element) {
        m_UIElementPointers.push_back(element.get());
        return ui_manager.addUIElementToVector(std::move(element));
    }


    IScene(UIManager& uimanager) : ui_manager(uimanager) {
    }



protected:
    UIManager& ui_manager;
    std::vector<IUIElement*> m_UIElementPointers;

private:

};


#endif //CMAKESFMLPROJECT_ISCENE_H