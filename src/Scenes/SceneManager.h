//
// Created by arwen on 29.09.2025.
//

#ifndef CMAKESFMLPROJECT_SCENEMANAGER_H
#define CMAKESFMLPROJECT_SCENEMANAGER_H
#include <memory>

#include "IScene.h"
#include "SceneType.h"


class UIManager;

class SceneManager {
public:
    void setActiveScene(SceneType sceneType);
    SceneManager(UIManager& uimanager);
    void initialize();
    void handleEvent(const std::optional<sf::Event>& event);

private:
    std::unique_ptr<IScene> m_activeScene;
    UIManager& m_uimanager;
    std::unique_ptr<IScene> createScene(SceneType sceneType);



};


#endif //CMAKESFMLPROJECT_SCENEMANAGER_H