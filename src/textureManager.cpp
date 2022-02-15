//
// Created by TANK1_41 on 1/25/2022.
//

#include "Astro/textureManager.h"
#include "Astro/game.h"

textureManger::textureManger(Game *game) : game(game) {}

SDL_Texture *textureManger::loadTexture(const char *fileName) {
    SDL_Surface *tempSurface = IMG_Load(fileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(game->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
