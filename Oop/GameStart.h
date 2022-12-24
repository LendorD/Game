//
// Created by Lendor on 30.11.2022.
//

#ifndef OOP_GAMESTART_H
#define OOP_GAMESTART_H
#include <iostream>
#include "Field/FieldView.h"
#include "Logs/LogPrint.h"
#include "Comands/PlayerMove.h"
#include "GeneratorField/LevelField.h"
#include "SaveGame/SaveLevel.h"
class GameStart {
public:
    GameStart() = default;
    void StartGame();
    int FieldLevel;
    int Logs;
    int lvlLogs = 0;
    bool checkLose;
    int ChoseMove;
    char action;
    LogReader::LogLevel levelLog;
    LogReader *logs = new LogReader;
    LevelField lvlField;
    Field* field;
    FieldView start;
    SaveLevel SaveLevel;
};


#endif //OOP_GAMESTART_H
