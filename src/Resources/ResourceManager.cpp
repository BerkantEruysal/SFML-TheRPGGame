//
// Created by arwen on [date]
//

#include "ResourceManager.h"
#include <stdexcept>

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

bool ResourceManager::loadFont(const std::string& name, const std::string& filepath) {
    // Zaten yüklenmişse tekrar yükleme
    if (m_fonts.find(name) != m_fonts.end()) {
        return true;
    }
    
    auto font = std::make_unique<sf::Font>();
    if (!font->openFromFile(filepath)) {
        return false;
    }
    
    m_fonts[name] = std::move(font);
    return true;
}

const sf::Font& ResourceManager::getFont(const std::string& name) {
    auto it = m_fonts.find(name);
    if (it == m_fonts.end()) {
        throw std::runtime_error("Font not found: " + name);
    }
    return *(it->second);
}