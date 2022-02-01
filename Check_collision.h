//
// Created by TANK1_41 on 2/1/2022.
//

#pragma once

#include "player.h"
#include "enemy.h"

class collision {
public:
    static void checkCollision(std::vector<astroidMovment> &movementSlope, const player &pla);

private:
    static int leftA, leftB;
    static int rightA, rightB;
    static int topA, topB;
    static int bottomA, bottomB;

};


