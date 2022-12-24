//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESSPAWNPLAYER_H
#define OOP_RULESSPAWNPLAYER_H
#include "Field.h"
template<int x = 0, int y=0>
class RulesPlayerSpawn{
public:
    void operator()(Field* field){
        if(field->createField){
            field->createField = false;
            return;
        }
        field->map[x][y].setSign(new PlayerSign);
        field->PlayerX = x;
        field->PlayerY = y;
    };
};
#endif //OOP_RULESSPAWNPLAYER_H
