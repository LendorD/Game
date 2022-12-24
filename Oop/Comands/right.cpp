//
// Created by Lendor on 15.11.2022.
//

#include "right.h"
#include "Field.h"
void right::Move(Field *map) {
    int x_exit = map->ExitPosX;
    int y_exit = map->ExitPosY;
    if(map->player->getMana() < 20)map->map[x_exit][y_exit].setAvailable(true);
    else map->map[x_exit][y_exit].setAvailable(false);
    if (map->PlayerY == map->getWigth()-1) {
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->PlayerY = -1;
    }
    int y = map->PlayerY;
    ++y;
    if(not map->map[map->PlayerX][y].getAvailablee()) {
        Event* event = map->map[map->PlayerX][y].getEvent();
        event ->init(map->player, map);
        event ->StateEvent();
        map->map[map->PlayerX][map->PlayerY].setPassable(true);
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->map[map->PlayerX][++map->PlayerY].setSign(new PlayerSign);
    }
}

right::right() {

}
