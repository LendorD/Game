//
// Created by Lendor on 15.11.2022.
//

#include "down.h"
#include "Field.h"
void down::Move(Field *map) {
    int x_exit = map->ExitPosX;
    int y_exit = map->ExitPosY;
    if(map->player->getMana() < 20)map->map[x_exit][y_exit].setAvailable(true);
    else map->map[x_exit][y_exit].setAvailable(false);
    bool f = true;
    if(map->PlayerX == map->getLenght() - 1){
        map->map[map->PlayerX][map->PlayerY].setPassable(true);
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->PlayerX = -1;
        map->map[map->PlayerX][map->PlayerY].setSign(new PlayerSign);
        f = false;
    }
    int x = map->PlayerX;
    ++x;
    if(not map->map[x][map->PlayerY].getAvailablee() and f) {
        Event* event = map->map[x][map->PlayerY].getEvent();
        event ->init(map->player, map);
        event -> StateEvent();
        map->map[map->PlayerX][map->PlayerY].setPassable(true);
        map->map[map->PlayerX][map->PlayerY].setSign(new EmptySign);
        map->map[++map->PlayerX][map->PlayerY].setSign(new PlayerSign);
    }
}

down::down() {

}
