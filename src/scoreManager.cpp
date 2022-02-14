//
// Created by TANK1_41 on 2/14/2022.
//

#include "Astro/scoreManager.h"
#include "Astro/game.h"
#include "string.h"

scoreManager::scoreManager(Game *game) : surface(nullptr), texture(nullptr), game(game) {
    destRect.x = 15;
    destRect.w = 100;
    destRect.y = 15;
    destRect.h = 60;
    font = TTF_OpenFont("assets/arial.ttf", 25);
}

void scoreManager::upadateScore(const int score) {
    std::string scoreString = "Score: " + std::to_string(score);
    surface = TTF_RenderText_Solid(font, scoreString.c_str(), {0, 0, 0});
    texture = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
}

void scoreManager::render() {

    SDL_RenderCopy(game->renderer, texture, NULL, &destRect);
    SDL_DestroyTexture(texture);
}

scoreManager::~scoreManager() {
    TTF_CloseFont(font);
}
