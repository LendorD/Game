//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_PLAYERMOVE_H
#define OOP_PLAYERMOVE_H

#include <map>
#include "stdio.h"
#include "regex"
#include "Field.h"
#include "fstream"
#include "up.h"
#include "down.h"
#include "left.h"
#include "right.h"
class PlayerMove {
public:
    enum action{Up, Down, Right, Left};
    std::map<char, enum action> MovesTable;
    PlayerMove(Field* map);
    ~PlayerMove() = default;
    Field* map;
    void Move(Field* map, char q);
    void ReadTxt();
    std::string line;
    std::ifstream in;
    up UpMove;
    down DownMove;
    right RightMove;
    left LeftMove;

};


#endif //OOP_PLAYERMOVE_H
