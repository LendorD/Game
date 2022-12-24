//
// Created by Lendor on 29.11.2022.
//

#ifndef OOP_RANDOM_H
#define OOP_RANDOM_H

#include <random>

namespace {
    auto random = std::mt19937 (std::random_device{}());

    int randInt(int from, int to) {
        return std::uniform_int_distribution<int>(from, to)(random);
    }
}
#endif //OOP_RANDOM_H
