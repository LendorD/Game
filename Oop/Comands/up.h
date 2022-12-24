//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_UP_H
#define OOP_UP_H
#include "MoveInterface.h"
class Field;

class up: MoveInterface {
public:
    up();
    void Move(Field *map) override;
};


#endif //OOP_UP_H
