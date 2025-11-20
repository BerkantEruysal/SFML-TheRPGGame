//
// Created by arwen on 24.10.2025.
//

#include "ScrollableTextContainer.h"

#include <iostream>
#include <utility>



ScrollableTextContainer::ScrollableTextContainer(UIManager &ui_manager, sf::Vector2f position, float width, float height) :
IUIElement(position),
m_width(width),
m_height(height),
ui_manager(ui_manager),
m_background(sf::Vector2f(width, height)),
m_firstElementAnchor(position.y),
m_scrollView(sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f( width, height)))  // Dünya koordinatları
{
    m_background.setPosition(position);
    m_background.setFillColor(sf::Color::Transparent);

    // View'in pencerede nerede görüneceğini ayarla (normalized koordinatlar)
    sf::Vector2u windowSize = ui_manager.getWindow().getSize();
    m_scrollView.setViewport(sf::FloatRect(
        sf::Vector2f(  position.x / windowSize.x,   position.y / windowSize.y),
        sf::Vector2f(width / windowSize.x,
        height / windowSize.y)
    ));
}
/*
IUIElement *ScrollableTextContainer::addTextBox(std::unique_ptr<TextBox> element) {
    auto *textBox = element.get();
    m_TextElems.push_back(std::move(element));
    return textBox;
}
*/

bool ScrollableTextContainer::removeElementFromVector(TextBox* element) {
    auto it = std::find_if(m_TextElems.begin(), m_TextElems.end(),
        [element](const std::unique_ptr<TextBox>& ptr) {
            return ptr.get() == element;
        });

    if (it != m_TextElems.end()) {
        m_TextElems.erase(it);
        return true;
    }

    return false;
}

bool ScrollableTextContainer::removeElementFromVector(size_t index) {
    if (index < m_TextElems.size()) {
        m_TextElems.erase(m_TextElems.begin() + index);
        return true;
    }
    return false;
}

void ScrollableTextContainer::draw(sf::RenderWindow &window) {
    window.draw(m_background);
    window.setView(m_scrollView);
    for (auto& element : m_TextElems) {
        element->draw(window);
    }
    window.setView(ui_manager.getWindow().getDefaultView());
}

sf::FloatRect ScrollableTextContainer::getGLobalBounds() {
    return m_globalBounds;
}

void ScrollableTextContainer::setPosition(const sf::Vector2f position) {
    // Empty because we won't need it for now.
}

IUIElement *ScrollableTextContainer::createTextBox(const Model::Dialog& dialog, int groupID,  std::function<void(Model::Dialog)> onClick) {
    //float bottomPoint {m_position.y + m_height};
    float totalSize{0};
    for (auto& element : m_TextElems) {
        if (element->m_isRemovalScheduled == false) {
            totalSize += element->getHeight() + BOX_SPACING ;
        }
    }
    sf::Vector2f calculatedPosition { 0, totalSize};
    m_TextElems.push_back(std::make_unique<TextBox>(ui_manager, m_scrollView , dialog.speaker , dialog.text,  calculatedPosition, m_width, dialog.type, dialog.id , groupID, dialog.nextID));
    m_TextElems.back()->onClick = std::move(onClick);

    if (totalSize > m_height) {
        adjustScrollToBottom();
    }

    return m_TextElems.back().get();
}

void ScrollableTextContainer::handleEvent(const sf::Event &event) {
    if (const auto* wheelScrolled = event.getIf<sf::Event::MouseWheelScrolled>()) {
        if (wheelScrolled->wheel == sf::Mouse::Wheel::Vertical) {
            float scrollSpeed = 30.0f;

            // Mouse wheel delta: pozitif = yukarı, negatif = aşağı
            // View'i ters yönde hareket ettiriyoruz (içerik doğal yönde hareket etsin)
            m_scrollView.move(sf::Vector2f(0, -wheelScrolled->delta * scrollSpeed));

            // Opsiyonel: Scroll limitlerini kontrol et
            sf::Vector2f center = m_scrollView.getCenter();

            // Minimum scroll (en üst)
            float minY = m_height / 2.0f;

            // Maximum scroll (en alt - toplam içerik yüksekliğine göre)
            float totalContentHeight = 0;
            for (auto& element : m_TextElems) {
                totalContentHeight += element->getHeight() + BOX_SPACING;
            }
            float maxY = std::max(minY, totalContentHeight - m_height / 2.0f);

            // Limitleri uygula
            center.y = std::clamp(center.y, minY, maxY);
            m_scrollView.setCenter(center);
        }
    }



    for (std::vector<IUIElement>::size_type i = 0; i < m_TextElems.size(); i++) {
        m_TextElems[i]->handleEvent(event);
    }
}

void ScrollableTextContainer::removeOptionGroup() {

    m_TextElems.erase(
        std::remove_if(
            m_TextElems.begin(),
            m_TextElems.end(),
            [ ](const std::unique_ptr<TextBox>& ptr) {
                return ptr->m_isRemovalScheduled == true; // groupID eşleşiyorsa sil
            }
        ),
        m_TextElems.end()
    );
    isTherePendingRemoval = false;

}

void ScrollableTextContainer::scheduleOptionGroupRemoval(int groupID) {
    for (auto& element : m_TextElems) {
        if (element->m_groupID == groupID) {
            element->m_isRemovalScheduled = true;
            isTherePendingRemoval = true;
        }
    }
}

void ScrollableTextContainer::adjustScrollToBottom() {
    // Toplam içerik yüksekliğini hesapla
    float totalContentHeight = 0;
    for (auto& element : m_TextElems) {
        if (!element->m_isRemovalScheduled) {
            totalContentHeight += element->getHeight() + BOX_SPACING;
        }
    }

    // View'in merkezini ayarla
    // En alttaki içeriği göstermek için: center.y = totalContentHeight - (m_height / 2)
    float newCenterY = totalContentHeight - (m_height / 2.0f);

    // Minimum limit: içerik küçükse yukarıda kalsın
    float minY = m_height / 2.0f;
    newCenterY = std::max(newCenterY, minY);

    m_scrollView.setCenter(sf::Vector2f(m_width / 2.0f, newCenterY));
}

void ScrollableTextContainer::update() {
    if (isTherePendingRemoval) {
        removeOptionGroup();
    }
}
