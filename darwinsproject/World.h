#pragma once
class WorldElement;

class World
{
private :
	static int s_iTotalPrey;
	static int s_iTotalPlant;
	static int s_iTotalPredator;

public:
	World(int p_iWidth, int p_iHeight);
	void step();


	static void addElement(LivingElement * le);

private:
	WorldElement*** m_ppelements;

	int m_iWidth;
	int m_iHeight;


};

