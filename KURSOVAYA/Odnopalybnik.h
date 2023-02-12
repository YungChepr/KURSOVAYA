#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //Хранит информацию о состоянии палубы корабля
	sost korabl; //Хранит информацию о состоянии корабля
public:
	Odnopalybnik();
	virtual sost getpalyba();
	virtual void setpalyba(sost p);
	virtual sost getkorabl();
	virtual void setkorabl(sost k);
};