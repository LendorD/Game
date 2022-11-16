//
// Created by Lendor on 11.10.2022.
//
#pragma once
#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H
#include "Cell.h"

class CellView {
public:
    CellView(Cell c);
    std::string getView();
private:
    std::string view;
};

#endif //OOP_CELLVIEW_H
