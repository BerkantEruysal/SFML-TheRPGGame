//
// Created by arwen on 27.10.2025.
//

#ifndef CMAKESFMLPROJECT_TEXTBOX_H
#define CMAKESFMLPROJECT_TEXTBOX_H
#include <functional>
#include "../IUIElement/IUIElement.h"
#include "../UIManager/UIManager.h"
#include "../../Models/Dialog.h"
#include "../../Models/TextBoxType.h"



class TextBox : public IUIElement {
public:

    void setText(std::string_view text);

    TextBox(UIManager &ui_manager, sf::View& scrollView ,  std::string_view speaker,std::string_view text, sf::Vector2f position, float width, Model::TextBoxType type, int ID, int groupID, int nextID);
    void draw(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event &event) override;
    void setPosition(sf::Vector2f position) override;
    void calculateElementPositions();
    float getHeight() const;
    std::string& getText();
    sf::FloatRect getGLobalBounds() override;
    std::function<void(Model::Dialog)> onClick;

    int m_groupID;
    int m_ID;
    int m_nextID;
    bool m_isRemovalScheduled {false};

    static int NEXT_ID;
    static int NEXT_GROUP_ID;

protected:
    void wrapText(const std::string& speaker, const std::string& text, float maxWidth);

private:
    float m_width;
    static constexpr unsigned int CHARACTER_SIZE {20};
    static constexpr unsigned int SPEAKER_CHARACTER_SIZE {25};
    static const float LINE_SPACING;
    static const sf::Color TEXT_COLOR;
    static const sf::Color SPEAKER_COLOR;
    static const float TEXT_X_AXIS_PADDING;
    static const sf::Color BG_HOVER_COLOR;
    static const sf::Color BG_COLOR;
    static const float BOX_SPACING;

    bool m_isHovered {false};
    Model::TextBoxType m_type;
    std::string m_text;
    std::string m_speaker;
    std::vector<sf::Text> m_textLines;
    sf::Text m_speakerObject;
    sf::RectangleShape m_textBackground;
    UIManager& ui_manager;
    sf::View& m_scrollView;



    void onHoverStart();
    void onHoverEnd();
};


#endif //CMAKESFMLPROJECT_TEXTBOX_H