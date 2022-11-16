//
// Created by Lendor on 11.10.2022.
//
#include "../Event/Event.h"
#include "CellSign.h"

Event* ExitSign::execute() {
    return propertyFactory->makeItem(3);
}

Event * HealSign::execute() {
    return propertyFactory->makeItem(0);
}

Event * EnemySign::execute() {
    return enemyFactory->makeItem(0);
}

Event * EmptySign::execute() {
    return propertyFactory->makeItem(2);
}

Event * WallSign::execute() {
    return propertyFactory->makeItem(2);
}

Event * PlayerSign::execute() {
    return propertyFactory->makeItem(2);
}

Event * ManaSign::execute() {
    return propertyFactory->makeItem(1);
}

Event * TrapSign::execute() {
    return enemyFactory->makeItem(1);
}

//Event * TpSign::execute() {
//    return enemyFactory->makeItem(1);
//}
