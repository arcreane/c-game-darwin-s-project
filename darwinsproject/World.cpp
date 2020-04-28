#include "World.h"
#include "LivingElement.h"
#include "WorldElement.h"

int World::s_iTotalPrey = 0;
int World::s_iTotalPlant = 0;
int World::s_iTotalPredator = 0;

void World::addElement(LivingElement* le)
{
	switch (le->getType())
	{
	case PREDATOR:
		s_iTotalPredator++;
		break;
	}

}


World::World(int p_iWidth, int p_iHeight)
	: m_iWidth(p_iWidth)
	,m_iHeight(p_iHeight)
{
	for (int i = 0; i < m_iWidth; i++)
	{
		m_ppelements[i] = new WorldElement*[m_iHeight];
		for (int j = 0; j < m_iHeight; j++)
		{
			m_ppelements[i][j] = new WorldElement();
		}
	}
}


void World::step()
{
	for (int i = 0; i < m_iWidth; i++)
	{
		m_ppelements[i] = new WorldElement * [m_iHeight];
		for (int j = 0; j < m_iHeight; j++)
		{
			if (m_ppelements[i][j] != nullptr)
				m_ppelements[i][j]->step();
		}
	}
}