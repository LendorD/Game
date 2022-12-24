//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESEXITPOS_H
#define OOP_RULESEXITPOS_H
#include "Field.h"
template<int x, int y>
class RulesPosExit{
public:
    void operator()(Field* field){
        if(field->createField){
            field->createField = false;
            return;
        }
        if(x < 0 or x > field->getLenght() - 1) return;
        if(y < 0 or y > field->getWigth() - 1) return;
        field->ExitPosX = x;
        field->ExitPosY = y;
        int posX = field->PlayerX;
        int posY = field->PlayerY;
        if(posX == x and posY == y) return;
        else{
            field->map[x][y].setSign(new ExitSign);
            field->map[x][y].setAvailable(false);
        }
    }
};
#endif //OOP_RULESEXITPOS_H
