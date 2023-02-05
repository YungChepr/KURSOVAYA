#pragma once
#include "Odnopalybnik.h"
#include "pole.h"

class Igra
{
private:
	string imyapobeditelya;
public: 
	void rasstanovka(Odnopalybnik* korabli[M], pole* doska);
	void hod(Odnopalybnik* korabli[M], pole* doska, int x, int y);
	int konecigry(Odnopalybnik* korabli[M]);
	string getimyapobeditelya();
	void setimyapobeditelya(string imyapobeditelya);
};