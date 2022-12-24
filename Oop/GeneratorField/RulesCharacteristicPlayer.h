//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESCHARACTERISTICPLAYER_H
#define OOP_RULESCHARACTERISTICPLAYER_H
#include "Field.h"
template<int mana, int hp>
class RulesPlayerCharacteristic{
public:
    void operator()(Field* field){
        if(hp < 0 or mana < 0) return;
        field->player->setHealth(hp);
        field->player->setMana(mana);
    };
};
#endif //OOP_RULESCHARACTERISTICPLAYER_H
