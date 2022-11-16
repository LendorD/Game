#pragma once
#ifndef OOP_EVENTPRETTY_H
#define OOP_EVENTPRETTY_H
#include "../Event/Event.h"
class EventPretty : public Event{
public:

};
class HealHP : public EventPretty {
public:
    Event* clone() override { return new HealHP; }
    void StateEvent() override;
};

class HealMana: public EventPretty{
public:
    Event* clone() override{ return new HealMana; }
    void StateEvent() override;
};

class Nothing: public EventPretty{
public:
    Event* clone() override{ return new Nothing; }
    void StateEvent() override;
};

class Exit: public EventPretty{
public:
    Event* clone() override{return new Exit;}
    void StateEvent() override;
};

#endif