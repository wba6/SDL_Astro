//
// Created by William Aey on 1/25/2022.
//

#pragma once
#define SDL_ASTRO_PLAYER_H

#include <map>
#include "SDL_image.h"
#include "SDL.h"
#include "textureManager.h"
class player{
public:
    player(SDL_Renderer* ren, int x,int y);
    ~player();
    void update();
    void render();
private:
    int xpos;
    int ypos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    SDL_Texture* playertex;

};
