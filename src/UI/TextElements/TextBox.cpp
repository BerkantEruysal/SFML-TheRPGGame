//
// Created by arwen on 27.10.2025.
//

#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "../../Resources/ResourceManager.h"


const float TextBox::LINE_SPACING = 12.0f;
const sf::Color TextBox::TEXT_COLOR = sf::Color (43,29,20);
const sf::Color TextBox::SPEAKER_COLOR = sf::Color (128,20,20);
const sf::Color TextBox::OPTION_COLOR = sf::Color (128,20,20);
const float TextBox::TEXT_X_AXIS_PADDING = 50.0f;
const sf::Color TextBox::BG_HOVER_COLOR = sf::Color(40, 30, 20, 0);
const sf::Color TextBox::BG_COLOR =  sf::Color(0, 0, 0, 0);
const sf::Color TextBox::HOVER_TEXT_COLOR = sf::Color (128,20,20);
const float TextBox::BOX_SPACING = 0.0f;
int TextBox::NEXT_ID = 0;
int TextBox::NEXT_GROUP_ID = 0;


TextBox::TextBox(UIManager& ui_manager, sf::View& scrollView ,std::string_view speaker, std::string_view text,  sf::Vector2f position, float width, Model::TextBoxType type, int ID, int groupID, int nextID, int optionNumber):
m_text(text),
m_speaker(speaker),
IUIElement(position),
m_width(width),
m_type(type),
m_groupID(groupID),
m_nextID(nextID),
m_ID(ID),
ui_manager(ui_manager),
m_scrollView(scrollView),
m_optionNumber(optionNumber),

m_speakerObject(ResourceManager::getInstance().getFont("crimsonBoldItalic"), sf::String::fromUtf8(m_speaker.begin(), m_speaker.end()), TextBox::SPEAKER_CHARACTER_SIZE)

{
     m_speakerObject.setCharacterSize(TextBox::SPEAKER_CHARACTER_SIZE);

    if (m_type == Model::TextBoxType::UserChoice) {
        m_speakerObject.setFillColor(TextBox::OPTION_COLOR);
        m_speakerObject.setString(">");
        m_speakerObject.setCharacterSize(TextBox::OPTION_CHARACTER_SIZE);
    }else if (m_type == Model::TextBoxType::Narator) {
        m_speakerObject.setFillColor(TextBox::SPEAKER_COLOR);
        m_speakerObject.setString(sf::String::fromUtf8(m_speaker.begin(), m_speaker.end()));
    }else {
        m_speakerObject.setFillColor(TextBox::SPEAKER_COLOR);
        m_speakerObject.setString(sf::String::fromUtf8(m_speaker.begin(), m_speaker.end()));
    }


     wrapText(std::string{speaker}, std::string{text} , m_width - BOX_SPACING * 2);

     calculateElementPositions();
    m_textBackground.setSize(sf::Vector2f(m_width, getHeight()));
    m_textBackground.setPosition(position);
    m_textBackground.setFillColor(BG_COLOR);

}

std::string& TextBox::getText() {
 return m_text;
}

void TextBox::setText(const std::string_view text) {
 m_text = text;
}

void TextBox::draw(sf::RenderWindow &window) {
    window.draw(m_textBackground);
    window.draw(m_speakerObject);
    for (auto& line : m_textLines) {
        window.draw(line);
    }
}

sf::FloatRect TextBox::getGLobalBounds() {
 return m_textBackground.getGlobalBounds();
}

void TextBox::setPosition(const sf::Vector2f position) {
    // TODO
}

void TextBox::handleEvent(const sf::Event &event) {
    const sf::RenderWindow &window = ui_manager.getWindow();
    if (m_type == Model::TextBoxType::UserChoice) {
        if ( auto* mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
            // Pixel koordinatlarını pencere koordinatlarına çevir
            sf::Vector2f mousePos = window.mapPixelToCoords(mouseMoved->position, m_scrollView);

            bool isMouseInside = m_textBackground.getGlobalBounds().contains(mousePos);

            if (isMouseInside && !m_isHovered) {
                m_isHovered = true;
                onHoverStart();
            }
            else if (!isMouseInside && m_isHovered) {
                m_isHovered = false;
                onHoverEnd();
            }
        }else if (auto* mouseButton = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseButton->button == sf::Mouse::Button::Left) {
                if (m_isHovered && onClick) {

                    onClick({
                    m_text,
                    m_speaker,
                        m_ID,
                        m_nextID,
                        m_type,
                    });
                }
            }
        }


    }

}

