//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_PLAYERMOVE_H
#define OOP_PLAYERMOVE_H

#include "Field.h"
#include "Player.h"
#include "fstream"
#include "Up.h"
#include "down.h"
#include "left.h"
#include "right.h"
class PlayerMove {
    PlayerMove(Field* map, Player* player);
    ~PlayerMove();
    Field* map;
    Player* player;
    void Move(Field* map, char q);
    void ReadTxt();
    std::ifstream in;
    char up;
    char down;
    char left;
    char right;
};


#endif //OOP_PLAYERMOVE_H
