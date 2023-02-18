#pragma once
#include "Header.h"
#include "pole.h"

class Igrok
{
private:
	string imya;
	sostoyanie masproverky[N][N]; //Хранит сделанные выстрелы игрока
	varianti fdobit; //Флажок для функции выстрел
	int napr; //Направление выстрелов по подбитому кораблю
	int xnach, ynach, xpre, ypre, naprmimo[4], ch; //Переменные для алгоритма добития корабля
public:
	Igrok(string imya);
	void vystrel(int* x, int* y, pole* doska);
	string getimya();
	
};