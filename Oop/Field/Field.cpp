//
// Created by Lendor on 19.09.2022.
//
#include <iostream>
#include "Field.h"
#include <random>

namespace {
    auto randomizer = std::mt19937 (std::random_device{}());

    int rand_int(int from, int to) {
        return std::uniform_int_distribution<int>(from, to)(randomizer);
    }
}

void Field::RandomSign() {
    int randPosX = rand_int(0, lenght - 1);
    int randPosY = rand_int(0, width - 1);
    int pos_ = rand_int(0, static_cast<int>(ListSign.size())-1);
    int x = PlayerX;
    int y = PlayerY;
    if (randPosY == y && randPosX == x){ return;}
    CellSign* sign = ListSign.at(pos_);
    if(sign == ListSign.at(0)) map[randPosX][randPosY].setAvailable(true);
    else map[randPosX][randPosY].setAvailable(false);
    map[randPosX][randPosY].setSign(sign);
    if (pos_){
        map[randPosX][randPosY].setPassable(true);
    } else {
        map[randPosX][randPosY].setPassable(false);
    }
}

bool Field::StatusField() {
    if(player->getKey() == 1) return true;
    return false;
}

Field::Field(int lenght, int width):lenght(lenght = 10),width(width = 10),player(new Player){
    ListSign = {new WallSign, new EnemySign, new HealSign, new ManaSign, new TrapSign};
    for(int row = 0; row < lenght; ++row){
        map.push_back(std::vector<Cell>());
        for(int col = 0; col < width; ++col){
            map.back().emplace_back(Cell(true));
        }
    }
    int x = PlayerX = rand_int(0, lenght - 1);
    int y = PlayerY = rand_int(0, width - 1);
    for(int i = 0; i < (lenght*width)/2; i++){
        RandomSign();
    }
    ExitPosX = rand_int(0, lenght - 1);
    ExitPosY = rand_int(0, width - 1);
    CellSign* signExit = new ExitSign;
    map[ExitPosX][ExitPosY].setSign(signExit);
    map[ExitPosX][ExitPosY].setAvailable(false);
    map[x][y].setAvailable(false);// доступна ли клетка
    map[x][y].setPassable(true);//проходили ли мы её
    map[x][y].setSign(new PlayerSign);
    createField = true;
}
void Field::swap(Field &obj){
    std::swap(lenght, obj.lenght);
    std::swap(width, obj.width);
    std::swap(map, obj.map);
    std::swap(PlayerX, obj.PlayerX),
    std::swap(player,obj.player),
    std::swap(PlayerY, obj.PlayerY),
    std::swap(ExitPosX, obj.ExitPosX),
    std::swap(ExitPosY, obj.ExitPosY);
}
Field::Field(const Field& obj):
        lenght(obj.lenght),
        width(obj.width),
        PlayerX(obj.PlayerX),
        PlayerY(obj.PlayerY),
        player(obj.player),
        ExitPosX(obj.ExitPosX),
        ExitPosY(obj.ExitPosY),
        map(obj.map){};

Field::Field(Field&& obj) noexcept{
    this->swap(obj);
};


int Field::getWigth(){
    return width;
}

int Field::getLenght() {
    return lenght;
}


Cell Field::getCell(int l, int w){
    return map[l][w];
}
void Field::ChangesFrame(char stateAction) {
    switch (static_cast<Player::PlayerMove>(stateAction))
    {
        case Player::PlayerMove::none:
            NoneAction();
            break;
        case Player::PlayerMove::left:
            LeftAction();
            break;
        case Player::PlayerMove::right:
            rightAction();
            break;
        case Player::PlayerMove::up:
            UpAction();
            break;
        case Player::PlayerMove::down:
            DownAction();
            break;
    }
}

void Field::NoneAction(){
}

void Field::SetField(std::vector<std::vector<Cell>> map){
    this->map = map;
    this->lenght = (int) map.size();
    this->width = (int) map.at(0).size();
}



void Field::LeftAction(){
    if(player->getMana() < 20)map[ExitPosX][ExitPosY].setAvailable(true);
    else map[ExitPosX][ExitPosY].setAvailable(false);
    if (PlayerY == 0){
        map[PlayerX][PlayerY].setSign(new EmptySign);
        PlayerY = width;
    }
    int y = PlayerY;
    --y;
    if(!map[PlayerX][y].getAvailablee()) {
        Event* event = map[PlayerX][y].getEvent();
        event ->init(player, this);
        event ->StateEvent();
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        map[PlayerX][--PlayerY].setSign(new PlayerSign);

    }
}
void Field::rightAction(){
    if(player->getMana() < 20)map[ExitPosX][ExitPosY].setAvailable(true);
    else map[ExitPosX][ExitPosY].setAvailable(false);
    if (PlayerY == width-1) {
        map[PlayerX][PlayerY].setSign(new EmptySign);
        PlayerY = -1;
    }
    int y = PlayerY;
    ++y;
    if(!map[PlayerX][y].getAvailablee()) {
        Event* event = map[PlayerX][y].getEvent();
        event ->init(player, this );
        event ->StateEvent();
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        map[PlayerX][++PlayerY].setSign(new PlayerSign);
    }
}
void Field::UpAction(){
    if(player->getMana() < 20)map[ExitPosX][ExitPosY].setAvailable(true);
    else map[ExitPosX][ExitPosY].setAvailable(false);
    bool f = true;
    if(PlayerX == 0){
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        PlayerX = lenght;
        map[--PlayerX][PlayerY].setSign(new PlayerSign);
        f = false;
    }
    int x = PlayerX;
    --x;
    if(!map[x][PlayerY].getAvailablee() and f) {
        Event *event = map[x][PlayerY].getEvent();
        event->init(player, this);
        event->StateEvent();
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        map[--PlayerX][PlayerY].setSign(new PlayerSign);
        }
    }


void Field::DownAction(){
    if(player->getMana() < 20)map[ExitPosX][ExitPosY].setAvailable(true);
    else map[ExitPosX][ExitPosY].setAvailable(false);
    bool f = true;
    if(PlayerX == lenght - 1){
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        PlayerX = -1;
        map[++PlayerX][PlayerY].setSign(new PlayerSign);
        f = false;
    }
    int x = PlayerX;
    ++x;
    if(!map[x][PlayerY].getAvailablee() and f) {
        Event* event = map[x][PlayerY].getEvent();
        event ->init(player, this);
        event -> StateEvent();
        map[PlayerX][PlayerY].setPassable(true);
        map[PlayerX][PlayerY].setSign(new EmptySign);
        map[++PlayerX][PlayerY].setSign(new PlayerSign);
    }
}


