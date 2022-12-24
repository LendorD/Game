//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESSETEVENT_H
#define OOP_RULESSETEVENT_H
#include "Field.h"
#include "Random.h"
template<int count>
class RulesEventSet{
public:
    void operator()(Field* field){
        if(field->createField){
            field->createField = false;
            return;
        }
        int x = field->PlayerX;
        int y = field->PlayerY;
        for(int i = 0; i < count;i++ ) {
            int randPosX = randInt(0, field->getLenght() - 1);
            int randPosY = randInt(0, field->getWigth() - 1);
            int pos_ = randInt(0, static_cast<int>(field->ListSign.size()) - 1);
            if (randPosY == y && randPosX == x) { continue; }
            CellSign *sign = field->ListSign.at(pos_);
            if (sign == field->ListSign.at(0)) field->map[randPosX][randPosY].setAvailable(true);
            field->map[randPosX][randPosY].setSign(sign);
            if (pos_) {
                field->map[randPosX][randPosY].setPassable(true);
            } else {
                field->map[randPosX][randPosY].setPassable(false);
            }
        }
    };
};
#endif //OOP_RULESSETEVENT_H
