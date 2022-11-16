#include "EventPretty.h"
void HealHP::StateEvent() {
    int health = player->getHealth();
    player->setHealth(health + 10);
}

void HealMana::StateEvent() {
    int mana = player->getMana();
    player->setMana(mana + 5);
}

void Nothing::StateEvent() {}

void Exit::StateEvent() {
    int mana = player->getMana();
    if (mana >= 20){
        player->setKey(1);
    }
}