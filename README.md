# SFML Visual Novel Engine

This project is a text-based **Role Playing Game (RPG)** and **Visual Novel** engine developed using **C++** and **SFML** (Simple and Fast Multimedia Library).

It offers players an interactive story experience where they can shape the narrative through their choices, accompanied by dynamic visuals and an atmospheric interface.

## 📖 About the Project

This game engine combines classic text-based adventures with modern visual presentation. It provides a deep narrative with backgrounds that change according to the story flow, character dialogues, and user choices.

## ✨ Features

*   **Dynamic Storytelling:** A branching dialogue tree responsive to player choices (User Choice).
*   **Advanced Scene Management:** Modular `SceneManager` structure ensuring smooth transitions between in-game scenes, menus, and different states.
*   **Layered Visual System:** `UIManager` that processes backgrounds, frames, paper textures, and scene visuals in layers.
*   **Interactive Interface:**
    *   Scrollable text boxes (`ScrollableTextContainer`).
    *   Clickable selection buttons.
    *   Keyboard and mouse interaction.
*   **Resource Management:** Singleton design pattern for performant management of game assets like fonts and images.

## 🛠 Technical Details

This project has been prepared observing modern game development principles and clean code standards.

*   **Programming Language:** C++17
*   **Graphics Engine:** SFML 3.0.2
*   **Build System:** CMake (Cross-platform support)
*   **Architecture:**
    *   **State Pattern:** For scene transitions and management.
    *   **Singleton Pattern:** For resource management (`ResourceManager`).
    *   **Component-based UI:** Flexible and reusable interface elements.

## 🚀 Installation and Compilation

You can follow the steps below to compile and run the project on your own computer.

### Requirements

*   **C++ Compiler:** C++17 supported (GCC, Clang, MSVC).
*   **CMake:** Version 3.28 or higher.
*   **Git:** To clone the project.
*   **For Linux:** SFML dependencies (can be installed with the command below).

### Step-by-Step Installation

1.  **Clone the Project:**
    ```bash
    git clone https://github.com/BerkantEruysal/sfml-repo.git
    cd sfml-repo
    ```

2.  **Dependencies for Linux Users:**
    On Ubuntu/Debian based systems:
    ```bash
    sudo apt update
    sudo apt install libxrandr-dev libxcursor-dev libxi-dev libudev-dev libfreetype-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev
    ```

3.  **Compile the Project:**
    ```bash
    cmake -B build
    cmake --build build
    ```

4.  **Launch the Game:**
    *   **Linux/macOS:**
        ```bash
        ./build/bin/main
        ```
    *   **Windows:**
        Run the file at `build/bin/Debug/main.exe`.

## 🎮 How to Play?

*   **Progression:** Use the **Space** key to skip dialogues and advance the story.
*   **Making Choices:** When options appear, click on the option you want with your mouse to direct the story.

## 📂 File Structure

*   `src/Game`: Main game loop and initialization processes.
*   `src/Scenes`: Logic for game scenes (Menu, In-Game).
*   `src/UI`: Interface components like buttons, images, and text boxes.
*   `src/Resources`: The section where font and image files are loaded and managed.
*   `src/Models`: Dialogue data and game logic structures.

---
*This project was developed to demonstrate C++ and SFML capabilities.*
