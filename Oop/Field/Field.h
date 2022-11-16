//
// Created by Lendor on 19.09.2022.
//
#pragma once
#ifndef OOP_FIELD_H
#define OOP_FIELD_H


#include <vector>
#include "../Cell/CellView.h"
#include "../Player/Player.h"

class Field {
private:
    typedef std::vector<std::vector<Cell>> field; //задаем псевдоним для типа данных
    field map;
    //Field CopyMap;
    int lenght, width;
    std::vector<CellSign*> ListSign;
public:
    explicit Field(int lenght = 10, int weight = 10);
    Field(const Field& obj);
    Field(Field&& obj) noexcept ;
    void swap(Field &obj);

    void ChangesAction();
    void ChangesFrame(char stateAction);
    void RandomSign();
    void NoneAction();
    void LeftAction();
    void rightAction();
    void UpAction();
    void DownAction();
    void TpAction();

    bool StatusField();

    Cell getCell(int h, int w);
    int getWigth();
    int getLenght();
    Player* player;
    int PlayerX;
    int PlayerY;
    int ExitPosX, ExitPosY;
};


#endif //OOP_FIELD_H
