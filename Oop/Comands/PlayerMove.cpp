//
// Created by Lendor on 15.11.2022.
//

#include "PlayerMove.h"

PlayerMove::PlayerMove(Field* map, Player* player):map(map),player(player){}

void PlayerMove::Move(Field *map, char q) {
    if(q == up)//        Up::Move(map);
    if(q == down)//        down::Move(map);
    if(q == left) //left::Move(map);
    if(q == right)// right::Move(map);
    ;

}

void PlayerMove::ReadTxt(){
    std::string line;
    in.open("move.txt");
    if (in.is_open())
    {
        for(int i = 0; i < 4; i++){
            std::getline(in, line);
            char q = line[0];
            if(i == 0) this->up = q;
            if(i == 1) this->down = q;
            if(i == 2) this->left = q;
            if(i==3) this->right = q;
        }
    }
    in.close();     // закрываем файл
}