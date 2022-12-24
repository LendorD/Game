//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_GENERATOR_H
#define OOP_GENERATOR_H
#include "../Field/Field.h"
template <class ... Rules>
class Generator {
public:
    Field* generator(){
        Field* map = new Field;

        (Rules()(map), ...);
        return map;
    }
};


#endif //OOP_GENERATOR_H
