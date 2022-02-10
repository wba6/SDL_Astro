//
// Created by William Aey on 1/31/2022.
//

#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <valarray>
#include <vector>
class astroids {
public:
  astroids(int x, int y);

  virtual ~astroids();

  void update(const double &slope);

  void render();

  SDL_Rect *getDestRect();

private:
  SDL_Rect srcRect, destRect;
  SDL_Texture *astroidTex;
};

struct astroidMovment {
  astroids *instance;
  double slope;
};

class astroidManager {
public:
  astroidManager(SDL_Window *window);

  ~astroidManager();

  void createAstroid();

  void update();

  void render();

  std::vector<astroidMovment> *getMovementSlope();

private:
  int windowWidth;
  int windowHight;
  std::vector<astroidMovment> movementSlope;
};
