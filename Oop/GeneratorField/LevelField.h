//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_LEVELFIELD_H
#define OOP_LEVELFIELD_H

#include <map>
#include <functional>
#include "Generator.h"
#include "RulesCharacteristicPlayer.h"
#include "RulesExitPos.h"
#include "RulesSetEvent.h"
#include "RulesSizeField.h"
#include "RulesSpawnEnemy.h"
#include "RulesSpawnPlayer.h"

class LevelField{
public:
    Generator<
            RulesFieldSize<15, 15>,
            RulesPlayerSpawn<5, 7>,
            RulesPosExit<1, 1>,
            RulesEventSet<30>,
            RulesEnemySpawn<10>,
            RulesPlayerCharacteristic<0, 30>
    > level1;
    Generator<
            RulesFieldSize<5, 5>,
            RulesPlayerSpawn<1, 1>,
            RulesEventSet<3>,
            RulesEnemySpawn<0>,
            RulesPlayerCharacteristic<0, 20>,
            RulesPosExit<2, 2>
    > level2;
    Field* levelOne = level1.generator();
    Field* levelTwo = level2.generator();
    Field* levelStandart = new Field;
    Field* ChoiceLevel(int lvl){
        if(lvl == 1)levelStandart = levelOne;
        if(lvl == 2)levelStandart = levelTwo;
    return levelStandart;
     }
};

#endif //OOP_LEVELFIELD_H
