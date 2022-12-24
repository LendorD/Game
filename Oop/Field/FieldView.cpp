#include "FieldView.h"
#include <iostream>


FieldView::FieldView(Field *other) {
    this->obj = other;
}

void FieldView::start(Field *map) {
    player = map->player;
    ExitX = map->ExitPosX;
    ExitY = map->ExitPosY;
    int length = map->getLenght();
    int wight = map->getWigth();
    for(int row = 0; row < length; ++row) {
        for (int col = 0; col < wight; ++col) {
            Cell cell = map->getCell(row,col);
            CellView cellView(cell);
            std::cout << "  " << cellView.getView();
        }
        std::cout << '\n';
    }
}

bool FieldView::GameOver(Field map){
    player = map.player;
    if(player->getHealth() < 0){
        std::cout<< '\n' <<"GAME OVER" ;
        return false;
    }
    if(player->getKey() == 1){
        std::cout<< '\n' <<"GAME OVER" ;
        return false;
    }else return true;
}
