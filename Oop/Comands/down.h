//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_DOWN_H
#define OOP_DOWN_H
#include "MoveInterface.h"
class Field;

class down:MoveInterface {
public:
    down();
    void Move(Field *map) override;
};


#endif //OOP_DOWN_H
