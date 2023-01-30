#pragma once
#include "koordinata.h"
class kletka : public koordinata
{
private:
	 sostoyanie klet; //Хранит состояние клетки
public:
	kletka();
	void setklet(sostoyanie k);
	sostoyanie getklet();

};

