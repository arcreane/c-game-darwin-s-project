#pragma once
#include <vector>

enum Type
{
	EMPTY,
	PLANT,
	PREY,
	PREDATOR
};



class Cell
{
public:
	Type type;

	bool done;
private :
	int nb_eat;
	int time_no_eat;
	CellColor color;

public:
	Cell();
	Cell(const Cell& cell);
	Cell(Type type);


	void operator=(const Cell& cell);
	const CellColor getColor() const { return color; }
	
};
