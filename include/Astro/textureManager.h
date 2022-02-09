//
// Created by William Aey on 1/25/2022.
//

#pragma once
#define SDL_ASTRO_TEXTUREMANAGER_H
#include "game.h"
class textureManger {
public:
    static SDL_Texture *loadTexture(const char *fileName);
};
