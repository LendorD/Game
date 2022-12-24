#pragma once
#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H
#include "Field.h"
//#include "../Cell/CellView.h"
//#include "../Player/Player.h"

class FieldView{
public:
    explicit FieldView(Field *other);
    FieldView() = default;
    void start(Field *field);
    bool GameOver(Field field);

    Field field;
    Player* player;
    int ExitX, ExitY;
private:
    Field *obj;
};
#endif //OOP_FIELDVIEW_H