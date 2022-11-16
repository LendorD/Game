#pragma once
#ifndef OOP_EVENTEVIL_H
#define OOP_EVENTEVIL_H
#include "../Event/Event.h"

class EventEvil:public Event{
public:
};

class Trap:public EventEvil{
public:
    Event* clone() override { return new Trap;}
    void StateEvent() override;
};

class Enemy:public EventEvil{
public:
    Event* clone() override { return new Enemy;}
    void StateEvent() override;
};

#endif