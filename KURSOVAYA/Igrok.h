#pragma once
#include "Header.h"

class Igrok
{
private:
	string imya;
	sostoyanie masproverky[N][N]; //Хранит сделанные выстрелы игрока
public:
	Igrok(string imya);
	void vystrel(int* x, int* y, pole* doska);
	string getimya();
	
};