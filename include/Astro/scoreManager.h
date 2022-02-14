//
// Created by TANK1_41 on 2/14/2022.
//

#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

class Game;

class scoreManager {
public:
    scoreManager(Game *game);

    ~scoreManager();

    void upadateScore();

    void render();

private:
    Game *Game;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Texture *texture;
};

