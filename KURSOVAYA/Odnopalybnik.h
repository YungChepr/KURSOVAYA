#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //Хранит информацию о состоянии палубы корабля
	sost korabl; //Хранит информацию о состоянии корабля
public:
	Odnopalybnik();
	sost getpalyba();
	void setpalyba(sost p);
	sost getkorabl();
	void setkorabl(sost k);
};