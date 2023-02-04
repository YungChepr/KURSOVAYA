#pragma once
#include "Odnopalybnik.h"
#include "pole.h"

class Igra
{
public: 
	void rasstanovka(Odnopalybnik* korabli[M], pole* doska);
	void hod(Odnopalybnik* korabli[M], pole* doska, int x, int y);
	int konecigry(Odnopalybnik* korabli[M]);
};