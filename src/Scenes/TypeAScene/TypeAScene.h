//
// Created by arwen on 24.10.2025.
//

#ifndef CMAKESFMLPROJECT_TYPEASCENE_H
#define CMAKESFMLPROJECT_TYPEASCENE_H

#include "../IScene.h"
#include "../../Models/Dialog.h"
#include "../../UI/SceneBackgorund/SceneBackground.h"
#include "../../UI/IUIElement/IUIElement.h"
#include "../../UI/TextElements/ScrollableTextContainer.h"

class TypeAScene : public IScene {
public:
    void onEnter() override;
    void onExit() override;
    TypeAScene(UIManager& uimanager, std::vector<Model::DialogGroup> dialogGroups);

    void nextGroup(int id);
    void handleOptionSelection(Model::Dialog option, int groupID);
    void handleEvent(const sf::Event &event) override;
private:
    int m_currentGroupID = 0;
    std::vector<Model::DialogGroup> m_dialogGroups;
    ScrollableTextContainer* scrollableTextContainerRef;
};


#endif //CMAKESFMLPROJECT_TYPEASCENE_H