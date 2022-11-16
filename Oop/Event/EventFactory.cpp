//
// Created by Lendor on 11.10.2022.
//

#include "EventFactory.h"

Event *EnemyFactory::makeItem(int choice) {
    return EnemyEvents[choice]->clone();
}

Event *PrettyFactory::makeItem(int choice) {
    return PrettyEvents[choice]->clone();
}
