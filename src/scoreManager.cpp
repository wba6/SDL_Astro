//
// Created by TANK1_41 on 2/14/2022.
//

#include "Astro/scoreManager.h"
#include "Astro/game.h"

scoreManager::scoreManager(class Game *game) : surface(nullptr), texture(nullptr), Game(game) {
    font = TTF_OpenFont("assets/arial.ttf", 25);
}

void scoreManager::upadateScore() {
    SDL_Surface *surface = TTF_RenderText_Solid(font,
                                                "Hello", {0, 0, 0});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game->renderer, surface);
    SDL_FreeSurface(surface);
}

void scoreManager::render() {
    SDL_RenderCopy(Game->renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
}

scoreManager::~scoreManager() {
    TTF_CloseFont(font);
}
