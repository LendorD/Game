//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESSPAWNENEMY_H
#define OOP_RULESSPAWNENEMY_H
#include "Field.h"
#include "Random.h"
template<int count>
class RulesEnemySpawn{
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
            if (randPosY == y and randPosX == x) {
                i--;
                continue;
            }
            field->map[randPosX][randPosY].setSign(new EnemySign);
            field->map[randPosX][randPosY].setAvailable(false);

        }
    }
};
#endif //OOP_RULESSPAWNENEMY_H
