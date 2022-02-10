//
// Created by William Aey on 1/25/2022.
//

#pragma once

#include <SDL2/SDL_render.h>
class Game;

class textureManger {
  Game *game;

public:
  explicit textureManger(Game *game);
  SDL_Texture *loadTexture(const char *fileName);
};
