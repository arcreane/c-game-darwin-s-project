#include "WorldElement.h"
#include "Predator.h"
#include "Plant.h"
#include "Prey.h"
#include "LivingElement.h"
#include "display.h"
#include <vector>
#include "World.h"

// Crée une case

WorldElement::WorldElement()
{
	done = false;
	nb_eat = 0;
	time_no_eat = 0;
	//Randomisation de la création du m_pLinvnElement
	int random = 0;//A générer en mode random entre 0 et 3:
	switch (random)
	{
	case EMPTY:
		m_pLivingElement = nullptr;
		break;
	case PREY:
		m_pLivingElement = new Prey();
		break;
	case PREDATOR:
		m_pLivingElement = new Predator();
		break;
	case PLANT:
		m_pLivingElement = new Plant();
		break;
	}
	if(m_pLivingElement != nullptr)
		World::addElement(m_pLivingElement);
}



// Crée une case à partir d'une autre case

WorldElement::WorldElement(const WorldElement& we)
{
	*this = we;
}



// Crée une case à partir d'un type donné

WorldElement::WorldElement(Type type)
{
	this->type = type;
	done = false;
	nb_eat = 0;
	time_no_eat = 0;
	color = CellColor{ 0, 0, 0 };
	switch (type)
	{
	case PREDATOR:
		color.red = 255;
		break;
	case PREY:
		color.blue = 255;
		break;
	case PLANT:
		color.green = 255;
		break;
	}
}



// Assignation

void WorldElement::operator=(const WorldElement & we)
{
	//type = cell.type;
	done = we.done;
	nb_eat = we.nb_eat;
	time_no_eat = we.time_no_eat;
	//color = cell.color;

}


// Affiche un rectangle aux coordonnées voulues

void WorldElement::display(int zoom)
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

//
//// Donne un ordre aléatoire de 4 valeurs
//
//std::vector<int> random_order_4()
//{
//	std::vector<int> vect;
//	int random = rand() % 24;
//
//	switch (random)
//	{
//	case 0:  vect = { 0, 1, 2, 3 }; break;
//	case 1:  vect = { 0, 1, 3, 2 }; break;
//	case 2:  vect = { 0, 2, 1, 3 }; break;
//	case 3:  vect = { 0, 2, 3, 1 }; break;
//	case 4:  vect = { 0, 3, 1, 2 }; break;
//	case 5:  vect = { 0, 3, 2, 1 }; break;
//	case 6:  vect = { 1, 0, 2, 3 }; break;
//	case 7:  vect = { 1, 0, 3, 2 }; break;
//	case 8:  vect = { 1, 2, 0, 3 }; break;
//	case 9:  vect = { 1, 2, 3, 0 }; break;
//	case 10: vect = { 1, 3, 0, 2 }; break;
//	case 11: vect = { 1, 3, 2, 0 }; break;
//	case 12: vect = { 2, 0, 1, 3 }; break;
//	case 13: vect = { 2, 0, 3, 1 }; break;
//	case 14: vect = { 2, 1, 0, 3 }; break;
//	case 15: vect = { 2, 1, 3, 0 }; break;
//	case 16: vect = { 2, 3, 0, 1 }; break;
//	case 17: vect = { 2, 3, 1, 0 }; break;
//	case 18: vect = { 3, 0, 1, 3 }; break;
//	case 19: vect = { 3, 0, 2, 1 }; break;
//	case 20: vect = { 3, 1, 0, 2 }; break;
//	case 21: vect = { 3, 1, 2, 0 }; break;
//	case 22: vect = { 3, 2, 0, 1 }; break;
//	case 23: vect = { 3, 2, 1, 0 }; break;
//	}
//
//	return vect;
//}