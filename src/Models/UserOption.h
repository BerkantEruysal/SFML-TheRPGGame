//
// Created by arwen on 5.11.2025.
//

#ifndef CMAKESFMLPROJECT_USEROPTIONMODEL_H
#define CMAKESFMLPROJECT_USEROPTIONMODEL_H


#include <string>

#include "TextBoxType.h"

namespace Model {
    struct UserOption {
        std::string m_text;
        Model::TextBoxType m_type;
        std::string m_speaker;
        int id;
        int groupID;
    };
}



#endif //CMAKESFMLPROJECT_USEROPTIONMODEL_H