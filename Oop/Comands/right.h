//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_RIGHT_H
#define OOP_RIGHT_H
#include "MoveInterface.h"
class Field;

class right:MoveInterface {
public:
    right();
    void Move(Field *map) override;
};


#endif //OOP_RIGHT_H
