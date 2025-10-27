//
// Created by arwen on 24.10.2025.
//

#ifndef CMAKESFMLPROJECT_TYPEASCENE_H
#define CMAKESFMLPROJECT_TYPEASCENE_H

#include "../IScene.h"
#include "../../UI/SceneBackgorund/SceneBackground.h"
#include "../../UI/IUIElement/IUIElement.h"

class TypeAScene : public IScene {
public:
    void onEnter() override;
    void onExit() override;



    TypeAScene(UIManager& uimanager);

private:


};


#endif //CMAKESFMLPROJECT_TYPEASCENE_H