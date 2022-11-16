//
// Created by Lendor on 19.09.2022.
//

#include "Cell.h"
Cell::Cell(bool passable):
        passable(passable){
    this -> obj = new EmptySign;
    this -> event = obj -> execute();
}


Cell::Cell(Cell &&other)  noexcept {
    this->swap(other);
}


Cell &Cell::operator=(Cell &&other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell &Cell::operator=(const Cell &other) {
    if (this != &other)
        Cell(other).swap(*this);
    return *this;
}

void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
    std::swap(event, other.event);

    bool temp = this->passable;
    this->passable = other.passable;
    other.passable = temp;
}

void Cell::setSign(CellSign* sign){
    this -> obj = sign;
    this -> event = obj -> execute();
}


CellSign* Cell::getSign(){
    return this->obj;
}

void Cell::setPassable(bool pas) {//проходили ли мы её
    this -> passable = pas;
}

void Cell::setEvent(Event *ev) {
    this->event = ev;
}

void Cell::setAvailable(bool available = true) {// доступна ли клетка
    this->available = available;
}

bool Cell::getPassable() {//проходили ли мы её
    return passable;
}

bool Cell::getAvailablee() {
    return available;
}

Event* Cell::getEvent() {
    return this -> event;
}

