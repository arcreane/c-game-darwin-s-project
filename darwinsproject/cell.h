#pragma once
#include <vector>

enum Type
{
	EMPTY,
	PLANT,
	PREY,
	PREDATOR
};

struct CellColor
{
	int red;
	int green;
	int blue;
};

class Cell
{
public:
	Type type;

private :
	bool done;
	int nb_eat;
	int time_no_eat;
	CellColor color;

public:
	Cell();
	Cell(const Cell& cell);
	Cell(Type type);


	void operator=(const Cell& cell);
	const CellColor getColor() const { return color; }
	void grow_PLANT(std::vector<std::vector<Cell>>& world, int x, int y, int growth_rate, int zoom);
	void update_world(std::vector<std::vector<Cell>>& world);
	int sign(int value);
	int is_walkable(Type type);
};
