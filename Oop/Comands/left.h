//
// Created by Lendor on 15.11.2022.
//

#ifndef OOP_LEFT_H
#define OOP_LEFT_H
#include "MoveInterface.h"
class Field;

class left:MoveInterface {
public:
    left();
    void Move(Field *map) override;
};


#endif //OOP_LEFT_H
