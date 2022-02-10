//
// Created by William Aey on 2/1/2022.
//

#include <Astro/Check_collision.h>

void collision::checkCollision(std::vector<astroidMovment> *movementSlope,
                               player *pla) {

  for (size_t i{0}; i < movementSlope->size(); i++) {

    SDL_bool collision = SDL_HasIntersection(
        movementSlope->at(i).instance->getDestRect(), pla->getDestRect());
    if (collision == true) {
      movementSlope->erase(movementSlope->begin() + i);
      i--;
    }
  }
}

void collision::checkCollision(std::vector<astroidMovment> *movementSlope,
                               std::vector<projectile *> *projectiles) {
  for (size_t i{0}; i < movementSlope->size(); i++) {
    for (size_t j{0}; j < projectiles->size(); i++) {
      SDL_bool collision =
          SDL_HasIntersection(movementSlope->at(i).instance->getDestRect(),
                              projectiles->at(j)->getDestRect());
      if (collision == true) {
        movementSlope->erase(movementSlope->begin() + i);
        projectiles->erase(projectiles->begin() + j);
        i--;
      }
    }
  }
}
