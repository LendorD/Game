//
// Created by Lendor on 15.11.2022.
//

#include "up.h"
#include "Field.h"
void up::Move(Field *map) {
//    map->UpAction();
    int x_exit = map->ExitPosX;
    int y_exit = map->ExitPosY;
    if(map->player->getMana() < 20)map->map[x_exit][y_exit].setAvailable(true);
    else map->getCell(x_exit, y_exit).setAvailable(false);
    bool f = true;
    if(map->PlayerX == 0){
        map->map[map->PlayerX][map->PlayerY].setPassable(true);
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->PlayerX = map->getLenght();
        map->map[--map->PlayerX][map->PlayerY].setSign(new PlayerSign);
        f = false;
    }
    int x = map->PlayerX;
    --x;
    if(not map->map[x][map->PlayerY].getAvailablee() and f) {
        Event *event = map->map[x][map->PlayerY].getEvent();
        event->init(map->player, map);
        event->StateEvent();
        map->map[map->PlayerX][map->PlayerY].setPassable(true);
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->map[--map->PlayerX][map->PlayerY].setSign(new PlayerSign);
    }
}

up::up() {

}
