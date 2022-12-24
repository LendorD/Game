//
// Created by Lendor on 22.11.2022.
//

#ifndef OOP_MOVEINTERFACE_H
#define OOP_MOVEINTERFACE_H
class Field;

class MoveInterface {
    virtual  void Move(Field* map) = 0;
};


#endif //OOP_MOVEINTERFACE_H
