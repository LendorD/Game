//
// Created by Lendor on 19.09.2022.
//

#pragma once
#ifndef OOP_EVENT_H
#define OOP_EVENT_H


#include "Player.h"
class Field;
class Event{
public:
    virtual void StateEvent();
    virtual Event* clone() = 0;
    virtual ~Event() = default;
    void init(Player* player, Field* field);
protected:
//    typedef std::vector<std::vector<Cell>> field;
    Field* filed;
    Player* player;

};


#endif //OOP_EVENT_H
