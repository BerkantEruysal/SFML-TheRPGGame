//
// Created by arwen on 3.10.2025.
//

#ifndef CMAKESFMLPROJECT_CHOICEGRID_H
#define CMAKESFMLPROJECT_CHOICEGRID_H
#include "../IUIElement/IUIElement.h"
#include "../IButton/IButton.h"
#include <vector>
#include <memory>

class ChoiceGrid : public IUIElement {
private:
    std::vector<std::unique_ptr<IButton>> buttons;

public:
    explicit ChoiceGrid(std::vector<std::unique_ptr<IButton>> buttonList);
    ~ChoiceGrid() override = default;
    
    // IUIElement arayüzünden gelen metodlar


};


#endif //CMAKESFMLPROJECT_CHOICEGRID_H