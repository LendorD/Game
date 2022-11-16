//
// Created by Lendor on 11.10.2022.
//
#pragma once

#ifndef OOP_CELLSIGN_H
#define OOP_CELLSIGN_H
#include <iostream>
#include "../Event/EventFactory.h"

class CellSign {
public:
    explicit CellSign(std::string _view) : view(std::move(_view)) {}
    inline std::string getView() { return view; }
    virtual Event * execute() = 0;
protected:
    std::string view;
    AbstractFactory* const enemyFactory = new EnemyFactory;
    AbstractFactory* const propertyFactory = new PrettyFactory;
};

class ExitSign: public CellSign{
public:
    Event* execute() override;
    ExitSign(): CellSign("X"){}
};

class HealSign : public CellSign {
public:
    Event * execute() override;
    HealSign() : CellSign("\3") {}
};

class EnemySign : public CellSign {
public:
    Event * execute() override;
    EnemySign() : CellSign("*") {}
};

class EmptySign : public CellSign {
public:
    Event * execute() override;
    EmptySign() : CellSign("." ) {}
};

class WallSign : public CellSign {
public:
    Event * execute() override;
    WallSign() : CellSign("|") {}
};

class PlayerSign : public CellSign {
public:
    Event * execute() override;
    PlayerSign() : CellSign("\2") {}
};

class ManaSign : public CellSign {
public:
    Event * execute() override;
    ManaSign() : CellSign("$") {}
};

class TrapSign : public CellSign {
public:
    Event * execute() override;
    TrapSign() : CellSign(".") {}
};
//
//class TpFeature : public CellSign {
//public:
//    Event * execute() override;
//    TpSign() : CellSign("+") {}
//};

#endif //OOP_CELLSIGN_H
