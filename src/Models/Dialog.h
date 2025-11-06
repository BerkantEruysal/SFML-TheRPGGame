//
// Created by arwen on 5.11.2025.
//

#ifndef CMAKESFMLPROJECT_DIALOG_H
#define CMAKESFMLPROJECT_DIALOG_H
#include <string>
#include <vector>

#include "TextBoxType.h"

namespace Model {
    struct Dialog {
        std::string text;
        std::string speaker;
        int id;
        int nextID;
        TextBoxType type;
    };

    struct DialogGroup {
        std::vector<Dialog> dialogs;
        int id;
    };
}


inline std::vector<Model::DialogGroup> exampleDialogGroup {
    // Grup 1 - Tekli diyalog (Narator)
        {
            {
                {
                    {"Bir sabah laboratuvarda garip bir ses duyarsın.", "Narrator", 1, 2, Model::TextBoxType::Narator}
                },
                1
            },

            // Grup 2 - Tekli diyalog (User)
            {
                {
                    {"Arwen: Berkant, sistem uyarı veriyor!", "Arwen", 2, 3, Model::TextBoxType::User}
                },
                2
            },

            // Grup 3 - UserChoice (birden fazla seçenek)
            {
                {
                    {"Hemen laboratuvara git.", "Berkant", 3, 4, Model::TextBoxType::UserChoice},
                    {"Arwen'e durumu sor.", "Berkant", 4, 5, Model::TextBoxType::UserChoice},
                    {"Uyarıyı önemseme ve çalışmaya devam et.", "Berkant", 5, 6, Model::TextBoxType::UserChoice}
                },
                3
            },

            // Grup 4 - Tekli diyalog (Narator)
            {
                {
                    {"Laboratuvara koşarak girersin. Etrafta duman var.", "Narrator", 6, 7, Model::TextBoxType::Narator}
                },
                4
            },

            // Grup 5 - Tekli diyalog (User)
            {
                {
                    {"Arwen: Sistem aşırı ısınmadan dolayı kendini kapatıyor!", "Arwen", 7, 1, Model::TextBoxType::User}
                },
                5
            },

            {
                {
                    {"Sistem aşırı ısınmadan dolayı kendini kapatıyor!", "Arwen", 8 , 1, Model::TextBoxType::User}
                },
                6
            }
        }
};

#endif //CMAKESFMLPROJECT_DIALOG_H