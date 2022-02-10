//
// Created by William Aey on 1/25/2022.
//

#pragma once

#include "Check_collision.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "enemy.h"
#include "player.h"
#include "projectiles.h"
#include "textureManager.h"
#include <iostream>
#include <vector>

class Game {
public:
  Game();

  virtual ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);

  void handleEvents();

    void update();

    void render();

    void clean();

    bool running();

    void addProjectile(projectile *p);

    void loseCondition(bool winLoss);

    void restart();

    SDL_Window *getWindow() const;

    SDL_Renderer *renderer;
    SDL_Event event;
    textureManger textures;

private:
    astroidManager *astMan;
    player *playerOne;
    bool lost;
    bool isRunning;
    SDL_Window *window;

    projectileManager Manageprojectiles;
};
