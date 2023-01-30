#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //Хранит информацию о состоянии палубы корабля
public:
	Odnopalybnik();
	sost getpalyba();
	void setpalyba(sost s);
};