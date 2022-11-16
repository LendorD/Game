#include "EventEvil.h"
#include "Field.h"
void Trap::StateEvent() {
    int health = player->getHealth();
    int mana = player->getMana();
    player->setMana(mana - 5);
    player->setHealth(health - 10);
}

void Enemy::StateEvent() {
    int health = player->getHealth();
    player->setHealth(health - 10);
    filed->RandomSign();
}