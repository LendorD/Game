//
// Created by Lendor on 14.12.2022.
//

#ifndef OOP_SAVELEVEL_H
#define OOP_SAVELEVEL_H

#include <filesystem>
#include <fstream>
#include <ostream>
#include "Field.h"
#include "Errors/FileDelete.h"

class SaveLevel {
    std::ofstream on;
    std::ifstream in;
    std::string line;
    std::string er = "Field.txt";
    ErrorsFile errorsF;
    ErrorsPlayer errorsP;
    ErrorsBit errorsB;
    int len;
    int wig;
    bool av;
    int sizeF;
    std::string file = "Field.txt";
public:
    SaveLevel() = default;
    void SaveLvl(Field* field);
    void UploadLvl(Field* field);
    void CreateFile();
    ~SaveLevel();
};


#endif //OOP_SAVELEVEL_H
