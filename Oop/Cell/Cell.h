#pragma once
#ifndef OOP_CELL_H
#define OOP_CELL_H

#include "CellSign.h"
//#include "../Event/Event.h"
#include <algorithm>

class Cell {

public:
    void setAvailable(bool available);
    void setPassable(bool pas);
    bool getAvailablee();
    bool getPassable();

    void setEvent(Event* ev);
    Event* getEvent();

    void setSign(CellSign* sign);
    CellSign* getSign();

    explicit Cell(bool passable = true);
    Cell(const Cell& other) = default;
    ~Cell() = default;
    Cell(Cell&& other) noexcept ;
    Cell& operator=(Cell&& other) noexcept ;
    Cell& operator=(const Cell& other);
    void swap(Cell &other);
private:
    CellSign* obj{};
    bool available{}; // доступна ли клетка
    bool passable{};//проходили ли мы её
    Event *event;

};


#endif //OOP_CELL_H
