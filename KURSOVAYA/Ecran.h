#pragma once
#include "pole.h"




class Ecran
{
public:
	static const string symvoli[4]; //Символы соответсвующие состояниям клеток поля
	static const string bykvi[10]; //Символы соответсвующие координатам по Y
	void prorisovka(pole* doska);
};

