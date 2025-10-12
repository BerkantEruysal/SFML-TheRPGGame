//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_MENUSCENE_H
#define CMAKESFMLPROJECT_MENUSCENE_H
#include "../IScene.h"


class MenuScene : public IScene {
public:
    void onEnter() override;
    void onExit() override;



    MenuScene(UIManager& uimanager);

};


#endif //CMAKESFMLPROJECT_MENUSCENE_H