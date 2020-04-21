#include "cell.h"
#include "display.h"
#include "SDL.h"



// Affiche un rectangle aux coordonnées voulues

void show_cell(int x, int y, const Type type, int zoom, Cell* c)
{
	if (c == nullptr)
		c = new Cell();
	if (type == PLANT)
		SDL_SetRenderDrawColor(renderer, c->getColor().red, c->getColor().green, c->getColor().blue, SDL_ALPHA_OPAQUE);

	else if (type == PREY)
		SDL_SetRenderDrawColor(renderer, c->getColor().red, c->getColor().green, c->getColor().blue, SDL_ALPHA_OPAQUE);

	else if (type == PREDATOR)
		SDL_SetRenderDrawColor(renderer, c->getColor().red, c->getColor().green, c->getColor().blue, SDL_ALPHA_OPAQUE);

	else
		SDL_SetRenderDrawColor(renderer, c->getColor().red, c->getColor().green, c->getColor().blue, SDL_ALPHA_OPAQUE);

	SDL_Rect rectangle[1];

	rectangle[0].h = zoom;
	rectangle[0].w = zoom;
	rectangle[0].x = y * zoom;
	rectangle[0].y = x * zoom;

	SDL_RenderFillRect(renderer, rectangle);
}