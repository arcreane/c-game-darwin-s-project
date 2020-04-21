#include "cell.h"
#include "display.h"
#include "SDL.h"
#include <time.h>
#include <windows.h>
#include <iostream>
#include <fstream>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
void initialize_world(std::vector<std::vector<Cell>>& world, int world_width, int world_height, int nb_PLANTs, int nb_PREYs, int nb_predators, int zoom);

int main(int argc, char* argv[])
{


	// ------------------------- Paramètres de la simulation -------------------------



	int	world_width = 320;				// Largeur du monde (en cases)
	int	world_height = 180;				// Hateur du monde (en cases)
	int	zoom = 6;						// Taille des cases (en pixels)

	int	nb_PLANTs = 160;				// Nombre de PLANTes au début
	int	growth_rate = 15;				// Vitesse de l'évolution des PLANTes (en pourcents)

	int	nb_PREYs = 160;					// Nombre de proies au début
	int PREY_time_no_eat_max = 30;		// Temps que tient une proie sans manger
	int PREY_nb_eat_kid = 15;			// Nombre de PLANTes qu'une proie doit manger pour faire un enfant

	int	nb_predators = 20;				// Nombre de prédators au début
	int predator_time_no_eat_max = 60;	// Temps que tient un prédateur sans manger
	int predator_nb_eat_kid = 25;		// Nombre de proies qu'un prédateur doit manger pour faire un enfant

	int frame_rate_max = 144;			



	// -------------------------------------------------------------------------------



	if (world_width < 1) world_width = 1;
	if (world_height < 1) world_height = 1;
	if (zoom < 1) zoom = 1;
	if (nb_PLANTs < 0) nb_PLANTs = 0;
	if (growth_rate < 0) growth_rate = 0;
	if (growth_rate > 100) growth_rate = 100;
	if (nb_PREYs < 0) nb_PREYs = 0;
	if (PREY_time_no_eat_max < 1) PREY_time_no_eat_max = 1;
	if (PREY_nb_eat_kid < 1) PREY_nb_eat_kid = 1;
	if (nb_predators < 0) nb_predators = 0;
	if (predator_time_no_eat_max < 1) predator_time_no_eat_max = 1;
	if (predator_nb_eat_kid < 1) predator_nb_eat_kid = 1;
	if (frame_rate_max < 1) frame_rate_max = 1;

	std::ofstream file_;
	file_.open("data.txt");

	int window_width = world_width * zoom;
	int window_height = world_height * zoom;

	std::vector<std::vector<Cell>> world;
	int number_PLANTs = 0;
	int number_PREYs = 0;
	int number_predators = 0;

	SDL_Init(SDL_INIT_VIDEO);

	window = NULL;
	renderer = NULL;

	SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetWindowTitle(window, "Ecosystem simulation");
	SDL_Event event;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	initialize_world(world, world_width, world_height, nb_PLANTs, nb_PREYs, nb_predators, zoom);

	bool stop = true;

	while (1)
	{
		clock_t start = clock();

		number_PLANTs = 0;
		number_PREYs = 0;
		number_predators = 0;

		for (int i = 0; i < world.size(); i++) // Boucle pour compter chaques types d'êtres vivants
		{
			for (int j = 0; j < world[0].size(); j++)
			{
				if (world[i][j].type == PLANT)
					number_PLANTs++;

				if (world[i][j].type == PREY)
					number_PREYs++;

				if (world[i][j].type == PREDATOR)
					number_predators++;
			}
		}

		if (stop)
		{
			for (int i = 0; i < world.size(); i++) // Boucle pour compter chaques types d'êtres vivants
			{
				for (int j = 0; j < world[0].size(); j++)
				{
					if (world[i][j].type == PLANT)
						show_cell(i, j, PLANT, zoom, nullptr);

					if (world[i][j].type == PREY)
						show_cell(i, j, PREY, zoom, nullptr);

					if (world[i][j].type == PREDATOR)
						show_cell(i, j, PREDATOR, zoom, nullptr);
				}
			}

			SDL_RenderPresent(renderer);

			Sleep(1000);
			stop = false;
		}

		//if (file_.is_open())
		//	file_ << number_PLANTs << ", " << number_PREYs << ", " << number_predators << "\n"; // Remplie de fichier data.txt

		//for (int i = 0; i < world.size(); i++) // Boucle du pas de temps de la simulation
		//{
		//	for (int j = 0; j < world[0].size(); j++)
		//	{
		//		if (world[i][j].type == EMPTY)
		//			grow_PLANT(world, i, j, growth_rate, zoom);

		//		if (world[i][j].type == PREY and !world[i][j].done)
		//			update_PREY(world, i, j, zoom, PREY_time_no_eat_max, PREY_nb_eat_kid, number_PLANTs);

		//		if (world[i][j].type == PREDATOR and !world[i][j].done)
		//			update_predator(world, i, j, zoom, predator_time_no_eat_max, predator_nb_eat_kid, number_PREYs);
		//	}
		//}

		//update_world(world);

		SDL_RenderPresent(renderer);

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			file_.close();
			SDL_Quit();
			exit(1);
		}

		if (clock() - start < (1. / (double)frame_rate_max) * 1000.)
			Sleep(((1. / (double)frame_rate_max) * 1000.) - (clock() - start));
	}

	if (renderer)
		SDL_DestroyRenderer(renderer);

	if (window)
		SDL_DestroyWindow(window);

	file_.close();
	SDL_Quit();
	return 0;
}




// Initialise le monde

void initialize_world(std::vector<std::vector<Cell>>& world, int world_width, int world_height, int nb_PLANTs, int nb_PREYs, int nb_predators, int zoom)
{
	world.clear();
	std::vector<Cell> temp;

	int x = rand() % world_height;
	int y = rand() % world_width;

	for (int i = 0; i < world_width; i++)
		temp.push_back(Cell());

	for (int i = 0; i < world_height; i++)
		world.push_back(temp);

	for (int i = 0; i < nb_PLANTs; i++)
	{
		while (world[x][y].type != EMPTY)
		{
			x = rand() % world_height;
			y = rand() % world_width;
		}

		world[x][y] = Cell(PLANT);
		show_cell(x, y, PLANT, zoom, nullptr);
	}

	for (int i = 0; i < nb_PREYs; i++)
	{
		while (world[x][y].type != EMPTY)
		{
			x = rand() % world_height;
			y = rand() % world_width;
		}

		world[x][y] = Cell(PREY);
		show_cell(x, y, PREY, zoom, nullptr);
	}

	for (int i = 0; i < nb_predators; i++)
	{
		while (world[x][y].type != EMPTY)
		{
			x = rand() % world_height;
			y = rand() % world_width;
		}

		world[x][y] = Cell(PREDATOR);
		show_cell(x, y, PREDATOR, zoom, nullptr);
	}
}
