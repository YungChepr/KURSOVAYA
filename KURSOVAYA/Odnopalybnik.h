#pragma once
#include "kletka.h"
#include "pole.h"


class Odnopalybnik: public kletka
{
private:
	sost palyba;//Хранит информацию о состоянии палубы корабля
	//sost korabl; //Хранит информацию о состоянии корабля
public:
	Odnopalybnik();
	virtual void ustanovkakorablya(pole* doska); //Установка на поле однопалубника
	virtual sost getpalyba(); //getpalyba не нужен многопалубнику
	virtual void setpalyba(sost p);//setpalyiba не нужен многопалубнику
	virtual sost proverkakorablya(int x, int y); //Спрашивает корабль попали ли в него
	virtual sost getkorabl();
	virtual void setkorabl(sost k);
};