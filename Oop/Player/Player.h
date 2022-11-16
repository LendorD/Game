//
// Created by Lendor on 19.09.2022.
//
#pragma once
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
public:
    Player(int health = 100, int armor = 50, int mana = 5, int key = 0);
    enum PlayerMove{
        left = 'a', right = 'd',
        up = 'w', down = 's',
        cast = 'z', none = 0
    };
    void setAction(Player::PlayerMove action);
    Player::PlayerMove getAction();

    int getHealth();
    int getArmor();
    int getMana();
    int getKey();

    void setKey(int key);
    void setHealth(int health);
    void setArmor(int armor);
    void setMana(int mana);
//    int PlayerX, PlayerY;
    int health = 100;
    int armor;
    int mana = 5;
    int key = 0;

private:


    PlayerMove realAction = none;
};


#endif //OOP_PLAYER_H
