#pragma once
class LivingElement;


class WorldElement
{
	public:
		bool done;
	private:
		int nb_eat;
		int time_no_eat;
		
		LivingElement* m_pLivingElement;

	public:
		WorldElement();
		WorldElement(const WorldElement& cell);
		//WorldElement(Type type);
		void display(int zoom);


		void operator=(const WorldElement& cell);
	//	const CellColor getColor() const { return color; }

};

