#ifndef DISPLAY_H
#define DISPLAY_H

#include "SDL.h"

extern SDL_Renderer* renderer;

class Cell;
void show_cell(int x, int y, Type type, int zoom, Cell* c);

#endif