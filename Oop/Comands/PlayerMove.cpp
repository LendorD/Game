//
// Created by Lendor on 15.11.2022.
//

#include "PlayerMove.h"

PlayerMove::PlayerMove(Field* map):map(map){}

void PlayerMove::Move(Field *map, char q) {
    switch (MovesTable[q])
    {
        case PlayerMove::action::Up:
            UpMove.Move(map);
            break;
        case PlayerMove::action::Down:
            DownMove.Move(map);
            break;
        case PlayerMove::action::Left:
            LeftMove.Move(map);
            break;
        case PlayerMove::action::Right:
            RightMove.Move(map);
            break;

    }

}

void PlayerMove::ReadTxt(){
    in.open("move.txt");
    char q;
    if (in.is_open())
    {
        for(int i = 0; i < 4; i++){
            std::getline(in, line);
            line = std::regex_replace(line, std::regex(" "), "");
            q = line[0];
            if(i == 0) MovesTable[q] = action::Up;
            if(i == 1) MovesTable[q] = action::Down;
            if(i == 2) MovesTable[q] = action::Left;
            if(i==3) MovesTable[q] = action::Right;
        }
    }
    in.close();
}