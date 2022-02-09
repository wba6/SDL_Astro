//
// Created by TANK1_41 on 2/1/2022.
//

#pragma once
#include "player.h"
#include "enemy.h"
#include "projectiles.h"
class collision {
public:
    static void checkCollision(std::vector<astroidMovment> *movementSlope, player *pla);

    static void checkCollision(std::vector<astroidMovment> *movementSlope, std::vector<projectile *> *projectiles);
};