void TextBox::wrapText(const std::string& speaker, const std::string& text, float maxWidth) {
    m_textLines.clear();

    const sf::Font& font = ResourceManager::getInstance().getFont("crimson");

    // Speaker'ı ayarla (sadece ilk satır için)

    m_speakerObject.setString(speaker.empty() ? sf::String() : m_speakerObject.getString() + sf::String(" "));

    const float speakerWidth = speaker.empty() ? 0.0f : m_speakerObject.getLocalBounds().size.x;

    // Geçici text objesi (genişlik hesaplamaları için)
    sf::Text tempText{font};
    tempText.setCharacterSize(TextBox::CHARACTER_SIZE);

    // Kelimelere ayır
    std::vector<std::string> words;
    std::istringstream ss(text);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    if (words.empty()) return;

    std::string currentLine = "";
    float currentWidth = 0.0f;
    bool isFirstLine = true;

    for (size_t i = 0; i < words.size(); ++i) {
        std::string testLine = currentLine.empty() ? words[i] : currentLine + " " + words[i];
        tempText.setString(sf::String::fromUtf8(testLine.begin(), testLine.end()));
        float testWidth = tempText.getLocalBounds().size.x;

        // İlk satırda speaker genişliğini de hesaba kat
        float availableWidth = isFirstLine ? (maxWidth - speakerWidth) : maxWidth;

        if (testWidth <= availableWidth) {
            // Kelime sığıyor
            currentLine = testLine;
            currentWidth = testWidth;
        } else {
            // Kelime sığmıyor, mevcut satırı kaydet
            if (!currentLine.empty()) {
                sf::Text lineText {font};
                lineText.setCharacterSize(TextBox::CHARACTER_SIZE);
                lineText.setString(sf::String::fromUtf8(currentLine.begin(), currentLine.end()));
                lineText.setFillColor(TextBox::TEXT_COLOR);
                m_textLines.push_back(lineText);

                isFirstLine = false;
            }

            // Yeni satıra geç
            currentLine = words[i];
            tempText.setString(sf::String::fromUtf8(words[i].begin(), words[i].end()));
            currentWidth = tempText.getLocalBounds().size.x;

            // Eğer tek kelime bile sığmıyorsa (çok uzun kelime durumu)
            if (currentWidth > maxWidth) {
                // Kelimeyi olduğu gibi ekle, taşmasına izin ver
                sf::Text lineText {font};
                lineText.setCharacterSize(TextBox::CHARACTER_SIZE);
                lineText.setString(sf::String::fromUtf8(currentLine.begin(), currentLine.end()));
                lineText.setFillColor(TextBox::TEXT_COLOR);
                m_textLines.push_back(lineText);
                currentLine = "";
                currentWidth = 0.0f;
            }
        }
    }

    // Son satırı ekle
    if (!currentLine.empty()) {
        sf::Text lineText {font};
        lineText.setCharacterSize(TextBox::CHARACTER_SIZE);
        lineText.setString(sf::String::fromUtf8(currentLine.begin(), currentLine.end()));
        lineText.setFillColor(TextBox::TEXT_COLOR);
        m_textLines.push_back(lineText);
    }

}

void TextBox::calculateElementPositions() {
    float shiftValue;
    if (m_type == Model::TextBoxType::UserChoice) {
        shiftValue = 0;
    }else {
        shiftValue = TextBox::SHIFT_VALUE;
    }

    m_speakerObject.setPosition(sf::Vector2f(m_position.x + BOX_SPACING, m_position.y + BOX_SPACING));
    const float speakerWidth = m_speakerObject.getLocalBounds().size.x;
    const float speakerHeight = m_speakerObject.getLocalBounds().size.y;
    const float lineHeight = m_textLines[0].getLocalBounds().size.y;
    m_textLines[0].setPosition(sf::Vector2f(m_position.x + speakerWidth + BOX_SPACING, m_position.y + shiftValue + BOX_SPACING ));
    for (int i = 1; i < m_textLines.size(); ++i) {
        m_textLines[i].setPosition(sf::Vector2f(m_position.x + BOX_SPACING, m_position.y + (TextBox::LINE_SPACING * i) + (lineHeight * i) + shiftValue + BOX_SPACING));
    }
}

float TextBox::getHeight() const {
    float height {0};
    height += m_speakerObject.getLocalBounds().size.y;
    for (const auto& line : m_textLines) {
        height += line.getLocalBounds().size.y;
    }
    height += TextBox::LINE_SPACING * (m_textLines.size() - 1) + BOX_SPACING * 2;
    return height;
}

void TextBox::onHoverStart() {
    m_textBackground.setFillColor(BG_HOVER_COLOR);
    for (auto& line : m_textLines) {
        line.setFillColor(TextBox::HOVER_TEXT_COLOR);
    }

}

void TextBox::onHoverEnd() {
    m_textBackground.setFillColor(BG_COLOR);
    for (auto& line : m_textLines) {
        line.setFillColor(TextBox::TEXT_COLOR);
    }

}





