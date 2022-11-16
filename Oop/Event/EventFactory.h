#pragma once
#ifndef OOP_EVENTFACTORY_H
#define OOP_EVENTFACTORY_H
//#include "Event.h"
#include "EventEvil.h"
#include "EventPretty.h"

class AbstractFactory {
public:
    virtual Event* makeItem(int choice) = 0;
};


class EnemyFactory: public AbstractFactory {
public:
    Event* makeItem(int choice) override;
private:
    Event* EnemyEvents[2] = {new Enemy, new Trap} ;
};


class PrettyFactory: public AbstractFactory {
public:
    Event* makeItem(int choice) override;

private:
    Event* PrettyEvents[4] = {new HealHP, new HealMana, new Nothing, new Exit} ;
};

#endif //OOP_EVENTFACTORY_H
