cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.h
        src/UI/IButton/IButton.h
        src/UI/UIManager/UIManager.cpp
        src/UI/UIManager/UIManager.h
        src/UI/IUIElement/IUIElement.h
        src/Scenes/IScene.h
        src/Scenes/SceneManager.cpp
        src/Scenes/SceneManager.h
        src/Scenes/SceneType.h
        src/Scenes/MenuScene/MenuScene.cpp
        src/Scenes/MenuScene/MenuScene.h
        src/UI/ChoiceGrid/ChoiceGrid.cpp
        src/UI/ChoiceGrid/ChoiceGrid.h
        src/UI/MenuButton/MenuButton.cpp
        src/UI/MenuButton/MenuButton.h
        src/Resources/ResourceManager.cpp
        src/Resources/ResourceManager.h
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)
