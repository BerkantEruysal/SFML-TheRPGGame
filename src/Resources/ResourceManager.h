//
// Created by arwen on 8.10.2025.
//

#ifndef CMAKESFMLPROJECT_RESOURCEMANAGER_H
#define CMAKESFMLPROJECT_RESOURCEMANAGER_H


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class ResourceManager {
public:
    // Singleton pattern
    static ResourceManager& getInstance();
    
    // Font yönetimi
    const sf::Font& getFont(const std::string& name);
    bool loadFont(const std::string& name, const std::string& filepath);
    
    // Gelecekte texture, sound ekleyebilirsin
    // const sf::Texture& getTexture(const std::string& name);
    // bool loadTexture(const std::string& name, const std::string& filepath);
    
    // Copy ve move'u engelle (singleton)
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

private:
    ResourceManager() = default;
    
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fonts;
    // std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};


#endif //CMAKESFMLPROJECT_RESOURCEMANAGER_H