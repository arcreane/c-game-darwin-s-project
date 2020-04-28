#pragma once

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

class LivingElement
{
public:
	Type getType();

	virtual void step() = 0;

private:
	Type m_eType;
	//CellColor color;
};

