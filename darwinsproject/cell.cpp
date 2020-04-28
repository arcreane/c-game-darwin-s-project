#include "cell.h"
#include "display.h"
#include <vector>


// Crée une case

Cell::Cell()
{
	type = EMPTY;
	done = false;
	nb_eat = 0;
	time_no_eat = 0;
}



// Crée une case à partir d'une autre case

Cell::Cell(const Cell& cell)
{
	*this = cell;
}



// Crée une case à partir d'un type donné

Cell::Cell(Type type)
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

void Cell::operator=(const Cell& cell)
{
	type = cell.type;
	done = cell.done;
	nb_eat = cell.nb_eat;
	time_no_eat = cell.time_no_eat;
	color = cell.color;
	
}




// Donne un ordre aléatoire de 4 valeurs

std::vector<int> random_order_4()
{
	std::vector<int> vect;
	int random = rand() % 24;

	switch (random)
	{
	case 0:  vect = { 0, 1, 2, 3 }; break;
	case 1:  vect = { 0, 1, 3, 2 }; break;
	case 2:  vect = { 0, 2, 1, 3 }; break;
	case 3:  vect = { 0, 2, 3, 1 }; break;
	case 4:  vect = { 0, 3, 1, 2 }; break;
	case 5:  vect = { 0, 3, 2, 1 }; break;
	case 6:  vect = { 1, 0, 2, 3 }; break;
	case 7:  vect = { 1, 0, 3, 2 }; break;
	case 8:  vect = { 1, 2, 0, 3 }; break;
	case 9:  vect = { 1, 2, 3, 0 }; break;
	case 10: vect = { 1, 3, 0, 2 }; break;
	case 11: vect = { 1, 3, 2, 0 }; break;
	case 12: vect = { 2, 0, 1, 3 }; break;
	case 13: vect = { 2, 0, 3, 1 }; break;
	case 14: vect = { 2, 1, 0, 3 }; break;
	case 15: vect = { 2, 1, 3, 0 }; break;
	case 16: vect = { 2, 3, 0, 1 }; break;
	case 17: vect = { 2, 3, 1, 0 }; break;
	case 18: vect = { 3, 0, 1, 3 }; break;
	case 19: vect = { 3, 0, 2, 1 }; break;
	case 20: vect = { 3, 1, 0, 2 }; break;
	case 21: vect = { 3, 1, 2, 0 }; break;
	case 22: vect = { 3, 2, 0, 1 }; break;
	case 23: vect = { 3, 2, 1, 0 }; break;
	}

	return vect;
}