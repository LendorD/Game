//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RULESSIZEFIELD_H
#define OOP_RULESSIZEFIELD_H
#include "Field.h"
template<int x = 10, int y = 10>
class RulesFieldSize{
public:
    std::vector<std::vector<Cell>> map;
    void operator()(Field* field){
        if(!field->createField){
            std::cout<< "incorrect placement of rules" << '\n';
            return;
        }
        for(int row = 0; row < x; ++row){
            map.emplace_back();
            for(int col = 0; col < y; ++col){
                map.back().emplace_back(Cell(true));
            }
        }
        field->createField = false;
        field->SetField(map);
    }
};
#endif //OOP_RULESSIZEFIELD_H
