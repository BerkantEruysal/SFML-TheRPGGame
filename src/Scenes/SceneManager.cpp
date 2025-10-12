//
// Created by arwen on 29.09.2025.
//

#include "SceneManager.h"

#include <stdexcept>

#include "SceneType.h"
#include "MenuScene/MenuScene.h"

SceneManager::SceneManager(UIManager &uimanager):
 m_uimanager(uimanager){

}


void SceneManager::setActiveScene(SceneType sceneType) {
    if (m_activeScene) {
        m_activeScene->onExit();
    }

    m_uimanager.setUIElements(nullptr);

    m_activeScene = createScene(sceneType);
    m_activeScene->onEnter();

    m_uimanager.setUIElements(m_activeScene->getUIElements());
}

std::unique_ptr<IScene> SceneManager::createScene(SceneType sceneType) {
    switch (sceneType) {
        case SceneType::Menu:
            return std::make_unique<MenuScene>(m_uimanager);
        default:
            throw std::runtime_error("Unknown scene type");
    }
}

void SceneManager::initialize() {
    setActiveScene(SceneType::Menu);
}