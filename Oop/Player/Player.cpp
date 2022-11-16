//
// Created by Lendor on 19.09.2022.
//

#include "Player.h"
#include "iostream"


Player::Player(int health, int armor, int mana, int key):health(health),armor(armor),mana(mana), key(key){}


Player::PlayerMove Player::getAction() {
    return realAction;
}

int Player::getArmor() {
    return armor;
}

int Player::getHealth() {
    return health;
}

int Player::getMana() {
//    std::cout << mana;
    return mana;
}

int Player::getKey(){
    return key;
}

void Player::setKey(int key) {
    this->key = key;
}

void Player::setArmor(int armor) {
    this->armor = armor;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::setMana(int mana) {
    this -> mana = mana;
}
void Player::setAction(Player::PlayerMove action) {
    switch (action) {
        case Player::PlayerMove::none:
            realAction = none;
            break;
        case Player::PlayerMove::left:
            realAction = left;
            break;
        case Player::PlayerMove::right:
            realAction = right;
            break;
        case Player::PlayerMove::up:
            realAction = up;
            break;
        case Player::PlayerMove::down:
            realAction = down;
            break;
        case Player::PlayerMove::cast:
            realAction = cast;
            break;

    }

}
