//
// Created by Lendor on 11.10.2022.
//

#include "CellView.h"

CellView::CellView(Cell cell) {
    this->view = cell.getSign()->getView();
}

std::string CellView::getView() {
    return this->view;
}

